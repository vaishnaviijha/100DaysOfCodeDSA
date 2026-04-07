#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    struct Node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
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
    char exp[1000];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " \n");

    while (token != NULL)
    {
        if (!isOperator(token))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();

            if (strcmp(token, "+") == 0)
                push(a + b);
            else if (strcmp(token, "-") == 0)
                push(a - b);
            else if (strcmp(token, "*") == 0)
                push(a * b);
            else if (strcmp(token, "/") == 0)
                push(a / b);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d", pop());

    return 0;
}