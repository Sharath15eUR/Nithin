#include <stdio.h>

int isSubset(int arr1[], int m, int arr2[], int n) {
    int found;

    for (int i = 0; i < n; i++) {
        found = 0;
        for (int j = 0; j < m; j++) {
            if (arr2[i] == arr1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int m, n;

    printf("Enter the size of the first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter elements of the first array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter elements of the second array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    if (isSubset(arr1, m, arr2, n)) {
        printf("arr2[] is a subset of arr1[]\n");
    } else {
        printf("arr2[] is not a subset of arr1[]\n");
    }

    return 0;
}
