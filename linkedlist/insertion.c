#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void insert(struct node **head,int data){   //address of a pointer variable stores in double pointer
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=*head;
    *head=newnode;
}
void append(struct node **head,int data ){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    temp=*head;
    if(*head==NULL){
        *head=newnode;
        return ;
    }
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    return;
}
void insert_specific_position(struct node *temp,int data){
    if(temp==NULL){
        printf("The given previous node cannot be null");
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=temp->link;
    temp->link=newnode;
}
void printnodes(struct node *head){
    if(head==NULL){
        printf("Linked list is empty");
        return;
    }
    printf("The linked list is: \n");
    while(head!=NULL){
        printf("%d ->",head->data);
        head=head->link;
    }
}
  
int main(){
    struct node *head=NULL;
    append(&head,55);
    append(&head,66);
    insert(&head,22);
    insert(&head,33);
    insert_specific_position(head,77);
    printnodes(head);
}