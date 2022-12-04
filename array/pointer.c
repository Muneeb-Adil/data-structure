#include<stdio.h>
#include<conio.h>
int main(){
int a[4]={2,4,6,8};
int *p;
p=a;
printf("%p \n",a); //&a //&a[0] //address of a[0]
printf("%p \n",a+1);      //address of a[1]
printf("%p \n",&a[2]);      //address of a[2]
printf("%p \n",&a[3]);      //address of a[3]
printf("%p \n",&p);    // Adress of pointer
printf("%p \n",p);     //address of a[0]
printf("%p \n",p+1);   //address of a[1]
printf("%p \n",p+2);   //address of a[2]
printf("%p \n",p+3);   //address of a[3]
printf("%d \n",*a);     // a[0] //value at a[0]
printf("%d \n",*(a+1)); // a[1] //value at a[1]
printf("%d \n",2[a]); // a[2] //value at a[2]
printf("%d \n",*(a+3)); // a[3] //value at a[3]
printf("%d \n",*p);     // a[0] //value at a[0]
printf("%d \n",*(p+1)); // a[1] //value at a[1]
printf("%d \n",2[p]); // a[2] // p[2] //value at a[2]
printf("%d \n",*(p+3)); // a[3] //value at a[3]
}


