#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node *next;
};

struct Node *top = NULL;


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

struct Node* push(struct Node *top, char x )
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

void valid_parenthesis(char * exp){
    
    //Create and initialize the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));

    for(i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(')
        {
            push(sp, arr[i]);
        }

        else if(arr[i] == ')')
        {
            if(!isEmpty(sp))
                return 0;
            else
                pop(sp);
        }  
    }
}


int main(void)
{
    char *exp = "8+(9*3)"; 
    if(valid_parenthesis(exp))
        printf("The parenthesis is matching");
    else
        printf("The parenthesis is not matching");
    return 0;
}