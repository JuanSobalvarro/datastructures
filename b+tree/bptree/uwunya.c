#include "bptree.h"
#include <stdio.h>

int main()
{   
    int array[] = {1,2,3,4,5};
    printf("%d\n", sizeof(array) / sizeof(*array));
    
    BpTree *t = initTree(array);
    return 0;
}