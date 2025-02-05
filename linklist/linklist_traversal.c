#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* traversal(struct node* head){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    return ptr;
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
    fifth->next = NULL; 

    head = traversal(head);
    
    return 0;

}
