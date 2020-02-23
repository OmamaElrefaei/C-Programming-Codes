//Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend right-aligned pyramid of blocks, a la the below.
//In this program I allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.
//Created on Thur Augast 22 2019.
//@author: Omama Elrefaei.

#include <stdio.h>

int main(void)
{
    //Asked the user How tall the pyramids should be?:
    int Height; 
    printf("How tall the pyramids should be?\n");
    scanf("%d", &Height);

    //To check if the input out of the range:
    while (Height <= 0 || Height > 8)
    {
        printf("please choose an integer number between 1 and 8\n");   
        scanf("%d", &Height);
    }
        
    //Building the pyramids:
    int i;
    for (i = 1; i <= Height; i++)
    {
        //For the first space before the first block:
        int j;
        for (j = Height; j > i; j--)
        {    
            printf(" ");
        }
        //For the first block:
        for (j = 1; j <= i; j++)
        {    
            printf("#");
        }   
        //For new line:
        printf("\n");    
    }
}
