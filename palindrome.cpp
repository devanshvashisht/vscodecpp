#include<iostream>
using namespace std;
bool checkPalindrome(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0]!=arr[size-1]){
        return false;

    }else if (arr[0]== arr[size-1]){
        return checkPalindrome(arr+1, size-2);
    }
}
int main(){
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << checkPalindrome(arr,n);
}