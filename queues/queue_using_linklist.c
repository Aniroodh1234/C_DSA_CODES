#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue* next;
};

struct queue* front = NULL;   // here globally declare ho gya he toh sare functions automatically use kr lenge, no need for passing to arguments and giving functions
struct queue* rear = NULL;

void list_traversal(struct queue* front){
    struct queue* ptr = front;
    while(ptr!=NULL){
        printf("element is %d\n",ptr -> data);
        ptr = ptr -> next;
    }
}
// checking stack overflow condition
int queue_overflow(struct queue* ptr){
    if(ptr == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// checking stack underflow condition
int queue_underflow(struct queue* front){
    if(front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//enqueue operation using linklist
void enqueue(int val){                       // linklist wale me sara function de rhe the because end me sab pointer retrun ho rhe the yaha aisa nhi he
    struct queue* ptr = (struct queue*)malloc(sizeof(struct queue));
    if(queue_overflow(ptr)){
        printf("queue is full\n");
    }
    else{
        ptr -> data = val;
        ptr -> next = NULL;
        if(front == NULL){        //special condition --> if the stack is empty i.e front == NULL
            front = rear = ptr; 
        }
        else{
            rear -> next = ptr;
            rear = ptr;
        }
    }
}

int dequeue(){
    int val = -1;
    struct queue* ptr;
    if(queue_underflow(ptr)){
        printf("queue is empty");
    }
    else{
        front = front -> next;
        val = ptr -> data;
        free(ptr);
    }
    return val;
}
int main(){

    printf("before enqueue:\n\n");
    list_traversal(front);

    printf("after enqueue:\n");

    enqueue(67);
    enqueue(98);
    enqueue(58);
    list_traversal(front);

    printf("after dequeue:\n");
    dequeue(front);
    list_traversal(front);
    return 0;
}



