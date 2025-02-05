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
    if((ptr->r+1)%(ptr->size)==ptr ->f){
        return 1;
    }
    else{
        return 0;
    }    
}
void enqueue_rear(struct queue* ptr, int value){
    if(queue_overflow(ptr)){
        printf("queue is full\n");
    }
    else{
        ptr ->r =(ptr ->r+1)%ptr -> size;
        ptr -> arr[ptr -> r] = value;
        printf("Enqueued at rear: %d\n", value);
    }
}

void enqueue_front(struct queue* ptr, int value){
    if(queue_overflow(ptr)){
        printf("queue is full\n");
    }
    else{
        ptr -> arr[ptr -> f] = value;
        ptr ->f = (ptr -> f-1 + ptr ->size) % ptr -> size;
        printf("Enqueued at front: %d\n", value);
    }
}

int dequeue_front(struct queue* ptr){
    int value = -1;
    if(queue_underflow(ptr)){
        printf("queue is empty\n");
    }
    else{
        ptr -> f = (ptr -> f+1)%ptr -> size;
        value = ptr -> arr[ptr -> f];
        // printf("Dequeued: %d\n", value);
    }
    return value;
}

int dequeue_rear(struct queue* ptr){
    int value = -1;
    if(queue_underflow(ptr)){
        printf("queue is empty\n");
    }
    else{
        value = ptr -> arr[ptr -> r];
        ptr -> r = (ptr -> r-1 + ptr ->size) % ptr -> size;
        // printf("Dequeued: %d\n", value);
    }
    return value;
}

int main(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 5;
    q->r = 0;           //in linear queue always the the f and r integer pointer points to the -1
    q->f = 0;
    q->arr = (int*)malloc(q->size*(sizeof(int)));
    enqueue_rear(q,12);
    enqueue_rear(q,45);
    enqueue_rear(q,89);
    enqueue_rear(q,47);
    
    printf("dequeue elements: %d\n",dequeue_front(q));
    printf("dequeue elements: %d\n",dequeue_front(q));
    printf("dequeue elements: %d\n",dequeue_front(q));
    printf("dequeue elements: %d\n",dequeue_front(q));

    enqueue_front(q,74);
    enqueue_front(q,6);
    enqueue_front(q,1);

    printf("dequeue elements: %d\n",dequeue_rear(q));
    printf("dequeue elements: %d\n",dequeue_rear(q));
    printf("dequeue elements: %d\n",dequeue_rear(q));
    return 0;
}