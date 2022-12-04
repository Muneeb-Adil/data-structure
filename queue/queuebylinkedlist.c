#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *front,*rear=NULL;
void enqueue(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->link=newnode;
        rear=newnode;
    }
}
void dequeue(){
    if(front==NULL){
        printf("\n Queue is empty");
    }
    else{
        struct node *temp=front;
        printf("\nDequeue element is:%d",front->data);
        front=front->link;
        free(temp);
    }
}
void peek(){
    if(front==NULL){
        printf("\n Queue is empty");
    }
    else{
        printf("\nFront element is:%d",front->data);
    }
}
void display(){
    if(rear=NULL){
        printf("\nQueue is empty");
    }
    else{
        printf("\nNow queue elements are:");
        struct node *temp=front;
        while(temp){
            printf("\n%d",temp->data);
            temp=temp->link;
        }
    }
}

int main(){
    struct node *head=NULL;
    peek();
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    enqueue(9);
    display();
    dequeue();
    display();
    peek();
    return 0;
}