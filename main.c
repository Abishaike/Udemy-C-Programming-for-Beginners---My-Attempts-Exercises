#include <stdio.h>
#include <stdlib.h>

/*
    Author: Abishaike Balachandran
    Description
        - Displaying the monthly rainfall averages from 2010 till 2014
        - Displaying the total amount of rainfall for each year from 2010 till 2014
        - Display the average amount of rainfall from 2010 till 2014
*/
int main()
{
    /*
        A 2D Array representing the amount of rainfall from 2010 till 2014 for each month.
        The rows represent the years [2010 till 2014]
        The columns represent the months [Jan till December]
    */
    float rainData [5][12] = {
                        { 7.8, 1.2, 3.4, 6.4, 2, 3.2, 1.2, 3.1, 5.6, 6.6, 9.8, 6.2 },
                        { 4.8, 0.2, 2.4, 5.4, 1, 1.2, 0.2, 4.1, 4.6, 5.6, 7.8, 3.1 },
                        { 10.3, 19.3, 100.3, 2.3, 1.4, 76.2, 3.4, 1.2, 3.4, 13.4, 12.5, 345.7},
                        { 456.3, 894.2, 123.4, 666.2, 1243.2, 13.5, 987.2, 1, 124.2, 453.2, 12.3,132.4 },
                        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }
                    };
    /*
        1) int year and int month
             - will be used to access the data present within the rainData array
        2) float yearlyTotals
             - array that will hold the total amount of rainfall for each year from 2010 till 2014
        3) float annualRainFall
            - Initialized to zero
            - Used wihin the for loop down below to determine the total amount of rainfall for each year
    */
    int year;
    int month;
    float yearlyTotals[5] = {0};
    float annualRainFall = 0;

    /*
        For loop is used to determine the total amount of rainfall for each year
        Outer loop
            - Represents the year
        Inner Loop
            - Represents the month
            - Summation of the amount of rainfall that took place each month for a specified year
              takes plac
    */
    for (year=0 ; year < 5; ++year)
    {
        for (month = 0; month < 12; ++month)
        {
            annualRainFall = annualRainFall  + rainData[year][month];
        }

        // Added to the array
        yearlyTotals[year] = annualRainFall;

        // Initalized back to zero
        annualRainFall = 0;
    }

    // Display the output
    printf("\nYEAR  RAINFALL (inches)\n");
    printf("2010  %.2f\n", yearlyTotals[0]);
    printf("2011  %.2f\n", yearlyTotals[1]);
    printf("2012  %.2f\n", yearlyTotals[2]);
    printf("2013  %.2f\n", yearlyTotals[3]);
    printf("2014  %.2f\n", yearlyTotals[4]);


    /*
        float fiveYearTotal & float averageFiveYears
            - Declared these variables to calculate the yearly average
    */
    float fiveYearTotal = 0;
    float averageFiveYears;

    /*
        For Loop is used to determine the total amount of rainfall that ocurred from 2010 till 2014
    */
    for (year =0; year < 5; ++year)
    {
        fiveYearTotal = fiveYearTotal + yearlyTotals[year];
    }

    // Calculate the average
    averageFiveYears = fiveYearTotal / 5;

    // Displaying the yearly average
    printf("\nThe yearly average is %.2f inches.\n", averageFiveYears);

    /*
        float monthlyAvg [12] = {0}
            - Creating an array of length 12 to store the monthly averages from 2010 till 2014
        float monthSpecificTotal
            - Initalized to zero
            - Used within the for loop to tally up the total amount of rainfall per month from 2010 till 2014
    */
    float monthlyAvg[12] = {0};
    float monthSpecificTotal = 0;

    /*
        For loop is used to determine the monthly average of rainfall from 2010 till 2014

        Outer loop
            - Represents the month

        Inner Loop
            - Represents the year
            - Monthly Total from 2010 till 2014 gets tallied up in the inner loop
    */
    for (month =0 ; month < 12; ++month)
    {
        for (year = 0; year < 5; ++year)
        {
            monthSpecificTotal = monthSpecificTotal  + rainData[year][month];
        }

        // Calculating the monthly average
        monthlyAvg[month] = monthSpecificTotal / 5;

        // Initalizing the monthSpecificTotal variable
        monthSpecificTotal = 0;
    }

    printf("\nMONTH  MONTHLY AVERAGE RAINFALL (inches)\n");
    printf("JAN  %.2f\n", monthlyAvg[0]);
    printf("FEB  %.2f\n", monthlyAvg[1]);
    printf("MAR  %.2f\n", monthlyAvg[2]);
    printf("APR  %.2f\n", monthlyAvg[3]);
    printf("MAY  %.2f\n", monthlyAvg[4]);
    printf("JUN  %.2f\n", monthlyAvg[5]);
    printf("JUL  %.2f\n", monthlyAvg[6]);
    printf("AUG  %.2f\n", monthlyAvg[7]);
    printf("SEP  %.2f\n", monthlyAvg[8]);
    printf("OCT  %.2f\n", monthlyAvg[9]);
    printf("NOV  %.2f\n", monthlyAvg[10]);
    printf("DEC  %.2f\n", monthlyAvg[11]);

    return 0;
}
