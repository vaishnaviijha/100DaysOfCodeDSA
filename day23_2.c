#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode, *cycleNode = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if(i == pos)
            cycleNode = newNode;
    }

    scanf("%d", &pos);

    if(pos != -1) {
        temp->next = cycleNode;
    }

    struct Node *slow = head, *fast = head;

    int hasCycle = 0;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            hasCycle = 1;
            break;
        }
    }

    if(hasCycle)
        printf("true");
    else
        printf("false");

    return 0;
}