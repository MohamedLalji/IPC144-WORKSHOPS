/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : mohamed lalji
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

int main(void)

{
    int done = 0, numberOfIterations;

    char loopType;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {

        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &numberOfIterations);

        if ((loopType == 'D' || loopType == 'W' || loopType == 'F' || loopType == 'Q'))
        {
            if ((numberOfIterations >= 3 && numberOfIterations <= 20))
            {
                if (loopType == 'D')
                {
                    printf("DO-WHILE: ");

                    do {
                        printf("%c", loopType);
                        numberOfIterations = numberOfIterations - 1;
                    } while (numberOfIterations > 0);
                }
                else if (loopType == 'W')
                {
                    printf("WHILE   : ");
                    while (numberOfIterations > 0)
                    {
                        printf("%c", loopType);
                        numberOfIterations = numberOfIterations - 1;
                    }
                }
                else if (loopType == 'F')
                {
                    printf("FOR   : ");

                    for (; numberOfIterations > 0; numberOfIterations--)
                    {
                        printf("%c", loopType);
                    }
                }
            }
            else
            {
                if (loopType == 'Q')
                {
                    if (numberOfIterations == 0)
                    {
                        done = 1;
                    }
                    else
                    {
                        printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                    }
                }
                else
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
            }
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }

    } while (done == 0);


    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n\n");
    return 0;
}
   