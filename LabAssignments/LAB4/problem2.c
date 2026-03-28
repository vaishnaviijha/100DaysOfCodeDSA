// NAME: Vaishnavi Kumari
// SAP ID: 590029048
// DATE: 05/02/2026

//Lab Problem 2: Task Management System using Circular Linked List
//Objective: To implement a circular linked list using structures and dynamic memory allocation to manage tasks in a cyclic manner.
//Problem Statement:
//•	Develop a C program to create a circular linked list where each node stores:
//•	Task ID
//•	Task Description
//•	Priority Level


//The program should perform the following operations:
//•	Add a new task
//•	Delete a task using Task ID
//•	Display all tasks
//•	Move to the next task cyclically (round-robin style processing)
//•	Count the total number of tasks

// REQUIRED CODE:-

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task
{
    int taskID;
    char description[50];
    int priority;
    struct Task *next;
};

struct Task *head = NULL;
struct Task *current = NULL;


struct Task* createTask()
{
    struct Task *newTask = (struct Task*)malloc(sizeof(struct Task));

    printf("Enter Task ID: ");
    scanf("%d", &newTask->taskID);

    printf("Enter Task Description: ");
    scanf(" %[^\n]", newTask->description);

    printf("Enter Priority Level: ");
    scanf("%d", &newTask->priority);

    newTask->next = newTask;   
    return newTask;
}


void addTask()
{
    struct Task *newTask = createTask();

    if (head == NULL)
    {
        head = newTask;
        current = newTask;
    }
    else
    {
        struct Task *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newTask;
        newTask->next = head;
    }

    printf("Task added successfully.\n");
}


void deleteTask()
{
    int id;
    struct Task *temp = head, *prev = NULL;

    if (head == NULL)
    {
        printf("Task list is empty.\n");
        return;
    }

    printf("Enter Task ID to delete: ");
    scanf("%d", &id);

    do
    {
        if (temp->taskID == id)
        {
            if (temp == head && temp->next == head)
            {
                head = NULL;
                current = NULL;
            }
            else
            {
                if (temp == head)
                {
                    prev = head;
                    while (prev->next != head)
                        prev = prev->next;
                    head = temp->next;
                    prev->next = head;
                }
                else
                {
                    prev->next = temp->next;
                }

                if (current == temp)
                    current = temp->next;
            }

            free(temp);
            printf("Task deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    printf("Task not found.\n");
}


void displayTasks()
{
    struct Task *temp = head;

    if (head == NULL)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\nTask List:\n");
    do
    {
        printf("Task ID: %d | Priority: %d | Description: %s\n",
               temp->taskID, temp->priority, temp->description);
        temp = temp->next;
    } while (temp != head);
}


void nextTask()
{
    if (current == NULL)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\nCurrent Task:\n");
    printf("Task ID: %d | Priority: %d | Description: %s\n",
           current->taskID, current->priority, current->description);

    current = current->next;
}


void countTasks()
{
    int count = 0;
    struct Task *temp = head;

    if (head == NULL)
    {
        printf("Total Tasks: 0\n");
        return;
    }

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    printf("Total Tasks: %d\n", count);
}


int main()
{
    int choice;

    do
    {
        printf("\n--- Task Management Menu ---\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display All Tasks\n");
        printf("4. Move to Next Task\n");
        printf("5. Count Tasks\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            deleteTask();
            break;
        case 3:
            displayTasks();
            break;
        case 4:
            nextTask();
            break;
        case 5:
            countTasks();
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
