#include<iostream>
using namespace std;
#include<string>

////array fill by user
// int main(){
//     int array[5];
//     int n=sizeof(array)/sizeof(array[0]);
//     for(int i=0;i<n;i++){
//         cout<<"ENTER "<< i << " ELEMENT:";
//         cin>>array[i];
//     }
//     for(int i=0;i<n;i++){
//         cout<<array[i];
//     }
// }


////prime number generator
// int prime[100]={0};
// void print(int n){
//     for(int i=2;i<=n;i++){
//         if(prime[i]==0){
//             cout<<i<<"-";
//         }
//     }
// }
// void primeSieve(int n){
//     for(int i=2;i<=n;i++){
//         if(prime[i]==0){
//             for(int j=i*i;j<=n;j+=i){
//                 prime[j]=1;
//             }
//         }
//     }
//     print(n);
// }
// int main(){
//     int size;
//     cin>>size;
//     primeSieve(size);
// }



////find given number is prime or not
// void prime(int n){
//     if(n%2!=0 && n>2){
//         cout<<"Given number is prime";
//     }
//     else{
//         cout<<"Given number is not a prime";
//     }
// }
// int main(){
//     prime(23);
// }

////pattern
// int main(){
// for(int i=1;i<=5;i++){
//     for(int k=i;k<=4;k++){
//         cout<<" ";
//     }
//     for(int j=0;j<=i;j++){
//         if(j<i){
//             cout<<j+1;
//         }
//         else{
//             cout<<i;
//         }
//     }
//     cout<<endl;
// }
// }

int main(){
    int arr[]={2,3,4,5,6,6,7,2,2,8,6,65,34,2,7,8,9};
    int k=0;
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++; 
            }
        }
        if(count>=2){
            cout<<arr[i]<<endl;
            cout<<count<<endl;
        }
    }

}
