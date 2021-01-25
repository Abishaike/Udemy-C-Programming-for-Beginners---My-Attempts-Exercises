#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    gcd function returns the greatest common divisor
    Euclidian Algorithm was used.
*/
int gcd(int x, int y)
{
    // Initialize variables
    int result;
    int maxValue, minValue;
    int dividend, divisor;
    int quotient, remainder;

    // Determining the maximum and minimum values of the arguments
    if (x > y)
    {
        maxValue = x;
        minValue = y;
    } else
    {
        maxValue = y;
        minValue = x;
    }

    /*
        Test Case 1
            If the maximum value is divisible by the minimum value then the
            greatest common divisor would be the minimum value and the function
            returns this result.
    */
    if (maxValue % minValue == 0)
    {
        result = minValue;
        return result;
    }

    /*
        In terms of the Euclidian Algorithm, this is the first step.
    */
    dividend = maxValue;
    divisor = minValue;
    quotient = dividend / divisor;
    remainder = dividend % divisor;

    /*
        If the remainder does not equal zero. The while loop gets executed.
        The while loop will break once you reach an iteration where the
        remainder is equal to zero. At this point, the divisor represents
        the greatest common divisor.
    */
    while (remainder != 0)
    {
        dividend = divisor;
        divisor = remainder;
        quotient = dividend / divisor;
        remainder = dividend % divisor;
    }

    // Dislaying the greast common divisor
    result = divisor;
    return result;
}

/*
    Absolute Function
        Takes an input and makes it positive if it's negative.
        If the input is already positive then it returns the input.
*/
float absolute(float x)
{
    float result;
    if (x < 0)
    {
        result = x * -1;
        return result;
    } else
    {
        return x;
    }
}

/*
    squareRoot function is used to determine the square root of a number
*/
float squareRoot(float x)
{
    // Allocate the argument to the target variable
    float target = x;

    // result will be the output from this function
    float result;

    // If the user enters a negative argument, the function return -1
    if (target < 0)
    {
        printf("The argument %.2f is a negative number. A positive number is required.\n", target);
        result = -1;
        return result;
    }

    /*
        For loop is used to determine the square root
        If the square root of the argument is determined you will then
        break out of the function
    */
    float squared = 0;
    int i = 1;
    bool perfectSquare = false;
    for (i; squared < target; i++)
    {
        squared = i * i;
        if (squared == target)
        {
           perfectSquare = true;
           result = i;
           return result;
        }
    }

    /*
        If you were not able to find to the square root of the argument
        An approximation method would be used to approximate the square root
    */
    if (perfectSquare == false)
    {
        /*
            i - 2 represents the starting point to guess what the
            square root will be. The result i comes from the previous
            for loop
        */
        float guess = i - 2;
        float tolerance = 0.1;
        float diff;

        squared = guess * guess;
        diff = target - squared;

        /*
            While loop will continue executing until the differential between
            the target and the approximated result is less than or equal to
            the tolerance.
        */
        while (diff >= tolerance)
        {
            guess+= 0.1;
            squared = guess * guess;
            diff = target - squared;
        }

        result = guess;
        return result;
    }
}

int main(void)
{
    // Testing out the gcd function
    int x1, x2;
    int f1;

    x1 = 888, x2 = 54;
    f1 = gcd(x1, x2);
    printf("The greatest common divisor of %d and %d is %d.\n", x1, x2, f1);
    printf("\n");


    // Testing the Absolute Function by using integers as inputs although the function
    // requires a float as its input
    int x3, x4;
    int f2, f3;
    x3 = -5, x4 = 5;
    f2 = absolute(x3);
    f3 = absolute(x4);
    printf("Using integers on an aboslute function that requires a float but we're inputting an integer.\n");
    printf("Input: Integer (%d), Output: Integer (%d)\n", x3, f2);
    printf("Input: Integer (%d), Output: Integer (%d)\n", x4, f3);
    printf("\n");

    // Testing the Absolute Function by using floats as inputs
    float x5, x6;
    float f4, f5;
    x5 = -5, x6 = 5;
    f4 = absolute(x5);
    f5 = absolute(x6);
    printf("Following the conventions of the absolute function, we're using floats as arguments.\n");
    printf("Input: Float (%.1f), Output: Float (%.1f)\n", x5, f4);
    printf("Input: Float (%.1f), Output: Float (%.1f)\n", x6, f5);
    printf("\n");

    // Testing the square root function
    float x7, x8, x9;
    float f6, f7, f8;
    x7 = 49, x8 = 4567, x9 = -3;

    f6 = squareRoot(x7);
    printf("Input: %.2f, Output: %.2f\n", x7, f6);
    printf("\n");

    f7 = squareRoot(x8);
    printf("Input: %.2f, Output: %.2f\n", x8, f7);
    printf("\n");

    f8 = squareRoot(x9);
    printf("Input: %.2f, Output: %.2f\n", x9, f8);
    printf("\n");

    return 0;
}
