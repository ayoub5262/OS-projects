#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_BAGS 40 // We define NUM_BAGS because we will use it globally
int NUM_THREADS = 5;
int remaining_bags = NUM_BAGS;

// Function that simulates the work of a helper
void *distribute(void *arg) {
    long tid = (long)arg; // Extract thread ID from argument
    while (1) {
        if (remaining_bags > 0) {
            // Output and decrement the number of remaining bags
            printf("Remaining bags: %d, Helper #%ld distributes a bag. \n", remaining_bags, tid+1);
            remaining_bags--;
            sleep(1); // Simulates distributing a bag with a 1-second pause
        } else {
            break; // No more bags left, exit loop
        }
    }
    pthread_exit(NULL); // Terminate thread
}

int main() {
    pthread_t threads[NUM_THREADS]; // Array to store thread IDs
    int rc; // Return value for error checking
    long t; // Counter variable

    // Create helper threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating Thread #%ld\n", t+1);
        rc = pthread_create(&threads[t], NULL, distribute, (void *)t);
        if (rc) {
            perror("Error creating thread");
            exit(-1); // Error case: exit program with error code
        }
    }
    // Wait for all helper threads to finish
    for (t = 0; t < NUM_THREADS; t++) 
        pthread_join(threads[t], NULL);

    printf("Remaining bags: %d\n", remaining_bags);
    
    return 0;
}
