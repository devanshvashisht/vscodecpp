#include<iostream>
using namespace std;
int sumOfelements(int input[], int n){
    if(n==0){
        return 0;
    }
    int smallerSum = sumOfelements(input +1 , n-1);
    return input[0] + smallerSum;
}
int main(){
    int t;
    cout << "Enter the number of test cases" << endl;
    cin >> t;
    for(int i=t; i>0; i--){
        int n;
        cout << "Enter the size of array" << endl;
        cin >> n;
        int arr[n];
        for (int j = 0;j<n;j++){
            cin >> arr[j];
        }
        cout << "The sum of elements is" << " " << sumOfelements(arr , n);
    }
}