#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top == (ptr->size - 1))
        return 1;
    else
        return 0;
}


void push(struct stack *ptr , int val )
{
    if(isFull(ptr))
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    else{  
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannnot pop from stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stack_top(struct stack *sp)
{
    return sp->arr[sp->top];
}


int stack_bottom(struct stack *sp)
{
    return sp->arr[0];
}

int main()
{
    //Create a stack;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); //Need to allocate memory just like we did in Linked List for each node
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size * sizeof(int)); // allocate memory for stack of size 10

    printf("Stack Created\n\n");
    push(sp,7);
    push(sp,8);
    push(sp,9);
    push(sp,10);
    push(sp,11);
    push(sp,89);
    push(sp,48);
    push(sp,56);
    push(sp,29);
    push(sp,89); //--->Pushed 10 values


    printf("Top Value of stack %d\n", stack_top(sp));
    printf("Bottom Value of stack %d\n", stack_bottom(sp));


    return 0;
}