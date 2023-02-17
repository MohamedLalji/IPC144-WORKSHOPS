/*
*****************************************************************************
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* inputInt)
{
	int userInput = 0;
	do {
		scanf("%d", &userInput);

		if (userInput <= 0) 
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (userInput <= 0);

	if (inputInt != NULL) 
	{
		*inputInt = userInput;
	}
		return userInput;
}



// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* inputDouble)
{
	double userInput = 0.0;
	do {
		scanf("%lf", &userInput);

		if (userInput <= 0.0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (userInput <= 0.0);

	if (inputDouble != NULL)
	{
		*inputDouble = userInput;
	}
		return userInput;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int nProducts) 
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS_ANALYZED);
	printf("NOTE: A 'serving' is %dg\n", SERVINGS_IN_GRAMS);

	return;
}


// 4. Get user input for the details of cat food product
void getCatFoodInfo (struct CatFoodInfo CF_info[], const int SequenceNumber)
{
	printf("\nCat Food Product #%d\n", SequenceNumber + 1);
	printf("--------------------\n");

	printf("SKU           : ");
	CF_info[SequenceNumber].Sku = getIntPositive(&CF_info[SequenceNumber].Sku);

	printf("PRICE         : $");
	CF_info[SequenceNumber].ProductPrice = getDoublePositive(&CF_info[SequenceNumber].ProductPrice);

	printf("WEIGHT (LBS)  : ");
	CF_info[SequenceNumber].ProductWeight = getDoublePositive(&CF_info[SequenceNumber].ProductWeight);

	printf("CALORIES/SERV.: ");
	CF_info[SequenceNumber].Calories = getIntPositive(&CF_info[SequenceNumber].Calories);
}




// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int Sku, const double* ProductPrice, const double* ProductWeight, const int Calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", Sku, *ProductPrice, *ProductWeight, Calories);
}

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo CF_info[MAX_PRODUCTS_ANALYZED] = { {0} };


	openingMessage(MAX_PRODUCTS_ANALYZED);

	for (i = 0; i < MAX_PRODUCTS_ANALYZED; i++)
	{
		getCatFoodInfo(CF_info, i);
	}
	printf("\n");

	displayCatFoodHeader();


	for (i = 0; i < MAX_PRODUCTS_ANALYZED; i++)
	{
		displayCatFoodData(CF_info[i].Sku, &CF_info[i].ProductPrice, &CF_info[i].ProductWeight, CF_info[i].Calories);
	}

	


}
