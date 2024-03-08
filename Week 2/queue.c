#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

int countElements(struct Queue* queue) {
    int count = 0;
    struct Node* current = queue->front;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }

    struct Node* temp = queue->front;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    printf("Initialize a queue!\n");
    printf("Check the queue is empty or not? ");
    if (isEmpty(&queue)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    printf("Number of elements in queue: %d\n", countElements(&queue));

    int numElements, element;
    printf("Insert some elements into the queue:\n");
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    printf("Enter the elements: ");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        enqueue(&queue, element);
    }

    printf("Queue elements are: ");
    printQueue(&queue);
    printf("Number of elements in queue: %d\n", countElements(&queue));

    int numDequeue;
    printf("Delete some elements from the said queue:\n");
    printf("Enter the number of elements to delete: ");
    scanf("%d", &numDequeue);

    for (int i = 0; i < numDequeue; i++) {
        dequeue(&queue);
    }

    printf("Queue elements are: ");
    printQueue(&queue);
    printf("Number of elements in queue: %d\n", countElements(&queue));

    printf("Insert another element into the queue:\n");
    printf("Enter the element: ");
    scanf("%d", &element);
    enqueue(&queue, element);

    printf("Queue elements are: ");
    printQueue(&queue);
    printf("Number of elements in the queue: %d\n", countElements(&queue));

    return 0;
}
