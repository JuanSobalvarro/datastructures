#include "person.h"

static size_t _days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date *createDate(size_t day, size_t month, size_t year)
{
    if (year < 0)
    {
        printf("Year must be greater or equal than 0\n");
        return NULL;
    }

    if (month <= 0 || month > 12)
    {
        printf("Month must be between 1 and 12\n");
        return NULL;
    }

    if (day <= 0 || day > _days_per_month[month-1])
    {
        printf("Day must be between 1 and %d (month %d)\n", _days_per_month[month-1], month);
        return NULL;
    }

    Date *date = malloc(sizeof(Date));

    if (!date)
    {
        printf("Couldnt Allocate memory for date\n");
        return NULL;
    }

    date->day = day;
    date->month = month;
    date->year = year;

    return date;
}

Person *createPerson(char *name, Date *date)
{
    Person *person = malloc(sizeof(Person));

    if (!person)
    {
        printf("Couldnt allocate memory for person\n");
        return NULL;
    }

    strcpy(person->name, name);
    person->date_of_birth = date;

    // Assign methods
    person->age = &_calculate_age;

    return person;
}

size_t _calculate_age(Person *p)
{
    Date *birthDate = p->date_of_birth;

    if (!birthDate)
    {
        return -1;
    }

    time_t now;
    time(&now);
    
    // Convert to local time struct
    struct tm *local_time = localtime(&now);

    // Get current year, month, and day
    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;

    // Calculate age
    int age = current_year - birthDate->year;

    // Adjust if the birth date hasnt occurred yet this year
    if (birthDate->month > current_month || (birthDate->month == current_month && birthDate->day > current_day)) 
    {
        age--;
    }

    return age;                                         
}
