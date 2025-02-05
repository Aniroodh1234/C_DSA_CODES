#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
//node creation in tree
struct node* createnode(int data){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
}
//preorder traversal in tree
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}
//postorder traversal in tree
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ",root -> data);
    }
}
//inorder traversal in tree
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root -> left);
        printf("%d ",root -> data);
        inorder(root -> right);
    }
}

int main(){
    struct node* p = createnode(2);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(4);
    struct node* p3 = createnode(5);
    struct node* p4 = createnode(6);

    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;

    printf("preorder traversal is: ");
    preorder(p);
    printf("\npostorder traversal is: ");
    postorder(p);
    printf("\ninorder traversal is: ");
    inorder(p);
    return 0;
}


