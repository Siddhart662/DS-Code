#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *node1, *node2, *node3, *newNode;
    struct Node *head, *temp;

    // Create 3 nodes: 10 -> 20 -> 30
    node1 = malloc(sizeof(struct Node));
    node2 = malloc(sizeof(struct Node));
    node3 = malloc(sizeof(struct Node));

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    head = node1;

    // (a) Insert at beginning (value 5)
    newNode = malloc(sizeof(struct Node));
    newNode->data = 5;
    newNode->next = head; // new node points to old head
    head = newNode;       // head now points to new node

    // (b) Insert at end (value 40)
    newNode = malloc(sizeof(struct Node));
    newNode->data = 40;
    newNode->next = NULL;
    node3->next = newNode; // last node points to new node

    // (c) Insert in middle, after node2 (value 25)
    newNode = malloc(sizeof(struct Node));
    newNode->data = 25;
    newNode->next = node2->next; // new node points to node3
    node2->next = newNode;       // node2 points to new node

    // Print list
    printf("After insertion:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}