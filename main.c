#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Author: Abishaike Balachandran
    Exercise: Find all of the prime Numbers from 3 till 100
*/

int main()
{
    /*
        Initialize the integer array below so that it can hold 98 values
        Maximum Possible Num of Prime Num from 3 till 100 = (100 -3) + 1 = 98 values
        The addition of 1 ensures that the number "3" will be included
    */
    int primeINT[98];

    /*
        This for loop ensures that all of the elements within the array
        gets initialized to zero.
    */
    int i;
    for (i = 0 ; i < 98; i++) {
        primeINT [i] = 0;
    }

    /*
        This is the initial condition.
        The first prime number that is present within the range [3-100] is 3.
    */
    primeINT[0] = 3;
    printf("Index of Prime Number Array: %d\n", 0);
    printf("Slot of Prime Number Array: %d\n", 1);
    printf("%d is a prime number.\n", primeINT[0]);
    printf("\n");

    /*
        Declare the variables that will be used in the for loop below
        int number
            - loops through all of the numbers from 3 till 100 to determine if it is a prime num
        int innerIndex
            - present within the inner loop to determine whether the already determined prime
              numbers are divisible by the current number which is being tested to see if it is a
              prime number
    */
    int number;
    int innerIndex;

    /*
        - Initialized oddPrime to true at the moment
        - oddPrime becomes false if the current number is divisble by any of the extracted prime numbers
    */
    bool oddPrime = true;

    /*
        Abstract Level
            -For Loop is used to loop through 4 till 100 to extract all of the prime numbers
            - Test Case 1 [Even]
                - If the number is even then we would continue on to the next iteration since it's
                  a composite number
            - Test Case 2 [Odd]
                - While loop is used to loop through the extracted prime numbers to see if the current
                  number is divisble.
                - If it's divisible then it's a composite number.
                - The while loop breaks when you finish scanning the last extracted prime number
            - Final Segments
                - Following the first two test cases, if the number is still a prime number then it gets
                  added to the array
    */
    for (number = 4; number <= 100; number++){
        // Test Case 1
        if (number % 2 == 0)
            continue;

        // Test Case 2
        innerIndex = 0;
        while (primeINT[innerIndex] != 0) {
            /*
                Break out of the while loop if the current number is
                divisible by any of the extracted prime numbers
            */
            if (number % primeINT[innerIndex] == 0) {
                oddPrime = false;
                break;
            }
            innerIndex++;
        }

        /*
        Test Case 2
            If it is a composite number then we would reinitialize the boolean
            back to true and continue on to the next iteration
        */
        if (oddPrime == false) {
            oddPrime = true;
            continue;
        }

        /*
        Final Segment
            If we reach this portion of the code then the current number
            is a prime number
        */
        primeINT[innerIndex] = number;

        printf("Index of Prime Number Array: %d\n", innerIndex);
        printf("Slot of Prime Number Array: %d\n", innerIndex + 1);
        printf("%d is a prime number.\n", number);
        printf("\n");
    }
    return 0;
}
