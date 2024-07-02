#include<iostream>
using namespace std;
void rotate(int arr[], int d , int n ){
    int temp[n];
    int index =0;
    for(int i=d;i<n;i++){
        temp[index] = arr[i];
        index++;
    }
    for(int j=0;j<d;j++){
        temp[index]=arr[j];
        index++;
    }
    for(int k=0;k<index;k++){
        arr[k] = temp[k];
    }
}
int main(){
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int d;
    cout << "enter the value of d" << endl;
    cin >> d;
    
    rotate(arr,d, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}