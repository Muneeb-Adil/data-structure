#include<stdio.h>
int main(){
    int arr[]={2,3,4};
    int count=sizeof(arr)/sizeof(arr[0]);
    printf("%d",count);
}