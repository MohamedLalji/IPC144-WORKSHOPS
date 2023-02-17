/*
*****************************************************************************
                          Workshop - #4 (P2)
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

    int nApples, nOranges, nPears, nTomatoes, nCabbages;
    int nPicked, continueShopping;

    do 
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &nApples);

            if (nApples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (nApples < 0);
        printf("\n");

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &nOranges);

            if (nOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (nOranges < 0);
        printf("\n");

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &nPears);

            if (nPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (nPears < 0);
        printf("\n");

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &nTomatoes);

            if (nTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (nTomatoes < 0);


        
        printf("\n");

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &nCabbages);

            if (nCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (nCabbages < 0);

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");

        if (nApples > 0)
        {
            while (nApples > 0)
            {
                printf("\nPick some APPLES... how many did you pick? : ");
                scanf("%d", &nPicked);
                if (nPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (nPicked > nApples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.", nApples);
                }
                else
                {
                    nApples = nApples - nPicked;
                    if (nApples > 0)
                    {

                        printf("Looks like we still need some APPLES...");
                    }
                    else
                    {
                        printf("Great, that's the apples done!\n");
                    }
                }
            }

        }


        if (nOranges > 0)
        {
            while (nOranges > 0)
            {
                printf("\nPick some ORANGES... how many did you pick? : ");
                scanf("%d", &nPicked);
                if (nPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (nPicked > nOranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.", nOranges);
                }
                else
                {
                    nOranges = nOranges - nPicked;
                    if (nOranges > 0)
                    {

                        printf("Looks like we still need some ORANGES...");
                    }
                    else
                    {
                        printf("Great, that's the oranges done!\n");
                    }
                }
            }

        }
        
        if (nPears > 0)
        {
            while (nPears > 0)
            {
                printf("\nPick some PEARS... how many did you pick? : ");
                scanf("%d", &nPicked);
                if (nPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (nPicked > nPears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.", nPears);
                }
                else
                {
                    nPears = nPears - nPicked;
                    if (nPears > 0)
                    {

                        printf("Looks like we still need some PEARS...");
                    }
                    else
                    {
                        printf("Great, that's the pears done!\n");
                    }
                }
            }

        }

        if (nTomatoes > 0)
        {
            while (nTomatoes > 0)
            {
                printf("\nPick some TOMATOES... how many did you pick? : ");
                scanf("%d", &nPicked);
                if (nPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (nPicked > nTomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.", nTomatoes);
                }
                else
                {
                    nTomatoes = nTomatoes - nPicked;
                    if (nTomatoes > 0)
                    {

                        printf("Looks like we still need some TOMATOES...");
                    }
                    else
                    {
                        printf("Great, that's the tomatoes done!\n\n");
                    }
                }
            }

        }

        if (nCabbages > 0)
        {
            while (nCabbages > 0)
            {
                printf("\nPick some CABBAGES... how many did you pick? : ");
                scanf("%d", &nPicked);
                if (nPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (nPicked > nCabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.", nCabbages);
                }
                else
                {
                    nCabbages = nCabbages - nPicked;
                    if (nCabbages > 0)
                    {

                        printf("Looks like we still need some CABBAGES...");
                    }
                    else
                    {
                        printf("Great, that's the cabbages done!\n\n");
                    }
                }
            }

        }

        printf("All the items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueShopping);
        
        printf("\n");
        
    } while (continueShopping == 1);

    printf("Your tasks are done for today - enjoy your free time!\n");
       return 0;
}