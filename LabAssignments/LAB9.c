// LAB ASSIGNMENNT-9


//Q1.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newnode == NULL){
        printf("Queue Overflow\n");
        return;
    }
    
    newnode->data = value;
    
    if(front == NULL){
        front = rear = newnode;
        newnode->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    
    struct Node *temp = front;
    
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
        rear->next = front;
    }
    
    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    
    struct Node *temp = front;
    
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != front);
    
    printf("\n");
}

int main(){
    int choice, value;
    
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
                
            case 2:
                dequeue();
                display();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}


//Q2.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value, int pr){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newnode == NULL){
        printf("Memory not available\n");
        return;
    }
    
    newnode->data = value;
    newnode->priority = pr;
    newnode->next = NULL;
    
    if(head == NULL || pr < head->priority){
        newnode->next = head;
        head = newnode;
    }
    else{
        struct Node *temp = head;
        
        while(temp->next != NULL && temp->next->priority <= pr){
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete(){
    if(head == NULL){
        printf("Queue Underflow\n");
        return;
    }
    
    struct Node *temp = head;
    printf("Deleted element: %d\n", temp->data);
    
    head = head->next;
    free(temp);
}

void display(){
    if(head == NULL){
        printf("Queue is empty\n");
        return;
    }
    
    struct Node *temp = head;
    
    while(temp != NULL){
        printf("Value: %d Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main(){
    int choice, value, pr;
    
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                
                printf("Enter priority: ");
                scanf("%d", &pr);
                insert(value, pr);
                display();
                break;
                
            case 2:
                delete();
                display();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}