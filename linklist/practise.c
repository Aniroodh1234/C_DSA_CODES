#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* traversal(struct node* head){
    struct node*ptr = head;
    while(ptr!=NULL){
        printf("elements: %d\n", ptr ->data);
        ptr = ptr -> next;
    }
    return ptr;
}
// insertion at start of the linklist
struct node*insert_at_start(struct node*head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

//insertion at the middle
struct node*insert_at_middle(struct node* head, int data, int index ){
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head;
    int i =0;
    while(p != NULL && i != index-1){
        p = p-> next;
        i++;
    }
    if(p ==NULL){
        printf("index out of bound");
        free(ptr);
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

//insertion of element at the end
struct node*insert_at_end(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head;
    int i = 0;
    while(p -> next !=NULL){
        p = p-> next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

//deletion of element at the start of linklist
struct node*delete_at_start(struct node* head, int data){
    struct node*ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

//deletion of element at the middle of the linklist
struct node*delete_at_middle(struct node*head, int index){
    struct node* ptr = head;
    struct node* p = head -> next;
    int i =1;
    while(ptr!=NULL&& i !=index-1 ){
        ptr = ptr -> next;
        p++;
        i++;
    }
    if(ptr == NULL){
        printf("index out of bound");
        free(ptr);

    }
    ptr -> next = p -> next;
    free(p);
    return head;
}
int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = fifth;

    fifth->data = 1;
    fifth->next = NULL; 

    printf("linklist before insertion operation: \n");
    traversal(head);

    // head = insert_at_start(head,10);
    // printf("linklist after insert at strat operation: \n");
    // traversal(head);

    // head = insert_at_middle(head,10,3);
    // printf("linklist after insert at middle operation: \n");
    // traversal(head);

    // head = insert_at_end(head,10);
    // printf("linklist after insert at end operation: \n");
    // traversal(head);

    // head = delete_at_start(head,5);
    // printf("linklist after deletion at end operation: \n");
    // traversal(head);

    // head = delete_at_middle(head,3);
    // printf("linklist after deletion at middle operation: \n");
    // traversal(head);


    return 0;
}
