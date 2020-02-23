//Greedy Algorithm.
//A program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.
//Created on Sun Augast 31 2019.
//@author: Omama Elrefaei.

#include <stdio.h>
#include <math.h>
#include <ctype.h>  // Used for isdigit() function
#include <string.h> // Used for strlen() function
#include <stdlib.h> // Used for atoi() function

// Directive allows the definition of macros within the source code
#define TRUE 1
#define FALSE 0

int input_intTest(char input[100]);

int main(void)
{
    char input[100];
    float Change = 0.0;
    char *C;

    //Ask the user how much change is owed:
    printf("How much change is owed? \n");
    scanf("%[^\n]s", input);

    int intTest = input_intTest(input);

    if (intTest == TRUE)
    {
        Change = strtof(input, &C);
        printf("Change owed: %.2f\n", Change);
    }

    while (intTest == FALSE)
    {
        printf("How much change is owed? \n");
        scanf(" %[^\n]s", input);
        intTest = input_intTest(input);
        
    }
    while (Change < 0)
    {
        printf("How much change is owed? \n");
        scanf(" %[^\n]s", input);
        Change = strtof(input, &C);
        printf("Change owed: %.2f\n", Change);
        
    }


    //Count the minimum number of coins possible:
    int Cents = round(Change * 100);
    int MinNumOfCoins = 0;
    
    if (Cents >= 25)
    {
        MinNumOfCoins += (int)(Cents / 25);
        Cents %= 25;
    }
    
    //Numbers of Dimes:
    if (Cents < 25 && Cents >= 10)
    {
        MinNumOfCoins += (int)(Cents / 10);
        Cents %= 10;
    }
    
    //Numbers of Nickels:
    if (Cents < 10 && Cents >= 5)
    {
        MinNumOfCoins += (int)(Cents / 5);
        Cents %= 5;
    }
    
    //Numbers of Pennies:
    if (Cents < 5)
    {
        MinNumOfCoins += Cents;
    } 
 
    printf("%i\n", MinNumOfCoins);  
    return 0;
}

//Check If the user fails to provide a number:
int input_intTest(char input[100])
{
    int intTest; 
    int i, len;
    for (i = 0, len = strlen(input); i < len; i++)
    {
        if (isdigit(input[i]))
        {
            intTest = TRUE;
        }
        else
        {
            intTest = FALSE;
            break;
        }

    }
    return intTest;
}