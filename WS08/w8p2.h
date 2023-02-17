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


// ----------------------------------------------------------------------------
// defines/macros

#define MAX_PRODUCTS_ANALYZED 3
#define SERVINGS_IN_GRAMS 64
#define CONVERSION_FACTOR 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int Sku;
    double ProductPrice;
    double ProductWeight;
    int Calories;
};

struct ReportData
{
    struct CatFoodInfo basicInfo;
    double ProductWeightKgs;
    int ProductWeightGrams;
    double TotalServings;
    double CostPerServing;
    double CostCalServing;
};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* inputInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* inputDouble);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int nProducts);

// 4. Get user input for the details of cat food product
void getCatFoodInfo(struct CatFoodInfo[], const int SequenceNumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int Sku, const double* ProductPrice, const double* ProductWeight, const int Calories);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *Lbs, double *Kgs);

// 9. convert lbs: g
int convertLbsG(const double *Lbs, int *Grams);

// 10. convert lbs: kg / g
void convertLbs(const double *Lbs, double *Kgs, int *Grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int ServingSizeGrams, const int TotalGrams, double *nServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *ProductPrice, const double *nServings, double *CostPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *Productprice, const double *nCalories, double *CostPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo data);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData *Data, const int CheaperOpt);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo *Info);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
