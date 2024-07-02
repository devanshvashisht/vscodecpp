#include<iostream>
using namespace std;

int sumOfelements(int arr[],int n,int output[]){
    int k;
    for (int i=0,j=n-1;i<j;i++,j--){
        output[k]=arr[i]+arr[j];
        k++ 
    }
    
}
int main()
{
    int arr[2000];
    int output[1000];
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];

    }
    sumOfelements(arr,n,output)
}
