#include <stdio.h>
#include <stdlib.h>

// Function that checks whether a given number is a prime number or not
int is_prime(int num) {
    if (num <= 1) return 0;                // If the number is less than or equal to 1, it is not a prime number
    for (int i = 2; i * i <= num; i++) {   // Check all numbers up to the square root of the given number
        if (num % i == 0) return 0;        // If the number is divisible by any number without remainder, it is not a prime number
    }
    return 1;                               // If none of the conditions apply, the number is a prime number
}

int main(int argc, char *argv[]) {
    if (argc != 2) {                        // Check if an argument was passed
        // Error message if no argument was passed
        printf("Error: No upper limit for prime numbers provided\n");
        return 1;                           // Exit the program with an error code
    }

    int upper_limit = atoi(argv[1]);        // Convert the passed argument to an integer
    // Iterate through all numbers from 2 to the upper limit
    for (int i = 2; i <= upper_limit; i++) {
        if (is_prime(i))                    // Check if the current number is a prime number
            printf("%d,", i);               // If yes, print the number
    }
    printf("\n");                           // Print a new line at the end of the program
    return 0;                               // Exit the program successfully
}
