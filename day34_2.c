#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 300000

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

int main()
{
    char s[MAX];
    fgets(s, sizeof(s), stdin);

    int num = 0;
    char op = '+';

    for (int i = 0; i <= strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0')
        {
            if (op == '+')
                push(num);
            else if (op == '-')
                push(-num);
            else if (op == '*')
                push(pop() * num);
            else if (op == '/')
                push(pop() / num);

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (top != -1)
        result += pop();

    printf("%d", result);

    return 0;
}