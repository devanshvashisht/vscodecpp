#include<iostream>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

int sum(vector<int> arr, int n){
    int max = INT16_MIN;
    int min = INT16_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    
    }
    for(int j=0;j<n;j++){
        if(arr[j]<min){
            min = arr[j];
        }
    }
    int sum = max + min;
    return sum;
}
void printArray(vector<int> arr, int n){
    for(int i =0;i<n;i++){
        cout << arr[i]<<" ";
    }
}
int main(){
    int t;
    cout << "Enter the number of test cases" << endl;
    cin >> t;
    for(int i=t;i>0;i--){
        int n;
        cout <<"Enter the size" << endl;
        
        cin >> n;
        vector<int> arr(n);
        int element;
        for(int i =0;i<n;i++){
            cin >> arr[i];
        }

       int ans = sum(arr,n);
       cout << ans << endl;
    }
}