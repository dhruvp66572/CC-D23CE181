#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 100

typedef struct
{
    int numStates;
    int numSymbols;
    char symbols[MAX_SYMBOLS];
    int transitionTable[MAX_STATES][MAX_SYMBOLS];
    int initialState;
    int numAcceptingStates;
    int acceptingStates[MAX_STATES];
} FiniteAutomata;

int getSymbolIndex(FiniteAutomata *fa, char symbol)
{
    for (int i = 0; i < fa->numSymbols; i++)
    {
        if (fa->symbols[i] == symbol)
        {
            return i;
        }
    }
    return -1;
}

int isAcceptingState(FiniteAutomata *fa, int state)
{
    for (int i = 0; i < fa->numAcceptingStates; i++)
    {
        if (fa->acceptingStates[i] == state)
        {
            return 1;
        }
    }
    return 0;
}

int validateString(FiniteAutomata *fa, char *inputString)
{
    int currentState = fa->initialState;
    for (int i = 0; i < strlen(inputString); i++)
    {
        int symbolIndex = getSymbolIndex(fa, inputString[i]);
        if (symbolIndex == -1)
        {
            return 0; // Invalid symbol
        }
        currentState = fa->transitionTable[currentState][symbolIndex];
    }
    return isAcceptingState(fa, currentState);
}

int main()
{
    FiniteAutomata fa;
    printf("Number of input symbols: ");
    scanf("%d", &fa.numSymbols);
    printf("Input symbols: ");
    for (int i = 0; i < fa.numSymbols; i++)
    {
        scanf(" %c", &fa.symbols[i]);
    }
    printf("Enter number of states: ");
    scanf("%d", &fa.numStates);
    printf("Initial state: ");
    scanf("%d", &fa.initialState);
    printf("Number of accepting states: ");
    scanf("%d", &fa.numAcceptingStates);
    printf("Accepting states: ");
    for (int i = 0; i < fa.numAcceptingStates; i++)
    {
        scanf("%d", &fa.acceptingStates[i]);
    }
    printf("Transition table:\n");
    for (int i = 0; i < fa.numStates; i++)
    {
        for (int j = 0; j < fa.numSymbols; j++)
        {
            printf("State %d to %c -> ", i, fa.symbols[j]);
            scanf("%d", &fa.transitionTable[i][j]);
        }
    }
    char inputString[100];
    printf("Input string: ");
    scanf("%s", inputString);
    if (validateString(&fa, inputString))
    {
        printf("Valid String\n");
    }
    else
    {
        printf("Invalid String\n");
    }
    return 0;
}