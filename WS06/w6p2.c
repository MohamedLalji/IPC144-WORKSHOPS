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
#define MIN_WISHLIST_ITEM 1
#define MAX_WISHLIST_ITEM 10
#define MIN_IMPORTANCE_VALUE 1
#define MAX_IMPORTANCE_VALUE 3
#define FM_QUIT 0
#define FM_ALL 1
#define FM_PRIORITY 2

int main(void)
{
    const double MAX_INCOME = 400000.00;
    const double MIN_INCOME = 500.00;

    double netIncome;

    int finance_flag,
        i,
        nWishlistitem;

    const double itemCost[MAX_WISHLIST_ITEM],
        minItemCost = 100.00;

    int itemPriority[MAX_WISHLIST_ITEM],
        forecastMethod,
        years,
        months,
        customerPriority;

    char financeOpt[MAX_WISHLIST_ITEM];

    double Cost = 0.0,
        wishListTotalCost = 0.0,
        TotalCost = 0.0,
        priorityTotalCost = 0.0;
 
  
    


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least %.2lf\n\n", MIN_INCOME);

        }
        else if (netIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than %.2lf\n\n", MAX_INCOME);
        }


    } while (netIncome < MIN_INCOME || netIncome > MAX_INCOME);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &nWishlistitem);

        if (nWishlistitem < MIN_WISHLIST_ITEM || nWishlistitem > MAX_WISHLIST_ITEM)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_WISHLIST_ITEM, MAX_WISHLIST_ITEM);
        }

    } while (nWishlistitem <= MIN_WISHLIST_ITEM || nWishlistitem >= MAX_WISHLIST_ITEM);



    for (i = 1; i <= nWishlistitem; i++)
    {
        printf("\nItem-%d Details:\n", i);

        do
        {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);

            if (itemCost[i] < minItemCost)
            {
                printf("      ERROR: Cost must be at least %.2lf\n", minItemCost);
            }

        } while (itemCost[i] < minItemCost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);

            if (itemPriority[i] < MIN_IMPORTANCE_VALUE || itemPriority[i] > MAX_IMPORTANCE_VALUE)
            {
                printf("      ERROR: Value must be between %d and %d\n", MIN_IMPORTANCE_VALUE, MAX_IMPORTANCE_VALUE);
            }

        } while ((itemPriority[i] < MIN_IMPORTANCE_VALUE) || (itemPriority[i] > MAX_IMPORTANCE_VALUE));

        if (itemPriority[i] >= MIN_IMPORTANCE_VALUE && itemPriority[i] <= MAX_IMPORTANCE_VALUE)
        {
            do
            {
                printf("   Does this item have financing options? [y/n]: ");
                scanf(" %c", &financeOpt[i]);

                if (financeOpt[i] != 'y' && financeOpt[i] != 'n')
                {
                    printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                }
            } while (financeOpt[i] != 'y' && financeOpt[i] != 'n');
        }
    }

    printf("\nItem Priority Financed Cost\n");
    printf("---- -------- -------- -----------\n");


    for (i = 1; i <= nWishlistitem; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i, itemPriority[i], financeOpt[i], itemCost[i]);
        wishListTotalCost = wishListTotalCost + itemCost[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", wishListTotalCost);

    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecastMethod);

        if(forecastMethod != FM_ALL && forecastMethod != FM_PRIORITY && forecastMethod != FM_QUIT)
        {
            printf("\nERROR: Invalid menu selection.\n\n");
        }

        else if (forecastMethod == FM_ALL)
        {
            finance_flag = 0;
            for (i = 1; i <= nWishlistitem; i++)
            {
                TotalCost = TotalCost + itemCost[i];
                years = (int)TotalCost / netIncome;
                months = (int)TotalCost / netIncome;
                if (itemPriority[i] = 'y')
                {
                    finance_flag = 1;
                }
            }
            
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", TotalCost);
            printf("Forecast: %d years, ", years / 12);

            if (months >= 6.5)
            {
                printf("%d months\n", months % 12 + 1);
            }
            else 
            {
                printf("%d months\n", months % 12 - 1);
            }
            if (finance_flag = 1)
            {
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");



        }

        else if (forecastMethod == FM_PRIORITY)
        {
            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &customerPriority);
            } while (customerPriority < MIN_IMPORTANCE_VALUE && customerPriority > MAX_IMPORTANCE_VALUE);

            
            finance_flag = 0;
            for (i = 1; i <= customerPriority; i++)
            {

                if (itemPriority[i] == customerPriority)
                {
                    wishListTotalCost = wishListTotalCost + itemCost[i];
                    years = (int)wishListTotalCost / netIncome;
                    months = (int)wishListTotalCost / netIncome;

                    if (itemPriority[i] = 'y')
                    {
                        finance_flag = 1;

                    }

                }
            }

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", customerPriority);
            printf("Amount:   $%1.2lf\n", wishListTotalCost);

            printf("Forecast: %d years, ", years / 12);
          
            if (months != .5)
            {
                printf("%d months\n", months % 12 + 1);
            }
            else
            {
                printf("%d months\n", months % 12 - 1);
            }
            if (finance_flag = 1)
            {
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            }
          
            printf("====================================================\n\n");




        }
        
       

    } while (forecastMethod != FM_QUIT);
  
    printf("\nBest of luck in all your future endeavours!\n");
    
       
        
        





    

















    

    return 0;
}