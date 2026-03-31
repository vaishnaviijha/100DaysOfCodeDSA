#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100], t[100][100];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            t[j][i] = a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}