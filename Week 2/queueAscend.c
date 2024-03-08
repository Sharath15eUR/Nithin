#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* temp = newNode(data);
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void sortQueue(struct Node** front, struct Node** rear) {
    struct Node* current = *front;

    while (current != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            if (current->data > temp->data) {
                int tempData = current->data;
                current->data = temp->data;
                temp->data = tempData;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

void printQueue(struct Node* front) {
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    int value;
    printf("Enter the elements of the queue (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        enqueue(&front, &rear, value);
    }

    printf("Input queue: ");
    printQueue(front);

    sortQueue(&front, &rear);

    printf("Output queue: ");
    printQueue(front);

    return 0;
}
