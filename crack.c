//Cracks passwords.
//Created on Sun November 14 2019.
//@author: Omama Elrefaei.

#include <cs50.h>   //CS50 Library for C created by: Glenn Holloway <holloway@eecs.harvard.edu>, David J. Malan <malan@harvard.edu>.
#include <stdio.h>
#include <crypt.h>  // Used for crypt() function
#include <string.h> 
#include <time.h> 

// Directive allows the definition of macros within the source code
#define TRUE 1
#define FALSE 0
#define _XOPEN_SOURCE // Needed for the crypt function to work.

char *randstring(int length);
int main(int argc, string argv[])
{
    string hash = argv[1];

    if (argc != 2)
    {
        printf("Usage: %s %s\n", argv[0], "hash");
        return 1;
    }
    int testKey = FALSE;
    while (testKey == FALSE)
    {

        char salt[3] = {hash[0], hash[1], '\0'};
        char *key;
        for (int i =  1 ; i < 6; i++)
        {
            key = randstring(i);
            if (strcmp(hash, crypt(key, salt)) == 0)
            {
                printf("%s\n", key);
                break;
            }
        }
        testKey = TRUE;
    }
    return 0;
}

char *randstring(int length)
{
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //size_t is an unsigned integral data type which can be a bit faster than int
    size_t stringLen = 26 * 2;
    char *randomString;

    randomString = malloc(sizeof(char) * (length + 1));

    if (!randomString)
    {
        return (char *)0;
    }

    int key = 0;
    for (int n = 0; n < length; n++)
    {
        // rand() function is used to generate random numbers
        key = rand() % stringLen;
        randomString[n] = string[key];
    }

    randomString[length] = '\0';

    return randomString;
}

//The DES algorithm itself has a few quirks which make the use of the crypt() interface a very  poor choice for anything other than password authentication.
