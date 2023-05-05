#include <stdio.h>

#define n 5 //n là kích thước ma trận input
static void initMatrix();
static void printMatrix();
static void rotate_matrix();
static int A[n][n]; 

int main(void){
    initMatrix();
    printMatrix();
    rotate_matrix();
    printMatrix();
    return 0;
}


static void initMatrix(){
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = n*i + j + 1;
        }
    }
}

static void printMatrix(){
    int i, j;

    printf("Matrix\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void rotate_matrix(){
    int i, j;

    for(i = 0; i < n/2; i++){
        for(j = i; j < n - i - 1; j++){
            int tmp = A[i][j];

            A[i][j] = A[n - j - 1][i];
            A[n - j - 1][i] = A[n - i- 1][n - j - 1];
            A[n - i - 1][n - j - 1] = A[j][n - i - 1];
            A[j][n - i - 1] = tmp;
        }
    }
}