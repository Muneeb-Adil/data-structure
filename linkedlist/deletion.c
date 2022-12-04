#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void createlinkedlist(struct node **head,int count){
    for(int i=0;i<count;i++){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->link=*head;
        *head=newnode;
    }
}
void deletefromstart(struct node **head){
    struct node *temp;
    temp=*head;
    *head=(*head)->link;
    free(temp);
}
void pop(struct node **head){
    struct node *temp,*current;
    temp=*head;
    while(temp->link!=NULL){
        current=temp;
        temp=temp->link;
    }
    current->link=NULL;
    free(temp);
}
void delete_specific_node(struct node **head,int data){
    struct node *temp;
    struct node *current= *head;
    while (current -> link != NULL) {
        if (current -> link -> data == data) {
            temp = current -> link;
            current -> link = current -> link -> link;
            free(temp);
        } 
        else{
            current = current -> link;
        }
    }
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
int main()
{
    struct node *head=NULL;
    createlinkedlist(&head,5);
    // deletefromstart(&head);
    // pop(&head);
    delete_specific_node(&head,5);
    printnodes(head);
}

