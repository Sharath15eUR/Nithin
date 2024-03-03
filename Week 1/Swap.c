#include <stdio.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    void (*swapptr)(int *, int *) = swap; 

    swapptr(&a, &b);

    printf("Swapped numbers: %d %d", a, b);

    return 0;
}
