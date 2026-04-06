#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    dummy.next = NULL;
    struct Node* temp = &dummy;

    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        temp->next = createNode(sum % 10);
        carry = sum / 10;
        temp = temp->next;
    }

    return dummy.next;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct Node* result = addLists(l1, l2);

    return reverse(result);
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n1, n2, x;

    scanf("%d", &n1);
    struct Node* l1 = NULL;
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    scanf("%d", &n2);
    struct Node* l2 = NULL;
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    struct Node* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}