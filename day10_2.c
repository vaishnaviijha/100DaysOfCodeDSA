#include <stdio.h>

int main() {
    int nums1[] = {1,2,2,1};
    int nums2[] = {2,2};

    int n1 = sizeof(nums1)/sizeof(nums1[0]);
    int n2 = sizeof(nums2)/sizeof(nums2[0]);

    int freq[1001] = {0};

    for(int i = 0; i < n1; i++) {
        freq[nums1[i]]++;
    }

    int result[1000];
    int k = 0;

    for(int i = 0; i < n2; i++) {
        if(freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    for(int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}