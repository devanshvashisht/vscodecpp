#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){

    for (int i=0;i<n;i++){
        if (arr[i]==key){
            return i;
        }
        
    }
    return -1;
}

int main(){
    int n;
    cout << "enter the number of elements in the array" << endl;
    cin >>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout << "enter the element";
        cin >> arr[i];

    }
    int key;
    cout << "Enter the element you want to find" << endl;
    cin >> key;

    cout << linearSearch(arr,n,key) << endl;

    return 0;
}