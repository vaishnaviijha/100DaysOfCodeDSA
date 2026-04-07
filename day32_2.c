#include <stdio.h>
#define MAX 10000

int stack[MAX], minStack[MAX];
int top1 = -1, top2 = -1;

void push(int val)
{
    stack[++top1] = val;

    if (top2 == -1 || val <= minStack[top2])
        minStack[++top2] = val;
}

void pop()
{
    if (stack[top1] == minStack[top2])
        top2--;
    top1--;
}

int top()
{
    return stack[top1];
}

int getMin()
{
    return minStack[top2];
}

int main()
{
    push(-2);
    push(0);
    push(-3);

    printf("%d\n", getMin());

    pop();

    printf("%d\n", top());
    printf("%d\n", getMin());

    return 0;
}