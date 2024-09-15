#include <stdio.h>
#include <string.h>

typedef struct {
    int age;
    char name[20];
    int id;
    char sex;
} STUDENT;

int main()
{
    FILE *fileptr = fopen("sample.txt", "rb");
    STUDENT s;

    while (fread(&s, sizeof(STUDENT), 1, fileptr) == 1) {
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("ID: %d\n", s.id);
        printf("Sex: %c\n", s.sex);
        printf("\n");
    }

    fclose(fileptr);
    return 0;
}

