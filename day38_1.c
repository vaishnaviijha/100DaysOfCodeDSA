#include <stdio.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1, size = 0;

int isEmpty() {
    return size == 0;
}

int isFull() {
    return size == MAX;
}

void push_front(int x) {
    if (isFull()) return;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = x;
    size++;
}

void push_back(int x) {
    if (isFull()) return;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = x;
    size++;
}

int pop_front() {
    if (isEmpty()) return -1;
    int val = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    size--;
    return val;
}

int pop_back() {
    if (isEmpty()) return -1;
    int val = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
    size--;
    return val;
}

int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

int getSize() {
    return size;
}

void clearDeque() {
    front = rear = -1;
    size = 0;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());

    printf("Pop Front: %d\n", pop_front());
    printf("Pop Back: %d\n", pop_back());

    display();

    printf("Size: %d\n", getSize());

    clearDeque();
    printf("After clear, size: %d\n", getSize());

    return 0;
}