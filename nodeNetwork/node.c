#include "node.h"

int currentNode = 0;

NODE *createNode(int val)
{
    NODE *n = (NODE*) malloc(sizeof(NODE));

    if (n == NULL)
    {
        printf("ERROR::CREATE NODE::ALLOCATING NODE IN MEMORY\n");
        return NULL;
    }

    n->val = val;

    n->nexts = NULL;
    n->weights = NULL;
    n->nN = 0;
}

int linkNodes(NODE *dest, NODE *new, int weight)
{
    if (dest == NULL || new == NULL)
    {
        printf("ERROR::LINKING NODES::ONE NODE IS NULL\n");
        return 0;
    }

    dest->nexts = (NODE**) realloc(dest->nexts, (++dest->nN));
    dest->nexts[dest->nN-1] = new;

    dest->weights = (int*) realloc(dest->weights, dest->nN);
    dest->weights[dest->nN-1] = weight;
}

void printTab(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t");
    }
}

void printNextNodes(NODE *n, int nTab)
{
    if (n == NULL)
    {
        return;
    }
    for (int i = 0; i < n->nN; i++)
    {
        printTab(nTab);
        printf("N val: %d with weight %d\n", n->nexts[i]->val, n->weights[i]);
        printNextNodes(n->nexts[i], nTab+1);
    }
}

// show all nodes in a tabulated format, from a seed Node
void showNodes(NODE *seed)
{
    printf("Seed Node: %d\n", seed->val);
    printNextNodes(seed, 1);
}

void generateNexts(NODE *n)
{
    int nodes = rand()%3;
    if (currentNode == 1 && nodes == 0)
    {
        nodes += 1;
    }
    for (int i = 0; i < nodes; i++)
    {
        NODE *kk = createNode(currentNode++);
        linkNodes(n, kk, rand()%10+1);
        generateNexts(kk);
    }
}

void freeNodes(NODE *seed)
{
    if (seed == NULL)
    {
        return;
    }

    for (int i = 0; i < seed->nN; i++)
    {
        freeNodes(seed->nexts[i]);
    }

    free(seed);
}

void showRandomTree()
{
    srand(time(NULL));

    NODE *seed = createNode(currentNode++);
    generateNexts(seed);

    showNodes(seed);

    freeNodes(seed);
}