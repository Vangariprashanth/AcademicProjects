/*
Documentation:

 * Monte Carlo Pi Estimation:

 * This program is used to calculate the value of pi using the Monte Carlo method. The Monte Carlo method consists of  random points within a circle of radius 1 and calculating the ratio of points within the circle to the total points generated to estimate pi.
 * Algorithm Steps:
 * 1. Generate random points as (x, y) co-ordinates.
 * 2. Determine if each point falls within the circle.
 * 3. Count the number of points that are within the circle.
 * 4. Estimate pi using the formula: pi is approximately equals to 4 * (points in circle) / (total points generated).
 * Input: Total number of points.
 * Output: Estimated value of π.
 */
#include <iostream> // Standard I/O library for input and output
#include <cstdlib> //POSIX threads used for multi threading
#include <ctime>
#include <pthread.h>
#include <cmath> // used to perform mathematical calculations

using namespace std;

int total_pts;      // Holds total number of points provided by user      
int pts_inside_crcle = 0;  // Used to store total number of points that are lying inside the circle
pthread_mutex_t mtx;     // Creates mutex ( mutual exclusion)

void* solve(void* arg) {
    for (int i = 0; i < total_pts; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX;  // Stores the random value of x which is between 0 and 1 
        double y = static_cast<double>(rand()) / RAND_MAX;  // Stores the random value of y which is again between zero and one

        if (x * x + y * y <= 1.0) {     // Formula is used to calcualte the area of the circle if the points are less than 1 then it falls inside the cricle 
            pthread_mutex_lock(&mtx);  //locks the pts_inside_crcle variable so that other threads are not using it in the same time
            pts_inside_crcle++;
            pthread_mutex_unlock(&mtx);  // unlocks the pts_inside_crcle variable so that other threads can use it
        }
    }
    return nullptr;  
}

int main(int argc, char* argv[]) {
    if (argc != 2) {  // It should accept two arguments: The name of the program itself and the total number of points
        cerr << "Provide only one number" << endl;
        return 1;
    }

    total_pts = atoi(argv[1]); // Converts the ascii code to integer

    if (total_pts <= 0) {  // Checks if the entered total number of points is zero or less than. It asks the 
        cerr << "Please provide a positive number of points." << endl;
        return 1;   //returns the exit status
    }

    pthread_mutex_init(&mtx, nullptr);  // Create the'mtx' pthread mutex by initializing it. A mutex used for thread synchronization is initialized on this line. The'mtx' mutex is started with default properties. 'nullptr' represents the absence of any default attributes.
    srand(static_cast<unsigned int>(time(nullptr)));

    pthread_t thrd;
    pthread_create(&thrd, nullptr, solve, nullptr);

    pthread_join(thrd, nullptr); //This line waits till the thread 'thrd' has finished running before continuing. It makes sure the main thread waits until the newly created thread has finished running before moving on.

    pthread_mutex_destroy(&mtx);  
// declares the  pthread named 'thrd' to store the identifier of the newly created thread.
    double calculatedPi = 4.0 * static_cast<double>(pts_inside_crcle) / total_pts; // Calculate the value of pi(estimation) using the formula
    
    cout << "Total count of points inside the circle = " << pts_inside_crcle << endl;
    cout << "Value of PI using Monte Carlo technique with " << total_pts << " random points = " << calculatedPi << endl;

    return 0; //return zero means the program exited by completing successfully
}

