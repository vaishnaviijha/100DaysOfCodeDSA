// Name: Vaishnavi Kumari 
//Sap Id: 590029048

//1) Write a C program to:
//1. Define the structure of a Generalized Linked List node.
//2. Create data nodes and sublist nodes.
//3. Construct a sample generalized linked list containing at least one sublist.
//4. Traverse and display the entire generalizelinked list using recursion.

//REQUIRED CODE:


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int tag;
    union
    {
        char data;
        struct node *sublist;
    } info;
    struct node *next;
};

struct node* createDataNode(char value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->tag = 0;
    newNode->info.data = value;
    newNode->next = NULL;
    return newNode;
}

struct node* createSublistNode(struct node *head)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->tag = 1;
    newNode->info.sublist = head;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct node *head)
{
    while(head != NULL)
    {
        if(head->tag == 0)
        {
            printf("%c ", head->info.data);
        }
        else
        {
            printf("( ");
            traverse(head->info.sublist);
            printf(") ");
        }
        head = head->next;
    }
}

int main()
{
    struct node *node1 = createDataNode('A');
    struct node *node2 = createDataNode('B');
    struct node *node3 = createDataNode('C');

    struct node *subNode1 = createDataNode('D');
    struct node *subNode2 = createDataNode('E');

    subNode1->next = subNode2;

    struct node *subList = createSublistNode(subNode1);

    node1->next = node2;
    node2->next = subList;
    subList->next = node3;

    printf("Generalized Linked List: ");
    traverse(node1);

    return 0;
}

//2) 
//Write a C program to:
//1. Create a generalized linked list with multiple levels of sublists.
//2. Traverse the list recursively.
//3. Count and display the total number of atomic data elements present in the generalized linked list.

//REQUIRED CODE:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int tag;
    union
    {
        char value;
        struct Node *down;
    };
    struct Node *next;
}Node;

Node* createAtom(char v)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->tag = 0;
    temp->value = v;
    temp->next = NULL;
    return temp;
}

Node* createSublist(Node* sub)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->tag = 1;
    temp->down = sub;
    temp->next = NULL;
    return temp;
}

void display(Node* head)
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        if(ptr->tag == 0)
        {
            printf("%c ", ptr->value);
        }
        else
        {
            printf("( ");
            display(ptr->down);
            printf(") ");
        }
        ptr = ptr->next;
    }
}

int countAtoms(Node* head)
{
    Node* ptr = head;
    int count = 0;

    while(ptr != NULL)
    {
        if(ptr->tag == 0)
        {
            count++;
        }
        else
        {
            count += countAtoms(ptr->down);
        }
        ptr = ptr->next;
    }

    return count;
}

int main()
{
    Node *a,*b,*c,*d,*e,*f,*g;
    Node *sub1,*sub2;
    Node *head;

    a = createAtom('A');
    b = createAtom('B');
    c = createAtom('C');
    d = createAtom('D');
    e = createAtom('E');
    f = createAtom('F');
    g = createAtom('G');

    sub2 = createSublist(f);
    f->next = g;

    sub1 = createSublist(d);
    d->next = e;
    e->next = sub2;

    head = a;
    a->next = b;
    b->next = createSublist(c);
    c->next = sub1;

    printf("Generalized Linked List:\n");
    display(head);

    int total = countAtoms(head);
    printf("\n\nTotal Atomic Elements: %d\n", total);

    return 0;
}