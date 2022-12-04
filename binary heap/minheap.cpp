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
            if(array[parent]>array[index]){
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
            if(leftchildindex<arraylength && array[rootindex]>array[leftchildindex]){
                swap(array[rootindex],array[leftchildindex]);
                rootindex=leftchildindex;
            }
            else if(rightchildindex<arraylength && array[rootindex]>array[rightchildindex]){
                swap(array[rootindex],array[rightchildindex]);
                rootindex=rightchildindex;
            }
            else{
                return;
            }
        }
    }
    void minHeap(){
        for(int i=1;i<=arraylength;i++){
        cout<<this->array[i]<<endl;
        }
    }
};
int main(){
    Heap *obj=new Heap();
    obj->insert(35);
    obj->insert(33);
    obj->insert(42);
    obj->insert(10);
    obj->insert(14);
    obj->insert(19);
    obj->insert(27);
    obj->insert(44);
    obj->insert(26);
    obj->insert(31);
    cout<<"Heap elements befor deletion"<<endl; 
    obj->minHeap();
    obj->deletefromHeap();
    cout<<"Heap elements after deletion"<<endl;
    obj->minHeap();
}