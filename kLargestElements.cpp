#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void kLargestelements(int arr[], int output[], int n, int k){
   sort (arr, arr+n);
   int count=0;
   for (int i= n-k ; i<n; i++){
      output[count++] = arr[i];
   }
   reverse(output, output+k);

}
int main(){
   int t;
   cout << "Enter the number of test cases" << endl;
   cin >> t;
   for (int m=t;m>0;m--){
      int n,k;
      int output[k];
      cout << "Enter the number of elements of array" << endl;;
      cin >> n;
      cout << "Enter the number of integers" << endl;
      cin >> k;
      int arr[n];
      for (int i=0; i<n ; i++){
         cin >> arr[i];
      }
      kLargestelements(arr,output,n,k);

      for (int i=0; i<k;i++){
         cout << output[i] << " ";
      }
   }
   
}