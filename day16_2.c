#include <stdio.h>

void rotate(int nums[], int n, int k) {
    k = k % n;

    for(int i = 0; i < k; i++) {
        int last = nums[n - 1];

        for(int j = n - 1; j > 0; j--) {
            nums[j] = nums[j - 1];
        }

        nums[0] = last;
    }
}

int main() {
    int nums[] = {1,2,3,4,5,6,7};
    int n = 7, k = 3;

    rotate(nums, n, k);

    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}