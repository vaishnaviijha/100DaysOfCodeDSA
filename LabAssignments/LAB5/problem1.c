// NAME: Vaishnavi Kumari
// SAP ID: 590029048
// DATE: 19/02/2026


// Problem-1:
//Write a C program to implement a Stack using arrays.
//The program should support the following stack operations:
//1.	Push – Insert an element into the stack
//2.	Pop – Remove the top element from the stack
//3.	Peek – Display the top element of the stack
//4.	Display – Display all elements present in the stack
//The program must handle overflow and underflow conditions properly and display appropriate messages.

//REQUIRED CODE:

#include <stdio.h>

int main() {
    int MAX = 10;
    int stack[10];
    int top = -1;
    int choice, value, i;

    while (1) {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
                if (top == MAX - 1) {
                    printf("Stack Overflow! Cannot push element.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                    printf("%d pushed into stack.\n", value);
                }
                break;

            case 2: 
                if (top == -1) {
                    printf("Stack Underflow! Stack is empty.\n");
                } else {
                    printf("Popped element: %d\n", stack[top]);
                    top--;
                }
                break;

            case 3: 
                if (top == -1) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Top element: %d\n", stack[top]);
                }
                break;

            case 4: 
                if (top == -1) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack elements:\n");
                    for (i = top; i >= 0; i--) {
                        printf("%d\n", stack[i]);
                    }
                }
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
