#include <stdio.h>

int main() {
    int n, i, pos, x;

    scanf("%d", &n);

    int a[100];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &pos);
    scanf("%d", &x);

    for(i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos - 1] = x;

    for(i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}