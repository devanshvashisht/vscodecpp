#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int j=0;j<n-1;j++){
        for(int i=0;i<n-1-j;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

int main(){
    int arr[7]={1,3,2,9,5,14,6};
    bubbleSort(arr,7);
    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}