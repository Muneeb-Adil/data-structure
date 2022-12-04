#include<iostream>
using namespace std;
void BubbleSort(int array[],int length){
    for(int passes=0;passes<length-1;passes++){
        int flag=0;
        for(int comparisions=0;comparisions<length-1-passes;comparisions++){
            if(array[comparisions]>array[comparisions+1]){
                int temp=array[comparisions];
                array[comparisions]=array[comparisions+1];
                array[comparisions+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"Given array is already sorted"<<endl;
            break;
        }
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
    BubbleSort(array,length);
    printArray(array,length);
}
