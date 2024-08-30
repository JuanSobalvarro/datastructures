#include "bptree.h"

// default order
#define ORDER 3

int order = ORDER;

// simulate data usage in disk
typedef struct 
{
    int value;
} record;

// estructura de nodo
typedef struct
{
    int *keys; // array de valores en el nodo
    struct node **p; // array de punteros children del nodo
    struct node *parent;
    bool isLeaf; // definir en 1 si el nodo es una leaf
    unsigned int num_keys; // 0 cantidad de keys, 1 cantidad de punteros
    struct node *next; // pointer por si es una leaf apunta al siguiente elemento
} node;

// Estructura de arbol. Solo es el nodo de root y en base a este se desarrolla todo el arbol
typedef struct 
{
    node *rootnode;
} BpTree;

// Inicializar nodo y definir si es leaf o no
node *initNode(bool leaf)
{
    node *n = malloc(sizeof(node));
    n->keys = (int *) malloc((order - 1) * sizeof(int));
    n->p = (node **) malloc(order * sizeof(node *));

    n->parent = (void *) 0;
    n->next = (void *) 0;
    n->isLeaf = leaf;
}

// Inicializar arbol.
BpTree *initTree()
{
    BpTree *tree = malloc(sizeof(BpTree)); 
    
    tree->rootnode = initNode(false);

    return tree;
}