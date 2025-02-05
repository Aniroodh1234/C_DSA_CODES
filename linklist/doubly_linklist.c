#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prevnode;
};

//traversal in a double linklist -----> both way traversal is possible in double link list

//traversal in reverse order
void reversetraversal(struct node* head){
    struct node* ptr = head;
    while(ptr ->next != NULL){
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prevnode;

    }
}

// traversal in normal order
void normaltraversal(struct node* head){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("elements: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}


// insertion of element at first in a double linklist
struct node* insertion_at_first(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    ptr -> prevnode = NULL;
    return head;

}
//insertion of elements at the given index of a doubly linklist
struct node* insert_at_middle(struct node* head, int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr -> data = data;
    int i = 0;
    while(i < index -1 &&  p -> next != NULL){
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    ptr -> prevnode = p;
    if( p -> next != NULL){
        p -> next -> prevnode = ptr;
    }
    p -> next = ptr;
    return head;
}

// insertion of element at the end of a doubly linklist
struct node*insert_at_end(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data  = data;
    struct node* p = head;
    while( p -> next != NULL){
        p = p -> next;
    }
    ptr -> next = NULL;
    p -> next = ptr;
    return head;
}

// delete the element from the first of the doubly link list
struct node*delete_at_first(struct node* head){
    struct node* ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// delete a element from a particular index in a doubly link list
struct node*delete_at_index(struct node* head, int index){
    struct node* p = head;
    struct node* q = head -> next;
    int i = 0;
    while(i < index -1 ){
        p = p -> next;
        q = q -> next;
        i++;
    }
    p -> next = q -> next;
    free(q);
    return head;
}

//delete a element from the last in a doubly linklist
struct node* delete_at_end(struct node* head){
    struct node* ptr = head;
    struct node* p = head -> next;
    while(p -> next != NULL){
        p = p -> next;
        ptr = ptr -> next; 
    }
    ptr -> next = NULL;
    free(p);
    return head;
}



int main(){
    //here a pointer is created and it is pointed towards a struct node created in heap directly

    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    head->data = 4;
    head ->next = second; 
    head -> prevnode = NULL;

    second->data = 6;
    second->next = third;
    second-> prevnode = head;

    third->data = 9;
    third->next = fourth; 
    third-> prevnode = second;

    fourth->data = 10;
    fourth->next = fifth; 
    fourth -> prevnode = third;

    fifth->data = 1;
    fifth->next = NULL; 
    fifth -> prevnode = fourth;

    // printf("traversal in reverse order:\n ");
    // reversetraversal(head);
    // printf("\n");
    // printf("traversal in normal order:\n ");
    // normaltraversal(head);


    // printf("before insertion\n");
    // normaltraversal(head);

    // printf("\nafter insertion:\n");
    // head = insertion_at_first(head,12);
    // normaltraversal(head);

    // printf("\nelements after insertion\n ");
    // head = insert_at_middle(head,32,2);
    // normaltraversal(head);

    // printf("\nelements after insertion\n ");
    // head = insert_at_end(head,12);
    // normaltraversal(head);

    printf("before deletion\n");
    normaltraversal(head);
    
    // printf("\nelements after deletion\n ");
    // head = delete_at_first(head);
    // normaltraversal(head);

    // printf("\nelements after deletion\n ");
    // head = delete_at_index(head,3);
    // normaltraversal(head);

    printf("\nelements after deletion\n ");
    head = delete_at_end(head);
    normaltraversal(head);
    
    return 0;


}
