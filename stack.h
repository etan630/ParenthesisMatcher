#ifndef stack_h
#define stack_h
#include "status.h"


struct stack;
typedef struct stack Stack;

struct stack
{
    char data;
    Stack* next;
};

//standard functions that were discussed during class
void stack_destroy(Stack** phStack);
void stack_push(Stack** pcurrentHead, int value); //head-tail
char stack_pop(Stack** hStack);
char stack_top(Stack* hStack);
Boolean stack_is_empty(Stack* hStack);

//functions specific for this assignment
Boolean isMatching(char front, char back);
Boolean isBalanced(char string[]);



#endif /* stack_h */
