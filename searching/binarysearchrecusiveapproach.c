#include<stdio.h>
#include<conio.h>
int BinarySearch(int arr[],int data,int left,int right){
    int mid=(left+right)/2;
    if(left<=right){
        if(arr[mid]==data){
            return mid;
        }
        else if(arr[mid]>data){
            return BinarySearch(arr,data,left,mid-1);
        }
        else{
            return BinarySearch(arr,data,mid+1,right);
        }
    }  
    return -1;
}
int main(){
    int arr[]={4,6,8,12,34,56,78,90,456,654};
    int length=sizeof(arr)/sizeof(arr[0]);
    int index = BinarySearch(arr,56,0,length-1);
    if(index!=-1){
        printf("Element found at index %d",index);
    }
    else{
        printf("Element not found in given array");
    }
}

