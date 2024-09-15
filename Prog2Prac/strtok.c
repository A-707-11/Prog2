#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "This is a string. This is a simple example.";
    char word[] = "This";
    int count = 0;
    char *ptr = str;

//    // Find the first occurrence of the word
    ptr = strstr(ptr, word);

    while (ptr != NULL) {
        count++;
        ptr = strstr(ptr + 1, word);  // Move to the next occurrence
    }

    printf("The word '%s' appears %d times in the string.\n", word, count);
    printf(strerror(5));

    return 0;
}

