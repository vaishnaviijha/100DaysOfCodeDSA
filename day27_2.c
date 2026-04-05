#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int removeCycle(struct Node* head) {
    if (!head || !head->next) return 0;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            if (slow == fast) {
                while (fast->next != slow) fast = fast->next;
                fast->next = NULL;
                return 1;
            }

            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;
            return 1;
        }
    }

    return 0;
}