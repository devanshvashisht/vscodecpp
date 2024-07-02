#include<iostream>
using namespace std;

bool checkNumber(int input[], int size , int x){
    if(input[0] == x){
        return true;
    }
    bool checkSmaller = checkNumber(input +1, size -1 , x);
    return checkSmaller;
}
int main(){
    int n;
    cout << "Enter the number of elements"<< endl;
    cin >> n;
    int x;
    cout << "Enter the element you want to find" << endl;
    cin >> x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << checkNumber(arr, n ,x);
}