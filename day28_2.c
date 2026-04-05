#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return 1;

    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *curr = slow, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode *first = head, *second = prev;

    while (second) {
        if (first->val != second->val) return 0;
        first = first->next;
        second = second->next;
    }

    return 1;
}