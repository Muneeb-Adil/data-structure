#include<iostream>
using namespace std;
int Partition(int array[],int lb,int ub){
    int start=lb;
    int end=ub;
    int pivot=array[lb];
    while(start<end){
        while(array[start]<=pivot){
            start++;
        }
        while(array[end]>pivot){
            end--;
        }
        if(start<end){
            int temp=array[start];
            array[start]=array[end];
            array[end]=temp;
        }
    }
    int temp=array[lb];
    array[lb]=array[end];
    array[end]=temp;
    return end;
}

void Quicksort(int array[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc=Partition(array,lb,ub);
        Quicksort(array,lb,loc-1);
        Quicksort(array,loc+1,ub);
    }
}
int main(){
    int array[]={7,6,10,5,9,2,1,15,7};
    int length=sizeof(array)/sizeof(array[0]);
    Quicksort(array,0,length-1);
    for(int i=0;i<length;i++){
        cout<<array[i]<<",";
    }
}