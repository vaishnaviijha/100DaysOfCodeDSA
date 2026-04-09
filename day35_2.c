#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push_stack1(int x)
{
    s1[++top1] = x;
}

int pop_stack1()
{
    return s1[top1--];
}

void push_stack2(int x)
{
    s2[++top2] = x;
}

int pop_stack2()
{
    return s2[top2--];
}

bool empty()
{
    return (top1 == -1 && top2 == -1);
}

void push(int x)
{
    push_stack1(x);
}

int pop()
{
    if (top2 == -1)
    {
        while (top1 != -1)
            push_stack2(pop_stack1());
    }
    return pop_stack2();
}

int peek()
{
    if (top2 == -1)
    {
        while (top1 != -1)
            push_stack2(pop_stack1());
    }
    return s2[top2];
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("%d ", peek());
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", empty());

    return 0;
}