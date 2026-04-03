#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

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
    }

    scanf("%d", &val);

    while(head != NULL && head->data == val) {
        struct Node* del = head;
        head = head->next;
        free(del);
    }

    struct Node *curr = head;

    while(curr != NULL && curr->next != NULL) {
        if(curr->next->data == val) {
            struct Node* del = curr->next;
            curr->next = del->next;
            free(del);
        } else {
            curr = curr->next;
        }
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}