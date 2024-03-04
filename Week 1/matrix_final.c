#include <stdio.h>

void multiplyMatrices(int *mat1, int *mat2, int *result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(result + i * n + j) = 0;
            for (int k = 0; k < n; k++) {
                *(result + i * n + j) += (*(mat1 + i * n + k)) * (*(mat2 + k * n + j));
            }
        }
    }
}

void displayMatrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", *(matrix + i * n + j));
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the matrices (n): ");
    scanf("%d", &n);

    int matrix1[n][n], matrix2[n][n], resultMatrix[n][n];

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    multiplyMatrices(&matrix1[0][0], &matrix2[0][0], &resultMatrix[0][0], n);

    printf("Resultant matrix after multiplication:\n");
    displayMatrix(&resultMatrix[0][0], n);

    return 0;
}
