#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node* create(){
    int x;
    printf("\nDo you want to create a node (0,1)");
    scanf("%d",&x);
    if(x==1){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&newnode->data);
        printf("Enter left child of %d",newnode->data);
        newnode->left=create();
        printf("Enter right child of %d",newnode->data);
        newnode->right=create();
        return newnode;
    }
}
// Preorder traversal
void preorderTraversal(struct node *node) {
    if (node == NULL){
    return;
    }
    printf("%d ->",node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(struct node *node) {
    if (node == NULL){
    return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ->",node->data); 
}

// Inorder traversal
void inorderTraversal(struct node *node) {
    if (node == NULL){
    return;
    }
    inorderTraversal(node->left);
    printf("%d ->",node->data); 
    inorderTraversal(node->right);
}

int main(){
    struct node *rootptr=NULL;
    rootptr=create();
    printf("The inorder treversal is:");
    inorderTraversal(rootptr);
    printf("\n");
    printf("The preorder treversal is:");
    preorderTraversal(rootptr);
    printf("\n");
    printf("The postorder treversal is:");
    postorderTraversal(rootptr);
    printf("\n");
}