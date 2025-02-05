#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};

//peek function for a stack
int peek(struct stack* ptr, int x){
    if(x < 0 || x > ptr -> top + 1){
        printf("invalid position");
        return -1;
    }
    else{
        return ptr -> arr[ptr -> top -x + 1];
    }
}

//checking stack overflow condition
int stack_overflow(struct stack* ptr){
    if(ptr -> top == ptr -> size - 1){
        return 1;
    }
    else {
        return 0;
    }
}

//pushing elements in to the stack
void push(struct stack* ptr, int x){
    if(stack_overflow(ptr)){
        printf("stack is overflow\n");
    }
    else{
        ptr -> top ++;
        ptr -> arr[ptr -> top] = x;
    }
}

//stack_underflow condition
int stack_underflow(struct stack* ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// poppping elements in the stack
int pop(struct stack* ptr, int x){
    if(stack_underflow(ptr)){
        printf("stack undeflow\n");
    }
    else{
        int value = ptr -> arr[ptr -> top];
        ptr -> top --;
        return value;
    }
}

//printing the stack
void print_stack(struct stack* ptr){
    for(int i = 1; i <= ptr -> top + 1; i++){
        printf("element %d: %d\n",i,peek(ptr,i));
    }
}

int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s -> size = 8;
    s -> top = -1;
    s -> arr = (int*)malloc(s -> size*sizeof(int));

    //pushing elements in to the stack 
    push(s,45);
    push(s,59);
    push(s,76);
    push(s,11);

    printf("\nelements in the stack before pushing:\n");
    print_stack(s);
    //pushing elements in to the stack
    push(s,89);
    push(s,28);
    push(s,58);

    printf("\nelements in the stack after pushing:\n");
    print_stack(s);

    printf("\nupdated stack after pushing:\n");
    print_stack(s);
    pop(s,28);
    pop(s,11);
    pop(s,58);
    pop(s,76);

    printf("\nupdated stack after popping:\n");
    print_stack(s);

    return 0;


}



















































// #include <stdio.h>
// #include <stdlib.h>

// struct stack {
//     int size;
//     int top;
//     int *arr;
// };

// // Function to check if the stack is full
// int stack_overflow(struct stack *ptr) {
//     return ptr->top == ptr->size - 1;
// }

// // Function to peek at the element at a given position
// int peek(struct stack *ptr, int x) {
//     if (x < 1 || x > ptr->top + 1) {
//         printf("Invalid position\n");
//         return -1; // Return an error indicator
//     }
//     return ptr->arr[ptr->top - x + 1];
// }

// // Function to push an element onto the stack
// void push(struct stack *ptr, int x) {
//     if (stack_overflow(ptr)) {
//         printf("Stack overflow\n");
//     } else {
//         ptr->arr[++(ptr->top)] = x;
//     }
// }

// // Function to print the contents of the stack
// void print_stack(struct stack *ptr) {
//     if (ptr->top == -1) {
//         printf("Stack is empty\n");
//     } else {
//         printf("Stack elements:\n");
//         for (int i = 1; i <= ptr->top + 1; i++) {
//             printf("Position %d: %d\n", i, peek(ptr, i));
//         }
//     }
// }

// int main() {
//     struct stack *s = (struct stack *)malloc(sizeof(struct stack));
//     s->size = 8;
//     s->top = -1;
//     s->arr = (int *)malloc(s->size * sizeof(int));

//     // Push elements onto the stack
//     push(s, 10);
//     push(s, 20);
//     push(s, 30);
//     push(s, 40);

//     // Print the stack before pushing more elements
//     printf("Before pushing:\n");
//     print_stack(s);

//     // Attempt to push more elements
//     push(s, 97);
//     push(s, 72);
//     push(s, 89);

//     // Print the stack after pushing more elements
//     printf("\nAfter pushing:\n");
//     print_stack(s);

//     return 0;
// }