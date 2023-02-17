/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Mohamed Lalji
Student ID#: 168229219
Email      : mlalji@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3


int main(void)
{
    const int JAN = 1,
        DEC = 12;
        

    int year,
        month,
        day;

    double mornRating,
           morningTotal = 0.0,
           eveRating,
           eveTotal = 0.0,
           overallTotal;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        ;
    } while (((year < MIN_YEAR || year > MAX_YEAR)) || ((month < 1 || month > 12)));


    printf("\n*** Log date set! ***\n");


    for (day = 1; day <= LOG_DAYS; day++)
    {
        printf("\n%4d-", year);

        switch (month)
        {
        case 1: printf("JAN"); break;
        case 2: printf("FEB"); break;
        case 3: printf("MAR"); break;
        case 4: printf("APR"); break;
        case 5: printf("MAY"); break;
        case 6: printf("JUN"); break;
        case 7: printf("JUL"); break;
        case 8: printf("AUG"); break;
        case 9: printf("SEP"); break;
        case 10: printf("OCT"); break;
        case 11: printf("NOV"); break;
        case 12: printf("DEC"); break;
        }

        printf("-%02d\n", day);



        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf(" %lf", &mornRating);

            if (mornRating < 0.0 || mornRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                
            } 
                      
        } while (mornRating < 0.0 || mornRating > 5.0);
        morningTotal = morningTotal + mornRating;

        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf(" %lf", &eveRating);

            if (eveRating < 0.0 || eveRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

            }

        } while (eveRating < 0.0 || eveRating > 5.0);
        eveTotal = eveTotal + eveRating;
    }

    

    printf("\nSummary");
    printf("\n=======\n");

    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating:  %.3lf\n", eveTotal);
    printf("----------------------------\n");
    overallTotal = morningTotal + eveTotal;
    printf("Overall total rating: %.3lf\n\n", morningTotal + eveTotal );


    printf("Average morning rating:  %.1lf\n", morningTotal/LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", overallTotal / (LOG_DAYS + LOG_DAYS));










        return 0;
}