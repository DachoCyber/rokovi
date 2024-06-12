#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int n, int m) {
    int** matrix = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * m);
    }
    return matrix;
}

void enterMatrix(int** matrix, int n, int m) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int checkIfColEq(int** matrix, int n, int m) {
    int indexStart = 0, indexEnd = m - 1;
    while(indexStart < indexEnd) {
        for(int i = 0; i < n; i++) {
            if(matrix[i][indexStart] != matrix[i][indexEnd]) {
                return 0;
            }
        }
        indexStart++;
        indexEnd--;
    }
    return 1;

}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    if(n < 0 || m < 0) {
        printf("-1");
        return 0;
    }

    int** matrix = allocateMatrix(n, m);
    enterMatrix(matrix, n, m);   

    int areEqual = checkIfColEq(matrix, n, m);
    if(areEqual == 1) {
        printf("1");
    }
    else {
        printf("0");
    }

    return 0;
}