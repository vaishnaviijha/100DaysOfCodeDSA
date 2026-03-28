// NAME: Vaishnavi Kumari
// SAP ID: 590029048
// DATE: 19/02/2026

//Problem-2:
//Write a C program to implement a Stack using a singly linked list.
//The program should perform the following operations:
//1.	Push – Insert an element into the stack
//2.	Pop – Remove the top element from the stack
//3.	Peek – Display the top element
//4.	Display – Display all stack elements
//Dynamic memory allocation must be used to create and delete stack nodes.	

//REQUIRED CODE:

#include <stdio.h>
#include <stdlib.h>

int main() {

    struct Node {
        int data;
        struct Node* next;
    };

    struct Node *top = NULL, *temp;
    int choice, value;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:   
                temp = (struct Node*)malloc(sizeof(struct Node));

                if (temp == NULL) {
                    printf("Stack Overflow! Memory not allocated.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);

                    temp->data = value;
                    temp->next = top;
                    top = temp;

                    printf("%d pushed into stack.\n", value);
                }
                break;

            case 2:   
                if (top == NULL) {
                    printf("Stack Underflow! Stack is empty.\n");
                } else {
                    temp = top;
                    printf("Popped element: %d\n", top->data);
                    top = top->next;
                    free(temp);
                }
                break;

            case 3:   
                if (top == NULL) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Top element: %d\n", top->data);
                }
                break;

            case 4:  
                if (top == NULL) {
                    printf("Stack is empty.\n");
                } else {
                    temp = top;
                    printf("Stack elements:\n");
                    while (temp != NULL) {
                        printf("%d\n", temp->data);
                        temp = temp->next;
                    }
                }
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
