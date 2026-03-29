#include <stdio.h>

int main() {
    char s[] = {'h','e','l','l','o'};
    int n = sizeof(s)/sizeof(s[0]);

    int i = 0, j = n - 1;
    char temp;

    while(i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    for(int k = 0; k < n; k++) {
        printf("%c", s[k]);
    }

    return 0;
}