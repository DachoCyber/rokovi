#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int numOfCapitalLet(const char* line) {
    int num = 0;
    for(int i = 0; i < strlen(line); i++) {
        if(isupper(line[i])) num++;
    }
    return num;
}

int cmp(const void* line1, const void* line2) {
    int num1 = numOfCapitalLet(*(const char**)line1);
    int num2 = numOfCapitalLet(*(const char**)line2);
    return num1 - num2; // sort in ascending order
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("-1\n");
        return 1;
    }
    
    FILE* fin = fopen(argv[1], "r");
    if(fin == NULL) {
        printf("-1\n");
        return 1;
    }

    char* arrayOfLines[100];
    int numOfLines = 0;
    char line[50];

    while(fgets(line, sizeof(line), fin) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        arrayOfLines[numOfLines] = malloc(strlen(line) + 1);
        if(arrayOfLines[numOfLines] == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation error\n");
            fclose(fin);
            for(int j = 0; j < numOfLines; j++) {
                free(arrayOfLines[j]);
            }
            return 1;
        }
        strcpy(arrayOfLines[numOfLines], line);
        numOfLines++;
    }

    fclose(fin);

    qsort(arrayOfLines, numOfLines, sizeof(char*), cmp);
    for(int i = 0; i < numOfLines; i++) {
        printf("%s\n", arrayOfLines[i]);
    }

    int b;
    if(scanf("%d", &b) != 1) {
        printf("-1\n");
        for(int i = 0; i < numOfLines; i++) {
            free(arrayOfLines[i]);
        }
        return 1;
    }

    int found = 0;
    for(int i = 0; i < numOfLines; i++) {
        if(numOfCapitalLet(arrayOfLines[i]) == b) {
            printf("%s\n", arrayOfLines[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No line found with %d capital letters.\n", b);
    }

    for(int i = 0; i < numOfLines; i++) {
        free(arrayOfLines[i]);
    }

    return 0;
}
