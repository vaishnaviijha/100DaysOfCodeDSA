//QUESTION 1

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1, size;


int isFull() {
    return (front == (rear + 1) % size);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    int value = queue[front];
    printf("Deleted: %d\n", value);

    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % size;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}


int main() {
    int choice, value;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;

            case 2:
                dequeue();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

//QUESTION 2
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int data[MAX];       
int priority[MAX];   
int size = 0;


void insert(int value, int pr) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    
    while (i >= 0 && priority[i] > pr) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }

    data[i + 1] = value;
    priority[i + 1] = pr;
    size++;

    printf("Inserted element %d with priority %d\n", value, pr);
}


void delete() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d (Priority: %d)\n", data[0], priority[0]);

    
    for (int i = 1; i < size; i++) {
        data[i - 1] = data[i];
        priority[i - 1] = priority[i];
    }

    size--;
}


void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Element\tPriority\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\n", data[i], priority[i]);
    }
}


int main() {
    int choice, value, pr;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete (Highest Priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &pr);
                insert(value, pr);
                display();
                break;

            case 2:
                delete();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


