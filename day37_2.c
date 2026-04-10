#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

int heap[MAX];
int size = 0;
int k;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int val) {
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}

void removeMin() {
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void init(int K, int nums[], int n) {
    k = K;
    for (int i = 0; i < n; i++) {
        insert(nums[i]);
        if (size > k) {
            removeMin();
        }
    }
}

int add(int val) {
    insert(val);
    if (size > k) {
        removeMin();
    }
    return heap[0];
}

int main() {
    int nums[] = {4, 5, 8, 2};
    int n = 4;

    init(3, nums, n);

    printf("%d\n", add(3));
    printf("%d\n", add(5));
    printf("%d\n", add(10));
    printf("%d\n", add(9));
    printf("%d\n", add(4));

    return 0;
}