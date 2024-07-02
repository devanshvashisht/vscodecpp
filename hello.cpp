#include<iostream>
#include<fstream>
using namespace std;
int binarysearch (int arr[],int n,int x)//n is size of array, x is number we have to search
{
    int start=0;
    int end=n-1;
    
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            start=mid+1;
        }
        else{
            
            end=mid-1;
        }
        
    }return -1;

}
int main(){
     ifstream inputFile("int.txt");  // Open the input file

    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int n;
    inputFile >> n; // Read the size of the array from the file
    int arr[n];

    for (int i = 0; i < n; i++) {
        inputFile >> arr[i]; // Read array elements from the file
    }

    int x;
    inputFile >> x; // Read the target number from the file

    inputFile.close(); // Close the input file
    int result=binarysearch(arr,n,x);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

}