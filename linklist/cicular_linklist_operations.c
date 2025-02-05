#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// traversal
void traversal(struct node* head){       //logic--> already head is pointed to ptr so we have to print the first element to start it from
                                        // second so that loop work properly
    struct node* ptr = head;
    printf("element: %d\n",ptr->data);
    ptr = ptr->next;
    while(ptr != head){
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }

}
// insertion at the beigning of a circular link list
struct node* insertion_at_first(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head -> next;
    while(p -> next != head){
        p = p -> next;
    }
    p -> next = ptr;
    ptr  -> next = head;
    head = ptr;
    return head;
}

// insertion of element at a particular index of a circular linklist
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
    p -> next = ptr;
    return head;
}

// insertion of element at the end of the circular linklist
struct node* insert_at_end(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head -> next;
    ptr -> data = data;
    while(p -> next != head){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = head;
    return head;
}

//deletion of element from the first of the linklist
struct node* delete_at_first(struct node* head){
    struct node* ptr = head;
    struct node* p = head -> next;
    while(p -> next != head){
        p = p -> next;
    }
    head = head -> next;
    p -> next = head;
    free(ptr);
    return head;
}

// deletion of element at a particular index
struct node* delete_at_index(struct node* head,int index){
    struct node* ptr = head;
    struct node* p = head -> next;
    int i = 0;
    while( i != index -1){
        p = p -> next;
        ptr = ptr -> next;
        i++;
    }
    ptr -> next = p -> next;
    free(p);
    return head;
}
// deletion at the end of the circular linklist
struct node* delete_at_end(struct node* head){
    struct node* ptr = head;
    struct node* p = head -> next;
    int i = 0;
    do{
    p = p -> next;
        ptr = ptr -> next;
    }
    while(p -> next != head);
    ptr -> next = head;
    free(p);
    return head;
}


int main(){

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
    fifth->next = head; 


    // printf("before insertion\n");
    // traversal(head);

    // printf("after insertion:\n");
    // head = insertion_at_first(head,12);
    // traversal(head);

    // printf("\nelements after insertion\n ");
    // head = insert_at_middle(head,32,2);
    // traversal(head);

    // printf("\nelements after insertion\n ");
    // head = insert_at_end(head,12);
    // traversal(head);

    printf("before deletion\n");
    traversal(head);
    
    // printf("\nelements after deletion\n ");
    // head = delete_at_first(head);
    // traversal(head);

    // printf("\nelements after deletion\n ");
    // head = delete_at_index(head,3);
    // traversal(head);

    printf("\nelements after deletion\n ");
    head = delete_at_end(head);
    traversal(head);
    return 0;

}
