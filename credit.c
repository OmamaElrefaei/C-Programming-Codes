//Luhn’s Algorithm.
//Created on Thur Augast 22 2019.
//@author: Omama Elrefaei.
//A program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein
#include <stdio.h>
#include <math.h>
#include <ctype.h>  // Used for isdigit() function
#include <string.h> // Used for strlen() function
#include <stdlib.h> // Used for strtol() function

// Directive allows the definition of macros within the source code
#define TRUE 1
#define FALSE 0

int input_intTest(char input[100]);

int main(void)
{
    char input[100];
    long long Number; // [−9,223,372,036,854,775,807, +9,223,372,036,854,775,807] range 64 bits in size
    char *eptr;

    //Ask the user for the credit card number:
    printf("Please enter your credit card number: \n");
    scanf("%[^\n]s", input);

    int intTest = input_intTest(input);

    if (intTest == TRUE)
    {
        // Converts char array to a long long:
        Number = strtoll(input, &eptr, 10);
        //Print out the number:
        printf("Number: %lli\n", Number);
    }

    while (intTest == FALSE)
    {
        printf("How much change is owed? \n");
        scanf(" %[^\n]s", input);
        intTest = input_intTest(input);

    }

    //Count the digits of the input numbers:
    long long Value = Number;
    int Count = 0;
    while (Value > 1)
    {
        Value /= 10;
        ++Count;
    }

    //Check if inputs are credit card numbers:
    if (Count >= 13)
    {
        //Count the weight of the credit card numbers:
        long long Weight = powl(10, Count - 1);

        //Determine the first start number:
        int FristOneDigit = (int)((Number) / (Weight));
        //Determine the first two start numbers:
        int FristTwoDigit = (int)((Number) / (Weight / 10));

        //Tmplement Luhn’s Algorithm:
        int CheckLuhn = 0;
        long long CardNum = Number;
        int NonMultiDigit = 0;
        int MultiDigit = 0;

        int Digits;
        for (Digits = 1 ; Digits <= Count ; ++ Digits)
        {
            NonMultiDigit = CardNum % 10;
            CardNum /= 10;
            MultiDigit = CardNum % 10;
            CheckLuhn += (int)((MultiDigit * 2) / 10) + ((MultiDigit * 2) % 10) + NonMultiDigit;
            CardNum /= 10;
        }

        if (CheckLuhn % 10 == 0)
        {
            //American Express uses 15-digit numbers and start with 34, 37:
            if (Count == 15)
            {
                if (FristTwoDigit == 34 || FristTwoDigit == 37)
                {
                    printf("AMEX\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }

            //MasterCard uses 16-digit numbers and start with 51, 52, 53, 54, or 55:
            //VISA uses 16-digit numbers and start with 4:
            else if (Count == 16)
            {
                if (FristTwoDigit == 51 || FristTwoDigit == 52 || FristTwoDigit == 53 || FristTwoDigit == 54 || FristTwoDigit == 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (FristOneDigit == 4)
                {
                    printf("VISA\n");
                }

                else
                {
                    printf("INVALID\n");
                }

            }
            //Visa uses 13- and 16-digit numbers and start with 4:
            else if (Count == 13 || Count == 16)
            {
                if (FristOneDigit == 4)
                {
                    printf("VISA\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }
        }
        //The inputs that are not credit card numbers:
        else
        {
            printf("INVALID\n");
        }

    }
    //The inputs that are not credit card numbers:
    else
    {
        printf("INVALID\n");
    }

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

        }
    }
    return intTest;
}
