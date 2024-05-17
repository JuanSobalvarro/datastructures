#include "b+tree2.c"
#include <stdio.h>

int main()
{   
    int array[] = {1,2,3,4};
    int size = sizeof(array) / sizeof(int);
    printf("%d\n",size);
    maketree(size, array);
    return 0;
}