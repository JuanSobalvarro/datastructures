# Linked Lists

## Overview

A linked list is a linear data structure where each element (node) points to the next element. Unlike arrays, linked lists do not require contiguous memory and can easily grow or shrink in size.

### Types of Linked Lists
- **Singly Linked List**: Each node points to the next node.
- **Doubly Linked List**: Each node points to both the next and the previous nodes.
- **Circular Linked List**: The last node points back to the first node.

## Implementation Details

### Singly Linked List
- **Node Structure**: Each node contains data and a pointer to the next node.
- **Operations**: Insert, Delete, Search, Traverse.

### Doubly Linked List
- **Node Structure**: Each node contains data, a pointer to the next node, and a pointer to the previous node.
- **Operations**: Insert, Delete, Search, Traverse.

### Circular Linked List
- **Node Structure**: Similar to singly or doubly linked lists, but the last node points back to the first node.

## Example Usage

```c
// Example of creating and using a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Traversing the linked list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}