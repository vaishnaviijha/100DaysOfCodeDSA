#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

int isOperator(char *s)
{
    return (strcmp(s, "+") == 0 ||
            strcmp(s, "-") == 0 ||
            strcmp(s, "*") == 0 ||
            strcmp(s, "/") == 0);
}

int main()
{
    int n;
    scanf("%d", &n);

    char tokens[n][20];

    for (int i = 0; i < n; i++)
        scanf("%s", tokens[i]);

    for (int i = 0; i < n; i++)
    {
        if (!isOperator(tokens[i]))
        {
            push(atoi(tokens[i]));
        }
        else
        {
            int b = pop();
            int a = pop();

            if (strcmp(tokens[i], "+") == 0)
                push(a + b);
            else if (strcmp(tokens[i], "-") == 0)
                push(a - b);
            else if (strcmp(tokens[i], "*") == 0)
                push(a * b);
            else if (strcmp(tokens[i], "/") == 0)
                push(a / b);
        }
    }

    printf("%d", pop());

    return 0;
}