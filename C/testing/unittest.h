#ifndef UNITTEST_H
#define UNITTEST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int test_count = 0;

void assert(void* first_val, void* second_val)
{
    printf("=====================Test %d=====================\n", test_count + 1);
    test_count++;
    if (first_val == second_val)
    {
        printf("Ok!\n");
        return;
    }

    printf("Not ok:(\n");
    printf("First Value: %d\nSecond Value: %d\n", first_val, second_val);
}


#endif