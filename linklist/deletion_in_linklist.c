#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traversal(struct node* head){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
    
}

//deletion at the starting of the linklist
struct node* deletion_at_start(struct node* head){
    struct node* ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

//deletion at a particular index in a link list 
struct node* deletion_at_index(struct node* head, int index){
    struct node* p = head;
    struct node* q = head -> next;
    for(int i = 0; i < index-1; i++){
        p = p -> next;
        q = q -> next;
    }
    p -> next = q -> next;
    free(q);
    return head;
}

//delete the elments from the end in the link list
struct node* deletion_at_end(struct node* head){
    struct node* p = head;
    struct node* q = p -> next;
    while(q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }
    p -> next = NULL;
    free(q);
    return head;
}

//deletion of element at a particular node
struct node* deletion_at_node(struct node* head, int node){
    struct node* p = head;
    struct node* q = head -> next;
    while(q -> data != node && q -> next != NULL ){
        p = p -> next;
        q = q -> next;
    }
    if(q -> data == node){
        p -> next = q -> next;
        free(q);
    }

    return head;
}
int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node)); 
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node)); 
    struct node* fifth = (struct node*)malloc(sizeof(struct node)); 

    head -> data = 4;
    head -> next = second;

    second -> data = 6;
    second -> next = third;

    third -> data = 9;
    third -> next = fourth;

    fourth -> data = 10;
    fourth -> next = fifth;

    fifth -> data = 1;
    fifth -> next = NULL;

    printf("\nelemets before deletion:\n");
    traversal(head);

    // printf("\nelements after deletion:\n");
    // head = deletion_at_start(head);
    // traversal(head);

    // printf("\nelements after deletion:\n");
    // head = deletion_at_index(head,3);
    // traversal(head);

    
    // printf("\nelements after deletion:\n");
    // head = deletion_at_end(head);
    // traversal(head);

    printf("\nelements after deletion:\n");
    head = deletion_at_node(head,4);
    traversal(head);

    return 0;



}