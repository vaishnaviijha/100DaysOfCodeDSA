#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    while(k < n) {
        nums[k] = 0;
        k++;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}