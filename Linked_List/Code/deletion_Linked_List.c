#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
struct Node * deleteFirstNode(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);

    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node * deleteNodeAtIndex( struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head;

    int i = 0, j = 0;

    while(i != index -1)
    {
        p = p->next;
        i++;
    }

    while(j != index)
    {
        q = q->next;
        j++;
    }

    p->next = q->next;
    free(q);

    return head;
}

// Case 3: Deleting the last element
struct Node * deleteLastNode( struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;

    while(q->next != NULL)
        q = q->next;

    while(p->next != q)
        p = p->next;
    
    p->next = NULL;

    free(q);

    return head;
}

// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteTheFirstNodeWithGivenValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head;

    while(q->data != value)
        q = q->next;

    while(p->next != q)
        p = p->next;
    
    if(q->data == value){
    p->next = q->next;
    free(q);
    }

    return head;

}


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    //head = deleteFirstNode(head);
    //head = deleteNodeAtIndex(head, 2);
    //head = deleteLastNode(head);
    head = deleteTheFirstNodeWithGivenValue(head, 41);
       
    printf("Linked list After Deletion\n");
    linkedListTraversal(head);

    return 0;
}