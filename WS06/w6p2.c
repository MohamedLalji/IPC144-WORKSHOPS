/*
*****************************************************************************
                          Workshop - #6 (P2)
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

#define MIN 1
#define MAX 10

int main(void)
{
    int flag1 = -1, flag2 = -1, i, forecast, years, month, nItems, selection = -1;;

    const double minIncome = 500.00, maxIncome = 400000.00;
    double income, subTotal = 0, priorityCost = 0;;

    double cost[10];
    int priority[10];
    char financing[10];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+");

    do
    {
        printf("\n\nEnter your monthly NET income: $");
        scanf("%lf", &income);
        if (income >= minIncome && income <= maxIncome)
        {
            flag1 = 0;
        }
        else
        {
            if (income < minIncome)
            {
                printf("ERROR: You must have a consistent monthly income of at least $500.00");
            }
            if (income > maxIncome)
            {
                printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
            }
        }
    } while (flag1 != 0);

    flag1 = -1;

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &nItems);
        if (nItems >= MIN && nItems <= MAX)
        {
            flag1 = 0;
        }
        else
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (flag1 != 0);

    for (i = 0; i < nItems; i++)
    {
        flag1 = -1;
        printf("\nItem-%d Details:", i + 1);

        do
        {
            printf("\n   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] > 100.00)
            {
                flag1 = 0;
            }
            else
            {
                printf("      ERROR: Cost must be at least $100.00");
            }
        } while (flag1 != 0);

        flag1 = -1;

        subTotal = subTotal + cost[i];

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] > 0 && priority[i] < 4)
            {
                flag1 = 0;
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (flag1 != 0);

        flag1 = -1;

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);
            if (financing[i] == 'y' || financing[i] == 'n')
            {
                flag1 = 0;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (flag1 != 0);

    }
    printf("\nItem Priority Financed        Cost");
    printf("\n---- -------- -------- -----------");

    for (i = 0; i < nItems; i++)
    {
        printf("\n%3d%7d%9c%15.2lf", i + 1, priority[i], financing[i], cost[i]);
    }

    printf("\n---- -------- -------- -----------");
    printf("\n                      $ %0.2lf", subTotal);

    do
    {
        flag1 = -1;
        do

        {
            printf("\n\nHow do you want to forecast your wish list?\n 1. All items (no filter)\n");
            printf(" 2. By priority\n 0. Quit/Exit\nSelection: ");
            scanf("%d", &selection);

            if (selection >= 0 && selection <= 2)
            {
                flag1 = 0;
            }

            else
            {
                printf("\nERROR: Invalid menu selection.");
            }

        } while (flag1 != 0);

        flag1 = -1;

        if (selection == 1)
        {
            printf("\n====================================================");
            printf("\nFilter:   All items");
            printf("\nAmount:   $%0.2lf", subTotal);

            years = (subTotal / income) / 12;
            month = (int)((subTotal / income) * 100) % 1200;

            if (month % 100 != 0)

            {
                month = month / 100;
                month = month + 1;
                if (month == 12)
                {
                    years = years + 1;
                    month = 0;
                }
            }
            for (i = 0; i < nItems; i++)
            {
                if (financing[i] == 'y')

                {
                    flag1 = 0;
                }
            }
            printf("\nForecast: %d years, %d months", years, month);
            if (flag1 == 0)
            {
                printf("\nNOTE: Financing options are available on some items.");
                printf("\n      You can likely reduce the estimated months.");
            }

            printf("\n====================================================");
        }
        if (selection == 2)
        {
            flag1 = -1;
            do

            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &forecast);
                if (forecast > 0 && forecast < 4)
                {
                    flag1 = 0;
                }
                else
                {
                    printf("   ERROR: Value must be between 1 and 3\n");
                }
            } while (flag1 != 0);
            flag1 = -1;
            priorityCost = 0;
            for (i = 0; i < nItems; i++)
            {
                if (priority[i] == forecast)
                {
                    priorityCost = priorityCost + cost[i];
                    if (financing[i] == 'y')

                    {
                        flag1 = 0;
                    }
                }
            }
            printf("\n====================================================");
            printf("\nFilter:   by priority (%d)", forecast);
            printf("\nAmount:   $%0.2lf", priorityCost);

            years = (priorityCost / income) / 12;
            month = (int)((priorityCost / income) * 100) % 1200;

            if (month % 100 != 0)
            {
                month = month / 100;
                month = month + 1;

                if (month == 12)
                {
                    years = years + 1;
                    month = 0;
                }
            }

            printf("\nForecast: %d years, %d months", years, month);

            if (flag1 == 0)
            {
                printf("\nNOTE: Financing options are available on some items.");
                printf("\n      You can likely reduce the estimated months.");
            }
            printf("\n====================================================");


        }

        if (selection == 0)
        {
            flag2 = 0;
        }

    } while (flag2 != 0);

    printf("\nBest of luck in all your future endeavours!\n");
    return 0;
}
