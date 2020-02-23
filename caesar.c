//Caesar algorithm: encrypts messages by rotating each letter by k positions.
//Created on Sun November 9 2019.
//@author: Omama Elrefaei.

#include <stdio.h> 
#include <stdlib.h> // Used for atoi() function
#include <string.h> // Used for strlen() function
#include <ctype.h>  // Used for isalpha() function

// Directive allows the definition of macros within the source code
#define TRUE 1
#define FALSE 0

// Declare the functions:
void invalid_input(char *input[]);
int input_intTest(char *input[], int input_test);
char *ciphertext(char plaintext[100], char *input[]);

char *crypt(const char *key, const char *salt);

int main(int argc, char *argv[])
{

    // Unencrypted text:
    char plaintext[100];
    // Integer test variable:
    int intTest;

    intTest = input_intTest(&argv[0], argc);

    if (intTest == FALSE)
    {
        invalid_input(&argv[0]);
        return 1;
    }
    printf("plaintext: ");
    scanf(" %[^\n]s", plaintext);
    // space befor "%[^\n]s" tell the buffer if there is any character lefted from previous line ignore it

    // Encrypted text:
    char *text = ciphertext(plaintext, &argv[0]);
    printf("ciphertext: %s\n", text);

    return 0;
}

//invalid_input: Printed a message if the input "key" not non-negative integer:
void invalid_input(char *input[])
{
    printf("Usage: %s %s\n", input[0], "key");
}

// input_intTest: an integer test variable for the "key":
int input_intTest(char *input[], int input_test)
{
    int intTest = TRUE; // Sets the default for the integer test variable to TRUE
    if (input_test != 2)
    {
        // Changes intTest variable from TRUE to FALSE
        intTest = FALSE;
        return intTest;
    }
    int i;
    for (i = 1; i < input_test; i++)
    {
        int j, n;
        for (j = 0, n = strlen(input[i]); j < n; j++)
        {
            // Tests the string characters for non-integer value
            if (input[i][j] < '0' || input[i][j] > '9')
            {
                // Changes intTest variable from TRUE to FALSE and breaks the loop early
                intTest = FALSE;
                i = j = input_test;
                break;
            }
        }
    }
    return intTest;
}

//ciphertext: returns encrypts messages:
char *ciphertext(char plaintext[100], char *input[])
{
    // Converts the string to an integer:
    if (strlen(input[1]) > 4)
    {
        return 0;
    }

    int k = atoi(input[1]);

    if (k > 255)
    {
        return 0;
    }

    int i, len;
    for (i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] - 'A') + k) % 26) + 'A';
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] - 'a') + k) % 26) + 'a';
        }

    }
    return plaintext;
}
