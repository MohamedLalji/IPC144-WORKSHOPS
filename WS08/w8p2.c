/*
*****************************************************************************
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
void getCatFoodInfo(struct CatFoodInfo CF_info[], const int SequenceNumber)
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *Lbs, double *Kgs)
{
	if (Kgs != NULL)
	{
		*Kgs = *Lbs / CONVERSION_FACTOR;
		return *Kgs;
	}
	else
	{
		return *Lbs / CONVERSION_FACTOR;
	}
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *Lbs, int *Grams)
{
	if (Grams != NULL)
	{
		*Grams = (int)(convertLbsKg(Lbs, NULL) * 1000.00);
		return *Grams;
	}

	else
	{
		return (int)(convertLbsKg(Lbs, NULL) * 1000.00);
	}
}

// 10. convert lbs: kg and g
void convertLbs(const double *Lbs, double *Kgs, int *Grams)
{
	convertLbsKg(Lbs, Kgs);
	convertLbsG(Lbs, Grams);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int ServingSizeGrams, const int TotalGrams, double *nServings)
{
	if (nServings != NULL)
	{
		*nServings = (double)TotalGrams / (double)ServingSizeGrams;
		return *nServings;
	}
	else
	{
		return((double)TotalGrams / (double)ServingSizeGrams);
	}
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* ProductPrice, const double* nServings, double* CostPerServing)
{
	if (CostPerServing != NULL)
	{
		*CostPerServing = *ProductPrice / *nServings;
		return *CostPerServing;
	}

	else
	{
		return (*ProductPrice / *nServings);
	}
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* Productprice, const double* nCalories, double* CostPerCal)
{
	if (CostPerCal != NULL)
	{
		*CostPerCal = *Productprice / *nCalories;
		return *CostPerCal;
	}

	else
	{
		return *Productprice / *nCalories;
	}
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo data)
{
	struct ReportData Data = { {0} };
	double calories;

	Data.basicInfo = data;
	Data.ProductWeightKgs = convertLbsKg(&data.ProductWeight, NULL);
	Data.ProductWeightGrams = convertLbsG(&data.ProductWeight, NULL);
	Data.TotalServings = calculateServings( SERVINGS_IN_GRAMS, Data.ProductWeightGrams, NULL);
	Data.CostPerServing = calculateCostPerServing(&data.ProductPrice, &Data.TotalServings, NULL);
	calories = data.Calories * Data.TotalServings;
	Data.CostCalServing = calculateCostPerCal(&data.ProductPrice, &calories, NULL);

	return Data;

}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SERVINGS_IN_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData* Data, const int CheaperOpt)
{
	if (CheaperOpt)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", Data->basicInfo.Sku, Data->basicInfo.ProductPrice, Data->basicInfo.ProductWeight, Data->ProductWeightKgs, Data->ProductWeightGrams, Data->basicInfo.Calories, Data->TotalServings, Data->CostPerServing, Data->CostCalServing);
	}

	else
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", Data->basicInfo.Sku, Data->basicInfo.ProductPrice, Data->basicInfo.ProductWeight, Data->ProductWeightKgs, Data->ProductWeightGrams, Data->basicInfo.Calories, Data->TotalServings, Data->CostPerServing, Data->CostCalServing);
	}
	
}


	
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo* Info)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", Info->Sku, Info->ProductPrice);
	printf("Happy shopping!");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i;
	int cheap = 0;
	int CheaperOpt = 0;
	struct CatFoodInfo CF_info[MAX_PRODUCTS_ANALYZED] = { {0} };
	struct ReportData DataArray[MAX_PRODUCTS_ANALYZED] = { { {0} } };

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

	printf("\n");

	for (i = 0; i < MAX_PRODUCTS_ANALYZED; i++)
	{
		DataArray[i] = calculateReportData(CF_info[i]);
	}

	for (i = 0; i < MAX_PRODUCTS_ANALYZED; i++)
	{
		if (DataArray[cheap].CostPerServing > DataArray[i].CostPerServing)
		{
			cheap = i;
		}
	}

	displayReportHeader();
	for (i = 0; i < MAX_PRODUCTS_ANALYZED; i++)
	{
		if (i == cheap)
		{
			CheaperOpt = 1;
			displayReportData(&DataArray[i], CheaperOpt);
		}
		else
		{
			CheaperOpt = 0;
			displayReportData(&DataArray[i], CheaperOpt);
		}
	}
	printf("\n");

	displayFinalAnalysis(&CF_info[cheap]);
}
