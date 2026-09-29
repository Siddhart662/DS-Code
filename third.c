#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *node1, *node2, *node3;

    // Create nodes
    node1 = malloc(sizeof(struct Node));
    node2 = malloc(sizeof(struct Node));
    node3 = malloc(sizeof(struct Node));

    // Store data
    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    // Connect nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Last node points to first node

    // Print circular list
    printf("Circular Linked List:\n");

    struct Node *temp = node1;

    printf("%d -> ", temp->data);
    temp = temp->next;

    printf("%d -> ", temp->data);
    temp = temp->next;

    printf("%d -> ", temp->data);
    temp = temp->next;

    printf("%d", temp->data);

    return 0;
}