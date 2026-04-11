#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int temp[n], ans[n], stack[n];
    for (int i = 0; i < n; i++) scanf("%d", &temp[i]);

    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && temp[stack[top]] <= temp[i]) {
            top--;
        }

        if (top == -1) ans[i] = 0;
        else ans[i] = stack[top] - i;

        stack[++top] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}