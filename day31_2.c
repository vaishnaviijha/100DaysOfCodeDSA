#include <stdio.h>
#include <string.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '#';
    return stack[top--];
}

int isValid(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else
        {
            char temp = pop();

            if ((ch == ')' && temp != '(') ||
                (ch == '}' && temp != '{') ||
                (ch == ']' && temp != '['))
                return 0;
        }
    }

    if (top == -1)
        return 1;
    return 0;
}

int main()
{
    char s[10000];
    scanf("%s", s);

    if (isValid(s))
        printf("true");
    else
        printf("false");

    return 0;
}