/*
*****************************************************************************
                          Workshop - #6 (P1)
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

int main(void)
{
    const double MAX_INCOME = 400000.00;
    const double MIN_INCOME = 500.00;
    
    double netIncome;
    
    int i,
        nWishlistitem;
   
    const double itemCost[3],
                 minItemCost = 100.00;

    int itemPriority[3];
           
    char financeOpt[3];

    double Cost = 0.0,
           wishListTotalCost = 0.0;


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if(netIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least %.2lf\n\n", MIN_INCOME);

        }
        else if(netIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than %.2lf\n\n", MAX_INCOME);
        }


    } while (netIncome < MIN_INCOME || netIncome > MAX_INCOME);

    do 
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &nWishlistitem);

        if(nWishlistitem < MIN_WISHLIST_ITEM || nWishlistitem > MAX_WISHLIST_ITEM)
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

            if(itemCost[i] < minItemCost)
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
        
        if(itemPriority[i] >= MIN_IMPORTANCE_VALUE && itemPriority[i] <= MAX_IMPORTANCE_VALUE)
        {
            do 
            {
                printf("   Does this item have financing options? [y/n]: ");
                scanf(" %c", &financeOpt[i]);

                if(financeOpt[i] != 'y' && financeOpt[i] != 'n')
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

    

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}