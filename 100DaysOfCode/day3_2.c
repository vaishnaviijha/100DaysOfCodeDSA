#include <stdio.h>

int findMissing(int arr[], int size) {
    int n = size + 1;
    
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;

    for(int i = 0; i < size; i++) {
        actual_sum += arr[i];
    }

    return expected_sum - actual_sum;
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Missing number: %d", findMissing(arr, size));
    return 0;
}