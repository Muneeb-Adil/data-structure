#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

int main(){
    node *head=NULL;
    node *previous;
    previous=(node *)malloc(sizeof(node));
    previous->data=45;
    previous->link=NULL;
    head=previous;
    node *current;
    current=(node *)malloc(sizeof(node));
    current->data=46;
    current->link=NULL;
    head->link=current;
    node *next;
    next=(node *)malloc(sizeof(node));
    next->data=47;
    next->link=NULL;
    head->link->link=next;
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->link;
    }
    return 0;
}