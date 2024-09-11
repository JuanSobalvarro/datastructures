#include <stdio.h>

int main()
{
    int *head = malloc(sizeof(int) * 5);

    int *uwu = head;
    for (int i = 0; i < 5; i++)
    {
        *uwu = i;
        printf("%d\n", *uwu);
        uwu++;
    }

    head = (int *) realloc(head, sizeof(int) * 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%p\n", *head);
        head++;
    }


    free(head);
    return 0;
}