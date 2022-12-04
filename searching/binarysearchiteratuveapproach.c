#include<stdio.h>
#include<conio.h>

int BinarySearch(int arr[],int length,int data){
    int left=0;
    int right=length-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==data){
           return mid;
        }
        else if(arr[mid]>data){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={4,6,8,12,34,56,78,90,456,654};
    int length=sizeof(arr)/sizeof(arr[0]);
    int index = BinarySearch(arr,length,12);
    if(index!=-1){
        printf("Element found at index %d",index);
    }
    else{
        printf("Element not found in given array");
    }
}
