#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
    char fname[20];
    char lname[20];
    char mi;
    int age;
    char gender;
} personRecords, *persondetails;

void displayRecords(persondetails *p);

persondetails* getMale(persondetails *people, int arraysize, int *maleCount) {
    int i;
    persondetails* males = NULL;
    *maleCount = 0;

    for (i = 0; i < arraysize; i++) {
        if (people.gender == 'M') {
            males = realloc(males, (*maleCount + 1) * sizeof(persondetails));
            males[*maleCount] = &people[i];
            (*maleCount)++;
        }
    }

    return males;
}

int main() {
    int count = 4;
    int i;
    personRecords p1[4] = {
        {.fname = "John", .lname = "Doe", .mi = 'J', .age = 30, .gender = 'M'},
        {.fname = "Jane", .lname = "Smith", .mi = 'S', .age = 25, .gender = 'F'},
        {.fname = "Bob", .lname = "Johnson", .mi = 'B', .age = 40, .gender = 'M'},
        {.fname = "Simon", .lname = "Stan", .mi = 'Q', .age = 22, .gender = 'M'}
    };

    int maleCount;
    persondetails* males = getMale(p1, count, &maleCount);

    printf("Male Persons:\n");
    for (i = 0; i < maleCount; i++) {
        printf("    First Name:    %s\n", males[i]->fname);
        printf("     Last Name:    %s\n", males[i]->lname);
        printf("Middle Initial:    %c\n", males[i]->mi);
        printf("           Age:    %d\n", males[i]->age);
        printf("        Gender:    %c\n\n", males[i]->gender);
    }

    // Free the dynamically allocated memory
    free(males);

    return 0;
}


