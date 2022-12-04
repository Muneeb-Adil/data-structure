#include<iostream>
using namespace std;
class Heap{
    private:
    int index;
    int arraylength=0;
    int array[20];
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    public:
    Heap(){
        array[0]=-1;
        this->index=0;
    }
    void insert(int value){
        arraylength++;
        int index=arraylength;
        array[index]=value;
        while(index>1){
            int parent=index/2;
            if(array[parent]<array[index]){
                swap(array[parent],array[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void deletefromHeap(){
        if(arraylength==0){
            cout<<"Heap is empty";
            return;
        }
        array[1]=array[arraylength];
        arraylength--;
        int rootindex=1;
        while(rootindex<arraylength){
            int leftchildindex=2*rootindex;
            int rightchildindex=2*rootindex+1;
            if(leftchildindex<arraylength && array[rootindex]<array[leftchildindex]){
                swap(array[rootindex],array[leftchildindex]);
                rootindex=leftchildindex;
            }
            else if(rightchildindex<arraylength && array[rootindex]<array[rightchildindex]){
                swap(array[rootindex],array[rightchildindex]);
                rootindex=rightchildindex;
            }
            else{
                return;
            }
        }
    }
    void maxHeap(){
        for(int i=1;i<=arraylength;i++){
        cout<<this->array[i]<<endl;
        }
    }
};
int main(){
    Heap *obj=new Heap();
    obj->insert(1);
    obj->insert(3);
    obj->insert(5);
    obj->insert(4);
    obj->insert(6);
    obj->insert(13);
    obj->insert(10);
    obj->insert(9);
    obj->insert(8);
    obj->insert(15);
    obj->insert(17);
    cout<<"Heap elements befor deletion"<<endl; 
    obj->maxHeap();
    obj->deletefromHeap();
    cout<<"Heap elements after deletion"<<endl;
    obj->maxHeap();
}