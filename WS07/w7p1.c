/*
*****************************************************************************
                          Workshop - #7 (P1)
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

#define MIN_LIVES 1
#define MAX_LIVES 10

#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70

#define PATH_LENGTH_MULTIPLE 5




#include <stdio.h>

struct PlayerInfo
{
    int nLives;
    char PlayerChar;
    int nTreasureFound;
    int PositionsEntered[MAX_PATH_LENGTH];
} playerConfig;

struct GameInfo
{
    int nMoves;
    int pathLength;
    int BombPlacement[MAX_PATH_LENGTH];
    int TreasurePlacement[MAX_PATH_LENGTH];
} gameConfig;

int StartIndex = 0,
    EndIndex = PATH_LENGTH_MULTIPLE - 1,
    i;


int main(void)
{
    

    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &playerConfig.PlayerChar);
    
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &playerConfig.nLives);

        if ((playerConfig.nLives < MIN_LIVES) || (playerConfig.nLives > MAX_LIVES))
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
        

    } while ((playerConfig.nLives < MIN_LIVES) || (playerConfig.nLives > MAX_LIVES));
    
    printf("Player configuration set-up is complete\n");

    printf("\nGAME Configuration\n");
    printf("------------------\n");

    

    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ",PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &gameConfig.pathLength);

        

        if ((gameConfig.pathLength % PATH_LENGTH_MULTIPLE != 0) || (gameConfig.pathLength < MIN_PATH_LENGTH || gameConfig.pathLength > MAX_PATH_LENGTH))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n",PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }

    } while ((gameConfig.pathLength % PATH_LENGTH_MULTIPLE != 0) || (gameConfig.pathLength < MIN_PATH_LENGTH || gameConfig.pathLength > MAX_PATH_LENGTH));

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameConfig.nMoves );

        if (gameConfig.nMoves < playerConfig.nLives || gameConfig.nMoves > (int)(0.75 * gameConfig.pathLength))
        {
            printf("    Value must be between %d and %d\n", playerConfig.nLives, (int)(0.75 * gameConfig.pathLength));
        }

    } while (gameConfig.nMoves < playerConfig.nLives || gameConfig.nMoves > (int)(0.75 * gameConfig.pathLength));

    printf("\nBOMB Placement");
    printf("\n--------------");

    printf("\nEnter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", PATH_LENGTH_MULTIPLE ,gameConfig.pathLength);



    for (i = 0; i < gameConfig.pathLength; i++)
        gameConfig.BombPlacement[i] = -1;

    StartIndex = 0;
    EndIndex = PATH_LENGTH_MULTIPLE - 1;

    while (EndIndex <= gameConfig.pathLength)
    {
        printf("   Positions [%2d-%2d]: ", StartIndex + 1, EndIndex + 1);

        int x = StartIndex;

        do
        {
            if (x == EndIndex)
                scanf("%d", &gameConfig.BombPlacement[x]);
            else
                scanf("%d ", &gameConfig.BombPlacement[x]);

            x++;

        } while (x <= EndIndex);


        StartIndex = StartIndex + PATH_LENGTH_MULTIPLE;
        EndIndex = StartIndex + PATH_LENGTH_MULTIPLE - 1;
    }
    
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------");
    
    printf("\nEnter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", PATH_LENGTH_MULTIPLE ,gameConfig.pathLength);
   
    for (i = 0; i < gameConfig.pathLength; i++)
        gameConfig.TreasurePlacement[i] = -1;

    StartIndex = 0;
    EndIndex = PATH_LENGTH_MULTIPLE - 1;

    while (EndIndex <= gameConfig.pathLength)
    {
        printf("   Positions [%2d-%2d]: ", StartIndex + 1, EndIndex + 1);

        int x = StartIndex;

        do
        {
            if (x == EndIndex)
                scanf("%d", &gameConfig.TreasurePlacement[x]);
            else
                scanf("%d ", &gameConfig.TreasurePlacement[x]);

            x++;

        } while (x <= EndIndex);


        StartIndex = StartIndex + PATH_LENGTH_MULTIPLE;
        EndIndex = StartIndex + PATH_LENGTH_MULTIPLE - 1;
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", playerConfig.PlayerChar);
    printf("   Lives      : %d\n", playerConfig.nLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", gameConfig.pathLength);

    printf("   Bombs      : ");
    for (i = 0; i < gameConfig.pathLength; i++)
    {
        printf("%d", gameConfig.BombPlacement[i]);
    }
    
    printf("\n   Treasure   : ");
    for (i = 0; i < gameConfig.pathLength; i++)
    {
        printf("%d", gameConfig.TreasurePlacement[i]);
    }

    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    
    return 0;
}

