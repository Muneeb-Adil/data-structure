#include<iostream>
using namespace std;
#include<string>

string prime(int num){
    int flag=0;
    if(num==0 || num==1){
        flag=1;
    }
    for(int i=2;i<=num/2;i++){
        if(num%i==0){
            flag=1;
        }
    }
    if(flag==0){
        return " is prime";
    }
    else{
        return " is not prime";
    }
}

int main(){
    for(int i=0;i<=10;i++){
        string s = prime(i);
        cout<<i<<s<<endl;
    }
}