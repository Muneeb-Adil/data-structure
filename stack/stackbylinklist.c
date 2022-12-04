#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* top=NULL;
void push(int value){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->link=top;
    top=newnode;
}
void pop() {
    if (top == NULL) {
        printf("\nList is empty");
    } 
    else{
        struct node *temp = top;
        printf("\nPopped element is :%d",temp->data);
        top=top->link;
        free(temp);
    }
}
void display() {
    if (top == NULL) {
        printf("\nList is empty");
    }
    else{
        printf("\nElements in stack are:");
        struct node* temp = top;
        while(temp!= NULL) {
            printf("\n%d", temp->data);
            temp = temp->link;
        }
    }
}
void peek(){
    if(top == NULL){
        printf("\nList is empty");
    }
    else{
        printf("\nTop most element is:%d",top->data);
    }
}

int main(){
    push(3);
    push(4);
    push(5);
    peek();
    display();
    pop();
    peek();
    display();
}




