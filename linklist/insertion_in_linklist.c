#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
//linklist traversal code
void traversal(struct node* head){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("element: %d\n",ptr->data);
        ptr = ptr -> next;
    }
    
}

// //insertion at the beigning
// struct node* insert_at_beg(struct node* head, int data){
//     struct node* ptr = (struct node*)malloc(sizeof(struct node));
//     ptr -> data = 32;
//     ptr -> next = head;
//     head = ptr;
//     return head; 
// }

//insertion at the middle of the linklist 
struct node* insert_at_middle(struct node*head, int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    ptr -> data = data;
    int i = 0;
    while(p != NULL && i != index-1){
        p = p -> next;
        i++;
    }
    if(p==NULL){        //this statement means we did not find the element in the loop  
        printf("index out of bound");
        free(ptr);
    }

    ptr -> next = p -> next;
    // ptr -> data = data;
    p -> next = ptr;
    return head;
}

//insertion at the end of the linklist
// struct node* insert_at_end(struct node* head, int data){
//     struct node* ptr = (struct node*)malloc(sizeof(struct node));
//     struct node* p = head;
//     ptr -> data = data;
//     while(p -> next != NULL){
//         p = p -> next;
//     }
//     ptr -> next = p -> next;
//     p -> next = ptr;
//     return head;

// }
int main(){
    int index,data;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    head->data = 4;
    head ->next = second; 

    second->data = 6;
    second->next = third;

    third->data = 9;
    third->next = fourth; 

    fourth->data = 10;
    fourth->next = fifth; 

    fifth->data = 1;
    fifth->next = NULL; 

    // printf("\nelements before insertion\n ");
    // traversal(head);
    // printf("\nelements after insertion\n ");
    // head = insert_at_beg(head,32);
    // traversal(head);
    
    printf("\nelements after insertion\n ");
    head = insert_at_middle(head,32,3);
    traversal(head);

    // printf("\nelements after insertion\n ");
    // head = insert_at_end(head,32);
    // traversal(head);


    return 0;


}