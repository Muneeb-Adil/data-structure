#include<stdio.h>
#include<stdlib.h>
void fun(int **tlist){
    int *funlist;
    funlist=malloc(4*sizeof(int));
    for(int i=0; i< sizeof(funlist)/sizeof(funlist[0]);i++){
        funlist[i]=20;
    };
    printf("Base Address of heap %d and its value is %d \n",&funlist[0],funlist[0]);
    free(funlist);//Release memory from heap.
    printf("After deleting the relation b/w heap and funlist it gives random values i.e \n");
    printf("Base Address of heap %d and its value is %d \n",&funlist[1],funlist[1]);
}

int main(){
    int a;
    int *list;
    fun(&list); //we pass address of a pointer as argument that's why it is necessary that function parameter must be a double pointer.
}