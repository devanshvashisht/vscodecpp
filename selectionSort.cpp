#include<iostream>
using namespace std;
void selectionSort(int input[],int n){
    for(int i=0;i<n-1;i++){
    // find minimum element in array
    int min = input[i], minIndex = i;
    for(int j=i+1;j<n;j++){
        if(input[j]<min){
            min = input[j];
            minIndex = j;
        }
    }
    // swap the elements
    int temp= input[i];
    input[i] = min;
    input[minIndex] = temp ;
    }
}

int main(){
    int arr[5]={1,4,2,8,3};
    int n= 5;
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}