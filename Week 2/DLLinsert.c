#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

struct Node* insertSorted(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int value;

    printf("Enter values for the doubly linked list (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        head = insertSorted(head, value);
    }

    printf("Doubly linked list: ");
    printList(head);

    printf("Enter a value to insert: ");
    scanf("%d", &value);

    head = insertSorted(head, value);

    printf("Doubly linked list after insertion: ");
    printList(head);

    return 0;
}
