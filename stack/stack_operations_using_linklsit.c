#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Linklist traversal
void traversal(struct node* top) {
    struct node* ptr = top; 
    int i = 1;
    while(ptr != NULL) {
        printf("Element %d: %d\n", i++, ptr->data);
        ptr = ptr->next;
    }
}

// Stack overflow condition (this function is not really necessary)
int stack_overflow() {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        return 1; // Overflow
    }
    else{
        return 0;
    }
}

// Stack underflow condition
int stack_underflow(struct node* top) {
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Pop function 
struct node* pop(struct node* top) {
    if (stack_underflow(top)) {
        printf("Stack underflow\n");
        return top; // Return unchanged top
    }
    struct node* ptr = top;
    top = top->next;
    free(ptr);
    return top; // Return new top
}

// Pushing operation in stack using linked list
struct node* push(struct node* top, int x) {
    if (stack_overflow()) {
        printf("Stack overflow\n");
        return top; // Return unchanged top
    }
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    return n; // Return new top
}

// Peek function to get the value at a specific position
int peek(struct node* top, int pos) {
    struct node* ptr = top;
    for (int i = 1; i < pos && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        return ptr->data;
    }
    return -1; // Position is out of bounds
}

int main() {
    struct node* top = NULL;
    top = push(top, 76);
    top = push(top, 45);
    top = push(top, 32);
    top = push(top, 78);
    top = push(top, 99);
    top = push(top, 89);
    top = push(top, 21);
    top = push(top, 57);
    top = push(top, 69);

    printf("Stack elements:\n");
    traversal(top);
    printf("\n");

    top = pop(top);
    top = pop(top);
    top = pop(top);

    printf("Stack elements after popping:\n");
    traversal(top);
    printf("\n");

    for (int i = 1; i <= 6; i++) {
        int value = peek(top, i);
        if (value != -1) {
            printf("Value at position %d is %d\n", i, value);
        } else {
            printf("No value at position %d\n", i);
        }
    }

    // Free remaining elements in the stack
    while (top != NULL) {
        top = pop(top);
    }

    return 0;
}
