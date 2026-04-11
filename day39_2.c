#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    int freq[20001] = {0};

    for (int i = 0; i < n; i++) {
        freq[nums[i] + 10000]++;
    }

    Node* bucket[n + 1];
    for (int i = 0; i <= n; i++) bucket[i] = NULL;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = i - 10000;
            newNode->next = bucket[freq[i]];
            bucket[freq[i]] = newNode;
        }
    }

    int count = 0;
    for (int i = n; i >= 0 && count < k; i--) {
        Node* temp = bucket[i];
        while (temp && count < k) {
            printf("%d ", temp->val);
            count++;
            temp = temp->next;
        }
    }

    return 0;
}