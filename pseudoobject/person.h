#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

// Date pseudo object to create a date dd/mm/yy
typedef struct Date
{
    size_t day;
    size_t month;
    size_t year;

    struct Date *(*createDate)(size_t day, size_t month, size_t year);
} Date;

Date *_create_date(size_t day, size_t month, size_t year);


// Person pseudo class with name, date of birth, age method, etc
typedef struct Person
{
    char name[20];
    Date *date_of_birth;

    size_t (*age)(struct Person *selfstruct);

    struct Person *(*createPerson)(char name[20], Date *date);
} Person;

Person *_create_person(char name[20], Date *date);
size_t _calculate_age(Person *p);

#endif