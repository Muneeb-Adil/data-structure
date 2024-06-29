#include<iostream>
using namespace std;
int prime[100] = {0};

void print(int n){
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<"-";
        }
    }
};

void primeSieve(int n){
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    print(n);
};

int main(){
    int size;
    cout<<"Enter size of array:";
    cin>>size;
    primeSieve(size);
};