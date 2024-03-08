#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(char data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

struct Node* rotateDoublyLinkedList(struct Node* head, int N) {
    if (head == NULL || N <= 0) {
        return head;
    }

    struct Node* current = head;
    int count = 1;

    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return head;
    }

    struct Node* newHead = current->next;
    struct Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = head;
    head->prev = tail;

    newHead->prev = NULL;
    current->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c  ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* current = NULL;
    char value;
    int N;

    printf("Enter the elements of the doubly linked list (enter '0' to stop):\n");
    while (1) {
        scanf(" %c", &value);
        if (value == '0') {
            break;
        }
        if (head == NULL) {
            head = newNode(value);
            current = head;
        } else {
            current->next = newNode(value);
            current->next->prev = current;
            current = current->next;
        }
    }

    printf("Enter the value of N for rotation: ");
    scanf("%d", &N);

    printf("Input linked list: ");
    printList(head);

    head = rotateDoublyLinkedList(head, N);

    printf("Output linked list: ");
    printList(head);

    return 0;
}
