#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int maxSum = nums[0];
    int currSum = nums[0];

    for(int i = 1; i < n; i++) {
        if(currSum + nums[i] > nums[i])
            currSum = currSum + nums[i];
        else
            currSum = nums[i];

        if(currSum > maxSum)
            maxSum = currSum;
    }

    printf("%d", maxSum);

    return 0;
}