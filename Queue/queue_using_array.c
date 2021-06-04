#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->r == q->f)
        return 1;
    else
        return 0;
}

int isFULL(struct queue *q){
    if(q->r == q->size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int val){
    if(isFULL(q))
        printf("This queue is Full ");
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued elements:%d\n",val);
    }
}

int dequeue(struct queue *q){
    
    int a = -1;

    if(isEmpty(q))
        printf("Queue is Empty");
    else{
        q->f++;
        a = q->arr[q->f];  
    }
    return a;
}


int main(void)
{
    struct queue q;
    q.size = 16u;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);


    printf("Dequeue element:%d\n", dequeue(&q));
    printf("Dequeue element:%d\n", dequeue(&q));


    return 0;
}