#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push(int val) {
   if(top>N-1){
   printf("Stack overflow");
   }
   else{
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1){
    printf("Stack underflow");
   }
   else{
      printf("\nPopped elements is %d \n",stack[top]);
      top--;
   }
}
void displaystack(){
   if(top>=0) {
      printf("Elements in stack are:");
      for(int i=top; i>=0; i--){
      printf("\n%d",stack[i]);
      }
   }
   else{
   printf("Stack is empty");
   }
}
int isFull(){
   if(top>=N-1){
      return 1;
   }
   else{
      return 0;
   }
}
int isEmpty(){
   if(top==-1){
      return 1;
   }
   else{
      return 0;
   }
}
void peek(){
   if(top==-1){
      printf("\nStack is empty");
   }
   else{
      printf("\n%d",stack[top]);
   }
}

int main() {
   push(3);
   push(4);
   push(5);
   push(2);
   push(1);
   displaystack();
   pop();
   displaystack();
   if(isFull()){
      printf("\nStack is full");
   }
   else{
      printf("\nStack is not full");
   }
   if(isEmpty()){
      printf("\nStack is empty");
   }
   else{
      printf("\nStack is not empty");
   }
   peek();
}

