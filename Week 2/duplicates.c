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

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    if (current == NULL || current->next == NULL) {
        return;
    }

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list in sorted order:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Input linked list: ");
    printList(head);

    removeDuplicates(head);

    printf("Output linked list: ");
    printList(head);

    return 0;
}
