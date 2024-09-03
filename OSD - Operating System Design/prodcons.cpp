#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N_THREADS 6  // Number of threads
#define COUNT 15     // Count the producer and consumer shall count

pthread_mutex_t m;
sem_t prod_sem, cons_sem; // Semaphores for producer and consumer
int buffer = 0;           // Shared buffer
int production_done = 0;  // Flag to indicate production is done

void* producer(void* arg) {
    pthread_t thread_id = pthread_self(); // Get producer thread ID
    while (1) { // Infinite loop
        sem_wait(&prod_sem); // Wait for permission to produce

        for (int i = 0; i < COUNT; i++) {
            pthread_mutex_lock(&m);

            buffer = rand() % 101; // Produce a random item
            printf("*** Producer thread ID: %lu, item produced = %d\n", thread_id, buffer);

            pthread_mutex_unlock(&m);
            sleep(1); // Simulate production time
        }

        production_done = 1; // Indicate production is done
        for (int i = 1; i < N_THREADS; i++) {
            sem_post(&cons_sem); // Signal all consumers
        }
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    pthread_t thread_id = pthread_self(); // Get consumer thread ID
    int id = *((int*) arg);
    while (1) { // Infinite loop
        sem_wait(&cons_sem); // Wait for signal from producer

        while (!production_done) { // Wait until production is done
            sleep(1);
        }

        pthread_mutex_lock(&m);
        printf("=== Consumer thread ID: %lu (%d), item consumed = %d\n", thread_id, id, buffer);
        pthread_mutex_unlock(&m);

        if (id == N_THREADS - 1) { // Last consumer signals producer
            production_done = 0; // Reset production flag
            sem_post(&prod_sem);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N_THREADS];
    srand(time(NULL)); // Initialize random seed
    int thread_ids[N_THREADS - 1]; // IDs for consumer threads

    // Initialize mutex and semaphores
    pthread_mutex_init(&m, NULL);
    sem_init(&prod_sem, 0, 1); // Start with producer allowed to produce
    sem_init(&cons_sem, 0, 0); // Consumer must wait initially

    // Create one producer thread and multiple consumer threads
    pthread_create(&threads[0], NULL, producer, NULL);
    for (int i = 1; i < N_THREADS; i++) {
        thread_ids[i - 1] = i;
        pthread_create(&threads[i], NULL, consumer, (void *)&thread_ids[i - 1]);
    }

    // Join threads (though they run indefinitely)
    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up (unreachable due to infinite loops)
    pthread_mutex_destroy(&m);
    sem_destroy(&prod_sem);
    sem_destroy(&cons_sem);

    return 0;
}

