#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* newNode(char data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(struct Node** top, char data) {
    struct Node* temp = newNode(data);
    temp->next = *top;
    *top = temp;
}

char pop(struct Node** top) {
    if (*top == NULL) {
        return '\0';
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

void reverseString(char* str) {
    int length = strlen(str);
    struct Node* stack = NULL;

    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}
