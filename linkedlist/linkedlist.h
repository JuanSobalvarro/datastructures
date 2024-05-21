/**
 * USAGE:
 * The linked list structure operates as a "pseudo class",
 * allowing you to work with linked lists similarly to classes in other languages.
 * Example:
 * linkedlist ll = LinkedList(); // This creates an instance of a linked list
 * ll.insertAt(ll.self, 1, 0); // Inserts the number 1 at position 0
 * ll.deleteAt(ll.self, 0); // Deletes the node at position 0
 * ll.print(ll.self); // Prints the current linked list
 * 
 * Since this is C, not a true class, 
 * you need to free the memory once you're done using the linked list:
 * ll.free(ll.self); // Frees the memory used
 * 
 * !IMPORTANT
 * REMEMBER TO COMPILE YOUR FILE INCLUDING THE linkedlist.h IN YOUR FILE
 * AND ADDING linkedlist.c TO THE COMPILE COMMAND
 * #include "'path'/linkedlist.h"
 * ...
 * 
 * Command: gcc myfile.c (...) 'path'/linkedlist.c
**/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linkedlist 
{
    struct linkedlist *self;
    struct node *head;
    int len;

    void (*insertAt)(struct linkedlist*, int, int);
    void (*deleteAt)(struct linkedlist*, int);
    void (*print)(struct linkedlist*);

    void (*free)(struct linkedlist*);
} linkedlist;

linkedlist LinkedList();

#ifdef _PRIVATE_

node *createNode(int val);

void insertat(struct linkedlist *ll, int val, int pos);

void deleteat(struct linkedlist *ll, int pos);

void print(struct linkedlist *ll);

void freell(struct linkedlist *ll);

#endif

#endif