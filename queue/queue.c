#include<stdio.h>
#define N 5
int queue[N];
int front,rear=-1;
void enqueue(int val){
    if(rear<N-1){
        if(front==-1){
            front++;
        }
        rear++;
        queue[rear]=val;
    }
    else{
        printf("Overflow");
    }
}
void dequeue(){
    if(front<=-1){
        printf("Underflow");
    }
    else{
        printf("\nDequeue element is:%d",queue[front]);
        front++;
    }
}
void display(){
    if(front>-1){
        printf("\nNow queue elements are:");
        for(int i=front;i<=rear;i++){
            printf("\n%d",queue[i]);
        }
    }
    else{
        printf("Queue is empty");
    }
}
void peek(){
    if(front>-1){
        printf("\nFront element is: %d",queue[front]);
    }
    else{
        printf("\nQueue is empty");
    }
}


int main(){
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    
}
