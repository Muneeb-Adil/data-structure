#include<stdio.h>
void swap(int &a,int &b){
    int c;
    c=a;
    a=b;
    b=c;
    printf("a = %d b = %d \n",a,b);
}
int main(){
    int x=5,y=6;
    printf("Values before swap \nx = %d  y = %d \n",x,y);
    swap(x,y);
    printf("Values after swap \nx = %d  y = %d \n",x,y);
}