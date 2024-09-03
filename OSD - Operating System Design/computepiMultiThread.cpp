
//Documentation:
//This program improves the previous assignment  to estimating the value of pi by incorporating multithreading. 
//By leveraging the power of multiple threads, the program divides the workload and assigns it to ten different threads. 
//Each thread  runs the `gnrtePnts` function, which takes on the generating a specific number of random points to determine their placement within a unit circle. 
//Through the use of global variables  `tp` for keeping track of total points and `p_crcle` for storing those within the circle.
//To prevent the race condition that may arise from modifying the global variable , a mutex called `cnt_mtx` is implemented,


#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <cmath>
#include <ctime>
#include <mutex>

std::mutex cnt_mtx;  // Mutex to prevent the race condition for the shared global variable

long long tp = 0;  // This stores the total number of points 
long long p_crcle = 0;  // This stores the number of points within the circle

// This function takes the input and calculates wether the pionts lie within the circle 
void* gnrtePnts(void* arg) {
    int nm_pnts = *(int*)arg;
    unsigned int sd = time(NULL) + pthread_self();
    double x, y, dst;

    for (int i = 0; i < nm_pnts; ++i) {
        x = (double)rand_r(&sd) / RAND_MAX;
        y = (double)rand_r(&sd) / RAND_MAX;

        // This calculates the area of the circle.
        dst = x * x + y * y;

        cnt_mtx.lock();  // this is used to lock the variable

        tp++;
        if (dst <= 1.0) {
            p_crcle++;
        }

        cnt_mtx.unlock();  // After updating the global variable the mutex can be unlocked
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Syntax: " << argv[0] << " num" << std::endl;
        return 1;
    }

    int nm_pnts = std::atoi(argv[1]);
    const int thrd_cnt = 10;
    pthread_t t[thrd_cnt];

    // RUn the for loop for 10 times calculating the number of pionits within the cricle.
    // This calls the function for 10 times which updates the global variable.
    for (int i = 0; i < thrd_cnt; ++i) {
        pthread_create(&t[i], NULL, gnrtePnts, &nm_pnts);
        std::cout << "Generating " << nm_pnts / thrd_cnt << " number of random numbers in thread id = " << t[i] << std::endl;
    }

    // This is used to join the thread
    for (int i = 0; i < thrd_cnt; ++i) {
        pthread_join(t[i], NULL);
    }

    // THe value of the pi is calculated using the below formula
    double pi = 4.0 * p_crcle / tp;

    // The result is printed out.
    std::cout << "In main thread, value of PI using Monte Carlo technique with " << nm_pnts << " random points = " << pi << std::endl;

    return 0;
}

