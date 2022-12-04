#include<iostream>
using namespace std;
void SelectionSort(int array[],int length){
    for(int i=0;i<length-1;i++){
        int min=i;
        for(int j=i+1;j<length;j++){
            if(array[j]<array[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=array[min];
            array[min]=array[i];
            array[i]=temp;
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
    int array[]={45,76,54,23,90,334,12,34,76,54};
    int length=sizeof(array)/sizeof(array[0]);
    cout<<"ARRAY BEFORE SORTING"<<endl;
    printArray(array,length);
    cout<<"ARRAY AFTER SORTING"<<endl;
    SelectionSort(array,length);
    printArray(array,length);
}