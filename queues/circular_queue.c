#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int r;
    int f;
    int* arr;
};
int queue_underflow(struct queue* ptr){
    if(ptr -> r == ptr -> f){
        return 1;
    }
    else{
        return 0;
    }
} 
int queue_overflow(struct queue* ptr){
    if((ptr ->r+1)%ptr -> size == ptr -> f){
        return 1;
    }
    else{
        return 0;
    }    
}
void enqueue(struct queue* ptr, int value){
    if(queue_overflow(ptr)){
        printf("queue is full\n");
    }
    else{
        ptr ->r = (ptr ->r+1)% ptr ->size;
        ptr -> arr[ptr -> r] = value;
        printf("Enqueued: %d\n", value);
    }
}
int dequeue(struct queue* ptr){
    int value = -1;
    if(queue_underflow(ptr)){
        printf("queue is empty\n");
    }
    else{
        ptr -> f = (ptr -> f+1)%ptr ->size;
        value = ptr -> arr[ptr -> f];
        // printf("Dequeued: %d\n", value);
    }
    return value;
}
int main(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 5;
    q->r = 0;      //in circular queue always the the f and r integer pointer points to the 0
    q->f = 0;
    q->arr = (int*)malloc(q->size*(sizeof(int)));
    enqueue(q,12);
    enqueue(q,45);
    enqueue(q,89);
    enqueue(q,47);

    printf("dequeue elements: %d\n",dequeue(q));
    printf("dequeue elements: %d\n",dequeue(q));
    printf("dequeue elements: %d\n",dequeue(q));
    printf("dequeue elements: %d\n",dequeue(q));

    enqueue(q,74);
    enqueue(q,6);
    enqueue(q,1);

    if(queue_underflow(q)){
        printf("queue is empty\n");
    }

    if(queue_overflow(q)){
        printf("queue is full\n");
    }
    
    return 0;
}
