#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct Node *top)
{
    
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL)
        return 1;
    else
        return 0;
}
//Return type should be struct Node * becuase we are pushing a node an retiurnig a pointer to the address of top
struct Node* push(struct Node *top, int x)
{
    
    if(isFull(top))
        printf("Stack Overflow\n");
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
    }
}

//Due to the call by reference top will behave asa pointer over here so we have to use *top every time instead of top
int pop(struct Node **top)
{
    if(isEmpty(*top))
        printf("Stack Underflow\n");
    else
    {
        struct Node *n = *top; // create a pointer not node, pointerpointing to top
        *top = (*top)->next; // use paranthesis to first dereference the top and then direct it to next
        int x = n->data;
        free(n);
        return x;
    }
}

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}


int main(void)
{
    struct Node *top = NULL;

    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);

    linkedListTraversal(top);

    int ele = pop(&top); //We need to send the address of pop to update it here also --> call by reference
    printf("Popped Element is %d\n", ele);
    linkedListTraversal(top);


return 0;
}