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
void length_of_linkedlist(struct node **head){
    int count=0;
    if(*head==NULL){
        printf("Linked list is empty");
        return;
    }
    while(*head!=NULL){
        count++;
        *head=(*head)->link;
    }
    printf("Number of nodes=%d",count++);
}
int main(){
    struct node *head=NULL;
    insert(&head,55);
    insert(&head,88);
    length_of_linkedlist(&head);
}