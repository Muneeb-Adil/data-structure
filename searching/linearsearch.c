#include<stdio.h>
#include<conio.h>

void LinearSearch(int arr[],int length,int data){
    int flag=0;
    for(int i=0;i<length;i++){
        if(arr[i]==data){
            printf("Element found at index %d \n",i);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Element %d is not found in given array \n",data);
    }
}
int main(){
    int array[]={98,76,54,23,11,101,6,43};
    int length=sizeof(array)/sizeof(array[0]);
    LinearSearch(array,length,20);
    LinearSearch(array,length,101);
}
