#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

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
void createlinkedlist(struct node **head,int count){
    for(int i=0;i<count;i++){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->link=*head;
        *head=newnode;
    }
}

int main()
{
    struct node *head=NULL;
    createlinkedlist(&head,5);
    printnodes(head);
}
