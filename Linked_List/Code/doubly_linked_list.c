/*I have written this whole program on my own, now you understood how linked List work, 
You can do linked list now, you have got this boy!!!!*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};


void forwardTraverse(struct Node * head)
{
    struct Node *ptr = head;

    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void reverseTraverse(struct Node * last)
{
    struct Node *ptr = last;
    while(ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    //Allocate the memory for the nodes in the linke list in the heap
    struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second node
    N1->next = N2;
    N1->prev = NULL;

    //Link second and third node
    N2->next = N3;
    N2->prev = N1;

    //Terminate the doubly linked list at 3rd node
    N3->next = NULL;
    N3->prev = N2;

    //Insert data in Linked List
    N1->data = 7;
    N2->data = 21;
    N3->data = 8;

    printf("Double Linked List Forward Traverse\n");
    forwardTraverse(N1);

    printf("Double Linked List Reverse Traverse\n");
    reverseTraverse(N3);

    return 0;
}