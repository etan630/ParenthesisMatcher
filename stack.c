#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void stack_destroy(Stack** phStack)
{
    Stack* iterator = *phStack; //need to cast the iterator to the original stack
    Stack* temp; //to free next and stuff
    
    while(iterator != NULL) //freeing everything in the function
    {
        temp = iterator->next;
        free(iterator);
        iterator = temp;
    }
    *phStack = NULL;
}



void stack_push(Stack** pcurrentHead, int value)
{
    //creating new node
    Stack *pNewNode = NULL;
    pNewNode = (Stack*)malloc(sizeof(Stack));
    if (pNewNode == NULL) //testing if pNewNode malloced correctly
    {
        printf("malloc failed in head insert - exiting...\n");
        exit(1);
    }
      /* from class */
    //set data
    pNewNode->data = value;
    
    //connect nodes - set next
    pNewNode->next = *pcurrentHead;
    
    
    //new head is now the newNode
    *pcurrentHead = pNewNode;
    
}


//didn't make this a Status function and want it to return char because want to check for parenthesis -- essentially want to take parenthesis and then remove it after its checked
char stack_pop(Stack** hStack)
{
    Stack* temp = *hStack;
    char parenthesis;
    //exit if there is nothing in the stack to pop
    if (stack_is_empty(*hStack))
    {
        printf("error, nothing to pop\n");
        exit(1);
    }
    //case if there are things to pop in the stack
    else
    {
        parenthesis = temp->data; //want to check the parenthesis here and then remove it
        *hStack = temp->next;
        free(temp); //free what is not needed anymore
        return parenthesis;
    }
}

/*ultimately dont end up using this function*/
char stack_top(Stack* hStack)
{
    Stack* pStack = (Stack*)hStack;
    
    if (!stack_is_empty(hStack))
    {
        return pStack->data;
    }
    
    return -99;
}


/* true or false where false is 0 and true is 1
 used pStack == NULL because want to check if the stack is empty
 */
Boolean stack_is_empty(Stack* hStack)
{
    Stack* pStack = (Stack*)hStack;
    return (pStack == NULL);
}


//functions specific for this assignment
Boolean isMatching(char front, char back) //this function checks if the corresponding parenthesis match each other
{
    if ((front == '(' && back == ')') || (front == '[' && back == ']') || (front == '{' && back == '}')) //Needs to have them match to return true
    {
        return TRUE;
    }
     //if not matching its false
    return FALSE;
}



Boolean isBalanced(char string[])
{
    int index = 0; //want to iterate between each parenthesis
    Stack* stack = NULL;
    
    /*
     logic behind function:
     -- so given a user input string of parenthesis ()[]{}, you want to check it as its added to a stack
     -- as the parenthesis are being added, want to check if there is a matching parenthesis in there as well -- and if it is matching, it will use the pop function to take it out to be able to compare the next set
     -- this sets it up so that essentially, if the parenthesis is correct and true, the stack should theoretically be empty(NULL)
     */
    
    while (string[index] != '\0') //while didnt reach null terminator
    {
        if (string[index] == '{' || string[index] == '(' || string[index] == '[')
        {
            stack_push(&stack, string[index]);
        } //adding front of parenthesis to the stack
        if (string[index] == '}' || string[index] == ')' || string[index] == ']')
        { //testing for back of parenthesis
            if (stack == NULL) //if there was no front parenthesis -- nothing would have been added to stack, so it wouldnt be balanced --> not necessary to check if its matching because its already known it isnt matched
            {
                return FALSE;
            }
            else if(!isMatching(stack_pop(&stack), string[index])) //if the parenthesis are not the same it will return false; however, if its true the return False won't run and function will continue running; and since its stack_pop itll remove from stack what was just tested
            {
                return FALSE;
            }
        }
        index++;
    }
    
    //as stated earlier, according to function logic this will return NULL if its correct
    if (stack == NULL)
    {
        stack_destroy(&stack); //to free stack made
        return TRUE;
    }
    else
    {
        stack_destroy(&stack);
        return FALSE;
    }
}
