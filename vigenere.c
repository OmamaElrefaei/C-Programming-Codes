//Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword).
//Created on Sun November 14 2019.
//@author: Omama Elrefaei.

#include <stdio.h>
#include <string.h> // Used for strlen() function
#include <ctype.h> // Used for isalpha() function

// Directive allows the definition of macros within the source code
#define TRUE 1
#define FALSE 0

// Declare the functions:
void invalid_input(char *input[]);
int input_intTest(char *input[], int test_input);
int shift(char c);
int keywordCounter(int counter, int lenthKeyword);

int main(int argc, char *argv[])
{
    // Unencrypted text:
    char plaintext[100];
    // Integer test variable:
    int intTest;
    int counter = 0;
    int lenthKeyword = 0;

    char *text = NULL;

    intTest = input_intTest(&argv[0], argc);

    if (intTest == FALSE)
    {
        invalid_input(&argv[0]);
        return 1;
    }
    lenthKeyword = strlen(argv[1]);
    printf("plaintext: ");
    scanf(" %[^\n]s", plaintext);

    int i, len;
    for (i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
            int key = shift(argv[1][counter]);
            if (isupper(plaintext[i]))
            {
                plaintext[i] = (((plaintext[i] - 'A') + key) % 26) + 'A';
            }
            else if (islower(plaintext[i]))
            {
                plaintext[i] = (((plaintext[i] - 'a') + key) % 26) + 'a';
            }

            counter = keywordCounter(counter, lenthKeyword);
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}


//invalid_input: Printed a message if the input "key" not non-negative integer:
void invalid_input(char *input[])
{
    printf("Usage: %s %s\n", input[0], "keyword");
}

// input_intTest:  an integer test variable for the "keyword":
int input_intTest(char *input[], int test_input)
{
    int intTest = TRUE; // Sets the default for the integer test variable to TRUE

    if (test_input != 2)
    {
        // Changes intTest variable from TRUE to FALSE
        intTest = FALSE;
        return intTest;
    }
    int i;
    for (i = 1; i < test_input; i++)
    {
        int j, n;
        for (j = 0, n = strlen(input[i]); j < n; j++)
        {
            // Tests the string characters for non-integer value
            if (isdigit(input[i][j]) != 0)
            {
                // Changes intTest variable from TRUE to FALSE and breaks the loop early
                intTest = FALSE;
                i = j = test_input;
                break;
            }
        }

    }
    return intTest;
}

// shift: Convert a single-character into the correct shift value:
int shift(char c)
{
    int shiftValue = 0;
    if (isupper(c))
    {
        shiftValue = c - 'A';
    }
    else
    {
        shiftValue = c - 'a';
    }

    return shiftValue;
}

// keywordCounter: Control the keyword counter:
int keywordCounter(int counter, int lenthKeyword)
{
    counter ++;
    if (counter >= lenthKeyword)
    {
        counter = 0;
    }
    return counter;
}

