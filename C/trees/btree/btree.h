/**
 * USAGE:
 * The binary tree structure operates as a "pseudo class",
 * allowing you to work with binary trees similarly to classes in other languages.
 * Example:
 * binarytree bt = BinaryTree(); // This creates an instance of a binary tree
 * bt.insert(&bt, 1); // Inserts the number 1 into the tree
 * bt.delete(&bt, 1); // Deletes the number 1 from the tree
 * bt.print(&bt); // Prints the tree in-order
 * 
 * Since this is C, not a true class, 
 * you need to free the memory once you're done using the tree:
 * bt.free(&bt); // Frees the memory used
 * 
 * !IMPORTANT
 * REMEMBER TO COMPILE YOUR FILE INCLUDING THE binarytree.h IN YOUR FILE
 * AND ADDING binarytree.c TO THE COMPILE COMMAND
 * #include "'path'/binarytree.h"
 * ...
 * 
 * Command: gcc myfile.c (...) 'path'/binarytree.c
**/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
} treenode;

typedef struct binarytree 
{
    struct binarytree *self;
    struct treenode *root;

    void (*insert)(struct binarytree*, int);
    void (*delete)(struct binarytree*, int);
    void (*print)(struct binarytree*);

    void (*free)(struct binarytree*);
} binarytree;

binarytree BinaryTree();

#ifdef _PRIVATE_

treenode *createTreeNode(int val);

void insert(struct binarytree *bt, int val);

void deleteTree(struct binarytree *bt, int val);

void printTree(struct binarytree *bt);

void freeTree(struct binarytree *bt);

#endif

#endif
