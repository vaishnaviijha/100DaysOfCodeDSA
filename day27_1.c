#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++) p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1->data == p2->data) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, val;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head1) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head2) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* res = findIntersection(head1, head2);

    if (res)
        printf("%d\n", res->data);
    else
        printf("No Intersection\n");

    return 0;
}