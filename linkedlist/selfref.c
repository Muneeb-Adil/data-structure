#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

int main(){
    node n1,n2;
    n1.data=65;
    n1.link=NULL;
    n2.data=66;
    n2.link=NULL;
    n1.link=&n2;
    printf("%d",n1.link->data);
    return 0;
}
