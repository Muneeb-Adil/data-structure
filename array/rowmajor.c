#include<stdio.h>
#include<time.h>
#include<stdint.h> // for typecast (int *) into int 
int main(){
    time_t seconds1,seconds2;
    seconds1=time(NULL);
    int ROW,COLUMN,DIM;
    printf("Enter numbers of 3D arrays:");
    scanf("%d",&DIM);
    printf("Enter number of 2D arrays:");
    scanf("%d",&ROW);
    printf("Enter number of 1D arrays:");
    scanf("%d",&COLUMN);
    int array[DIM][ROW][COLUMN];
    uintptr_t p = (uintptr_t)array;  //saves address of array first element into p
    int number_of_elements=DIM*ROW*COLUMN;
    int space=sizeof(int)*number_of_elements;
    printf("Total number of elements in array is:%d \n",number_of_elements);
    printf("Total space occupied by array is:%d bytes \n",space);
    printf("Enter Elements: \n");
    for(int i =0; i<DIM;i++){
        for(int j=0;j<ROW;j++){
            for(int k=0; k<COLUMN; k++){
            scanf("%d \n",&array[i][j][k]);
            }
        }
    }
    seconds2=time(NULL);
    int time=seconds2-seconds1;
    printf("Time consumed:%d \n",time);
    printf("Display array \n");
    for(int i =0; i<DIM;i++){
        for(int j=0;j<ROW;j++){
            for(int k=0; k<COLUMN; k++){
            printf("Element at index array[%d][%d][%d]=%d ",i,j,k,array[i][j][k]);
            printf("Address of array[%d][%d][%d]=%p \n",i,j,k,&array[i][j][k]); 
            printf("%p \n",p+(((i*ROW*COLUMN)+(j*COLUMN)+k)*sizeof(int)));
            }
        }
    }
}