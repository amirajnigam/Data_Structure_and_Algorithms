#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//top global variable
struct Node*top = NULL;

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

//Change top variable name here to tp otherwise the local function operation in each line will update the global variable which will through ambiguity
int pop(struct Node *tp)
{
    if(isEmpty(tp))
        printf("Stack Underflow\n");
    else
    {
        struct Node *n = tp; 
        top = tp->next; 
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

int peek(int pos)
{
    struct Node *ptr = top;

    for(int i = 0; (i < pos-1 && ptr != NULL); i++)
        ptr= ptr->next;

    if(ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int stack_top()
{
    // struct Node *ptr = top;
    // return ptr->data;

    return top->data;
}

int stack_bottom()
{
    struct Node *ptr = top;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    return ptr->data;
}


int main(void)
{

    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    linkedListTraversal(top);

    for(int i = 1; i <= 4; i++){
        printf("Element at %d position is: %d\n", i, peek(i));
    }

    printf("Stack Top: %d\n", stack_top());

    printf("Stack bottom: %d\n", stack_bottom());

    return 0;
}