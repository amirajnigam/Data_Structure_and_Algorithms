#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int size;
    int f;
    int r;
    int *arr;
};

int isFULL(struct CircularQueue *q){
    if((q->r+1)%q->size == q->f)
        return 1;
    else
        return 0;
}

int isEmpty(struct CircularQueue *q){
    if(q->r == q->f)
        return 1;
    else
        return 0;
}

void enqueue(struct CircularQueue *q, int val){
    if(isFULL(q))
        printf("This queue is Full\n ");
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued Elements:%d\n", val);
    }
}

int dequeue(struct CircularQueue *q){
    
    int val = -1;

    if(isEmpty(q))
        printf("Queue is Empty\n");
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main(void)
{
    struct CircularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);

    // if(isEmpty(&q))
    //     printf("Queue is empty\n");
    
    // if(isFull(&q))
    //     printf("Queue is full\n");
    
    return 0;
}