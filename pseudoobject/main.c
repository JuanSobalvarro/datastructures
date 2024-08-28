/*
* You can compile the main.c to test this pseudo Object person example
* HOWTO COMPILE: gcc main.c -o example.exe person.c
*/
#include <stdio.h>

#include "person.h"

int main()
{
    // Person & Date general "object"
    Person person;
    Date date;

    Person *juan = person.createPerson("Juan", date.createDate(23, 8, 2004));
    Person *esther = person.createPerson("Esther", date.createDate(12, 2, 2005));

    Person *people[2] = {juan, esther};

    for (int i = 0; i < 2; i++)
    {
        printf("%s is %d years old\n", people[i]->name, people[i]->age(people[i]));
        free(people[i]->date_of_birth);
        free(people[i]);
    }

    return 0;
}