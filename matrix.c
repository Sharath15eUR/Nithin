#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the square matrices (n): ");
    scanf("%d", &n);

    int mat1[n][n], mat2[n][n], result[n][n];

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat2[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Product of the matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", result[i][j]);
        printf("\n");
    }

    return 0;
}
