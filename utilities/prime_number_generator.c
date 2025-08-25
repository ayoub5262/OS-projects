#include <stdio.h>

// Function that checks whether a given number is a prime number or not
int is_prime(int num) {
    if (num <= 1) return 0;                // If the number is less than or equal to 1, it is not a prime number
    for (int i = 2; i * i <= num; i++) {   // Check all numbers up to the square root of the given number
        if (num % i == 0) return 0;        // If the number is divisible by any number without remainder, it is not a prime number
    }
    return 1;                               // If none of the conditions apply, the number is a prime number
}

int main(){
    for ( int i = 2 ; i <= 20; i++){       // Iterate through all numbers from 2 to the upper limit
        if (is_prime(i))                    // Check if the current number is a prime number
            printf("%i, ", i);              // If yes, print the number
    }
    printf("\n");                           // Print a new line at the end of the program
    return 0;                               // Exit the program successfully
}
