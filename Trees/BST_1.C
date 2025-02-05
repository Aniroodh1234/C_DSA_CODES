#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    
};

//creation of node in a BST
struct node* createnode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n -> data = data;
    n -> right = NULL;
    n -> left = NULL;
    return n;
}
//to see whether the given tree is a BST or not
int isBST(struct node*root){
    static struct node*prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        else if(prev!=NULL && root->data < prev -> data){
            return 0;
        }
        prev = root;
        isBST(root-> right);
    }
    else{
        return 1;
    }
}

//inorder traversal of BST
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root -> left);
        printf("%d ",root-> data);
        inorder(root -> right);
    }
}
//preorder traversal of BST
void preorder(struct node*root){
    if(root!=NULL){
        printf("%d ",root-> data);
        inorder(root -> left);
        inorder(root -> right);
    }
}
//postorder traversal of BST
void postorder(struct node*root){
    if(root!=NULL){
        inorder(root -> left);
        inorder(root -> right);
        printf("%d ",root-> data);
    }
}
//searching a node in BST
struct node* searchnode(struct node*root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(root-> data==data){
        return root;
    }
    else if(root->data < data){
        return searchnode(root->right,data);
    }
    else{
        return searchnode(root->left,data);
    }
}
//insertion operation in BST
void insert(struct node*root, int data){
    struct node*prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data == data){
            return;
        }
        else if(root->data < data){
            root = root->right;
        }
        else if(root->data > data){
            root = root->left;
        }
    }
    struct node*newnode = createnode(16);
    if(data<prev->data){
        prev -> left = newnode;
    }
    else{
        prev -> right = newnode;
    }
}

//code for inorder predesscor
struct node* inorderpredesscor(struct node* root){
    root = root->left;
    while(root->right!=NULL){
        root = root -> right;
    }
    return root; 
    
}
//Deletion operation in BST
struct node* deletenode(struct node*root, int data){
    struct node* ipre;
    if(root==NULL){
        return NULL;
    }
    else if(root->left == NULL && root-> right == NULL){
        free(root);
        return NULL;
    }
    else if(root -> data < data){
        root -> right = deletenode(root->right,data);
    }
    else if(root->data > data){
        root -> left = deletenode(root-> left, data);
    }
    else{
        ipre = inorderpredesscor(root);
        root ->data = ipre-> data;
        root->left = deletenode(root->left,ipre->data);
    }
}


int main(){
    struct node* p = createnode(10);
    struct node* p1 = createnode(5);
    struct node* p2 = createnode(15);
    struct node* p3 = createnode(2);
    struct node* p4 = createnode(7);
    struct node* p5 = createnode(12);
    struct node* p6 = createnode(20);

    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    p2 -> left = p5;
    p2 -> right = p6;
//to check whether a tree is a BST or not
    if (isBST(p)) {
        printf("The tree is a BST.\n");
    } else {
        printf("The tree is not a BST.\n");
    }

//TRAVERSAL IN BST
    printf("inorder traversal: ");
    inorder(p);
    printf("\npreorder traversal: ");
    preorder(p);
    printf("\npostorder traversal: ");
    postorder(p);

//SEARCH OPERATION IN BST
    struct node* x = searchnode(p,12);
    if(x == NULL){
        printf("\nelement not found");
    }
    else{
        printf("\nelement found: %d",x->data);
    }

//insertion in BST
    insert(p,16);
    printf("\n%d", p->right->right->left->data);

//DELETIOMN IN BST
    printf("\ntree before deletion: ");
    inorder(p);
    deletenode(p,16);
    printf("\ntree after deletion: ");
    inorder(p);
    return 0;
}
