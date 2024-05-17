#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE
{
    int val;
    int *weights;
    int nN; // number of next nodes
    struct NODE **nexts;
} NODE;

NODE *createNode(int val);
int linkNodes(NODE *dest, NODE *new, int weight);

void showNodes();

void showRandomTree();

#endif