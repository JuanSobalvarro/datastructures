/**
 * USAGE:
 * The linked list structure operates as a "pseudo class",
 * allowing you to work with linked lists similarly to classes in other languages.
 * Example:
 * singlyLinkedList ll = createSinglyLinkedList(); // This creates an instance of a linked list
 * ll.insertAt(ll.self, 1, 0); // Inserts the number 1 at position 0
 * ll.deleteAt(ll.self, 0); // Deletes the node at position 0
 * ll.print(ll.self); // Prints the current linked list
 * 
 * Since this is C, not a true class, 
 * you need to free the memory once you're done using the linked list:
 * ll.free(ll.self); // Frees the memory used
 * 
 * !IMPORTANT
 * REMEMBER TO COMPILE YOUR FILE INCLUDING THE singlylinkedlist.h IN YOUR FILE
 * AND ADDING singlylinkedlist.c TO THE COMPILE COMMAND
 * #include "'path'/singlylinkedlist.h"
 * ...
 * 
 * Command: gcc myfile.c (...) 'path'/singlylinkedlist.c
**/
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct singlyLinkedList 
{
    struct singlyLinkedList *self;
    struct node *head;
    int len;

    void (*insertAt)(struct singlyLinkedList* self, int value, int index);
    void (*deleteAt)(struct singlyLinkedList* self, int index);
    void (*print)(struct singlyLinkedList* self);
 
    void (*free)(struct singlyLinkedList* self);
} singlyLinkedList;

singlyLinkedList createSinglyLinkedList();

#ifdef _PRIVATE_

node *createNode(int val);

void insertat(struct singlyLinkedList *ll, int val, int pos);

void deleteat(struct singlyLinkedList *ll, int pos);

void print(struct singlyLinkedList *ll);

void freell(struct singlyLinkedList *ll);

#endif

#endif