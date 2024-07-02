#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int val){
    for (int i=0;i<n && arr[i]<=val;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]= {1,2,4,3,5,6};
    int key = 4;
    cout << linearSearch(arr,6,key);
}