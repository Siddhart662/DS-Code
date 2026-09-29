#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    // Create 3 nodes
    struct Node *node1, *node2, *node3;

    node1 = malloc(sizeof(struct Node));
    node2 = malloc(sizeof(struct Node));
    node3 = malloc(sizeof(struct Node));

    // Store data
    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    // Connect nodes
    node1->prev = NULL;
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = NULL;

    // Print list
    printf("Doubly Linked List:\n");
    printf("%d <-> %d <-> %d\n",
           node1->data,
           node2->data,
           node3->data);

    // Delete node2
    node1->next = node3;
    node3->prev = node1;

    free(node2);

    // Print after deletion
    printf("After deletion:\n");
    printf("%d <-> %d\n", node1->data, node3->data);

    return 0;
}