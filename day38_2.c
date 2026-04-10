#include <stdio.h>

#define MAX 100000

int dq[MAX];
int front = 0, rear = -1;

void push_back(int x) {
    dq[++rear] = x;
}

void pop_front() {
    front++;
}

void pop_back() {
    rear--;
}

int get_front() {
    return dq[front];
}

int isEmpty() {
    return front > rear;
}

void maxSlidingWindow(int nums[], int n, int k) {
    front = 0;
    rear = -1;

    for (int i = 0; i < n; i++) {

        if (!isEmpty() && get_front() <= i - k)
            pop_front();

        while (!isEmpty() && nums[dq[rear]] < nums[i])
            pop_back();

        push_back(i);

        if (i >= k - 1)
            printf("%d ", nums[get_front()]);
    }
}

int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int n = 8;
    int k = 3;

    maxSlidingWindow(nums, n, k);

    return 0;
}