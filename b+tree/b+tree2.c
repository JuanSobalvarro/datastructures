#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *val; // array de valores en el nodo
    void **p; // array de punteros del nodo
    int size[2]; // 0 cantidad de valores, 1 cantidad de punteros 
} node;

typedef struct 
{
    node *rootnode;
} BpTree;

BpTree *maketree(int size, int array[])
{
    /*
    2 valores minimos de root iniciales para crear los rootnodes
    */
    BpTree *uwu = malloc(sizeof(BpTree)); // referencia al tree

    uwu->rootnode->val = array;
    uwu->rootnode->p = malloc(sizeof(void) * (size + 1));
    uwu->rootnode->size[0] = size;
    uwu->rootnode->size[1] = size + 1;

    return uwu;
}