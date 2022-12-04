#include<iostream>
using namespace std;
void InsertionSort(int array[],int length){
    for(int i=1;i<length;i++){
        int temp=array[i];
        int j=i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }  
}
void printArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<",";
    }
    cout<<endl;
}

int main(){
    int array[]={596,907,23,45,555,23,43,11,56,34,21,9};
    // int array[]={2,4,6,8,10,34,67,89};
    int length=sizeof(array)/sizeof(array[0]);
    cout<<"ARRAY BEFORE SORTING"<<endl;
    printArray(array,length);
    cout<<"ARRAY AFTER SORTING"<<endl;
    InsertionSort(array,length);
    printArray(array,length);
}