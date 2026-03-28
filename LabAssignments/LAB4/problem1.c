// NAME: Vaishnavi Kumari
// SAP ID: 590029048
// DATE: 05/02/2026

// Lab Problem 1: Music Playlist using Doubly Linked List
//Objective: To implement a doubly linked list and perform bidirectional traversal.
//Problem Statement:
//•	Design a music playlist manager where each node stores:
//•	Song Name
//•	Artist Name
//•	Duration


//The program should allow:
//•	Add a song at the beginning
//•	Add a song at the end
//•	Delete a song by name
//•	Display playlist forward
//•	Display playlist in reverse


//REQUIRED CODE:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char songName[50];
    char artist[50];
    int duration;
    struct Song *prev;
    struct Song *next;
};

struct Song *head = NULL;


struct Song* createSong()
{
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));

    printf("Enter Song Name: ");
    scanf(" %[^\n]", newSong->songName);

    printf("Enter Artist Name: ");
    scanf(" %[^\n]", newSong->artist);

    printf("Enter Duration (in seconds): ");
    scanf("%d", &newSong->duration);

    newSong->prev = NULL;
    newSong->next = NULL;

    return newSong;
}


void addAtBeginning()
{
    struct Song *newSong = createSong();

    if (head == NULL)
    {
        head = newSong;
    }
    else
    {
        newSong->next = head;
        head->prev = newSong;
        head = newSong;
    }

    printf("Song added at beginning.\n");
}


void addAtEnd()
{
    struct Song *newSong = createSong();
    struct Song *temp = head;

    if (head == NULL)
    {
        head = newSong;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newSong;
    newSong->prev = temp;

    printf("Song added at end.\n");
}

void deleteSong()
{
    char name[50];
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("Enter song name to delete: ");
    scanf(" %[^\n]", name);

    while (temp != NULL && strcmp(temp->songName, name) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Song not found.\n");
        return;
    }

    if (temp == head)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Song deleted successfully.\n");
}


void displayForward()
{
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\nPlaylist (Forward):\n");
    while (temp != NULL)
    {
        printf("Song: %s | Artist: %s | Duration: %d sec\n",
               temp->songName, temp->artist, temp->duration);
        temp = temp->next;
    }
}


void displayReverse()
{
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("\nPlaylist (Reverse):\n");
    while (temp != NULL)
    {
        printf("Song: %s | Artist: %s | Duration: %d sec\n",
               temp->songName, temp->artist, temp->duration);
        temp = temp->prev;
    }
}


int main()
{
    int choice;

    do
    {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add Song at Beginning\n");
        printf("2. Add Song at End\n");
        printf("3. Delete Song by Name\n");
        printf("4. Display Playlist Forward\n");
        printf("5. Display Playlist Reverse\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAtBeginning();
            break;
        case 2:
            addAtEnd();
            break;
        case 3:
            deleteSong();
            break;
        case 4:
            displayForward();
            break;
        case 5:
            displayReverse();
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
