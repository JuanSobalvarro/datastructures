/**
 * USAGE:
 * The stack structure works as a "pseudo class",
 * it is just a structure that can be used as we use classes in other languages
 * Example: 
 * stack s = Stack(); // this creates a instance of a stack structure
 * s.push(&s, 1); // Add the number 1 to the top of our stack
 * s.pop(&s); // Eliminates the top node of the stack
 * s.print(&s); // prints the current stack
 * 
 * Since we are in C, it is not a class, 
 * so you should free the memory once you are finished working with the stack:
 * s.free(&s); // free memory used
 * 
 * !IMPORTANT
 * REMEMBER TO COMPILE YOUR FILE INCLUDING THE stack.h IN YOUR FILE
 * AND ADDING stack.c TO THE COMPILE COMMAND
 * #include "'path'/stack.h"
 * ...
 * 
 * command: gcc myfile.c (...) 'path'/stack.c
**/
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{
    int val;
    struct node *next_node;
} node;

/*
 * Top node will always be the one at the s->len-1
*/
typedef struct stack 
{
    struct stack *self;
    struct node *top_node;
    int len;
    
    // PUSHES A VALUE ON THE TOP OF THE STACK
    void (*push)(struct stack*, int);
    
    // POPS(ELIMINATES) A VALUE FROM THE TOP OF THE STACK
    void (*pop)(struct stack*);
    
    // PRINTS THE STACK
    void (*print)(struct stack*);
    
    // FREES THE STACK
    void (*free)(struct stack*);
} stack;

stack Stack();

#ifdef _PRIVATE_

node createNode(int val);

void push(stack *s, int value);
void pop(stack *s);

void printStack(stack *s);

void freeStack(stack *s);

#endif

#endif