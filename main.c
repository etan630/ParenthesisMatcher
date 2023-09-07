#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, const char * argv[]) {
    char string[100]; //this is for the string of parenthesis
    int userLines; //how many lines the user wants to test
    int i;
    
    printf("How many lines do you want to test?\n");
    scanf("%d", &userLines);

    getchar(); //to get input and put into stdin lib
    
    for (i = 0; i < userLines; i++)
    {
        fgets(string, 100, stdin); //to get a string of parenthesis for each line user wants

        if (isBalanced(string)) //if it is balanced and matched, it will return yes
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
