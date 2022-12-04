#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int **TDA;
    int NOR;
    int NOC;
    printf("Enter number of rows :");
    scanf("%d",&NOR);
    printf("Enter number of columns:");
    scanf("%d",&NOC);
    TDA=(int **)malloc(NOR*sizeof(int *));
    for(int i=0;i<NOR;i++){
        TDA[i]=(int *)malloc(10*sizeof(int));
        for(int j=0;j<NOC;j++){
            printf("Enter element");
            scanf("%d",&TDA[i][j]);
            printf("Address of row number %d and column number %d is %d   Value:%d\n",i+1,j+1,&TDA[i][j],TDA[i][j]);
        }
    }
}