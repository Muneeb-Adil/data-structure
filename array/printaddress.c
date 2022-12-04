#include<stdio.h>
int main(){
    const int len=10;
    int array[len];
    for(int i=0;i<len;i++){
        printf("Address of array element %d is %u \n",i+1,&array[i]);
    }
    printf("Integar size in system %d \n",sizeof(int)); // int = 4 bytes
    printf("Array size %d \n",sizeof(array)); //number of elements*sizeofdatatype=10*4=40
    printf("Number of elements in an array %d \n",sizeof(array)/sizeof(array[0])); // 40/4=10
    printf("Base address is %u \n",array); 
}