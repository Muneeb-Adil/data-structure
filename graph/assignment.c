#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *ptr=NULL;
    int V,E;
    ptr=fopen("graph.txt","r");
    if(ptr==NULL){
        printf("No File Exist");
        exit(1);
    }
    fscanf(ptr,"%d",&V);
    fgetc(ptr);
    fscanf(ptr,"%d",&E);
    printf("%d %d",V,E);
    int G[V][E];
    char data[5];
    int line=0;
    while(!feof(ptr)){
        fgets(data[line],20,ptr);
        printf(data);
        line++;
    }
    fclose(ptr);
}
