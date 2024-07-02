#include<iostream>
#include<fstream>
#include<string>
using namespace std;



int binarySearch(int arr[],int n,int val){
    int s=0;
    int e=n-1;
    while (s<=e){
        int mid=s+e/2;
        if  (arr[mid]==val){
            return mid;
        } else if (arr[mid]<val){
            s=mid+1;
        } else if (arr[mid]>val){
            e=mid-1;
        }
    }
        
    return -1;

    
}

int main(){
    string filename;
    ifstream inputfile;
    cout << "Enter filename" << endl;
    cin >> filename;
    inputfile.open(filename.c_str());


    
    if (!inputfile){
        cerr << "Error opening input ";
    }
    int n;
    inputfile>> n;
    int arr[n];
    for (int i=0;i<n;i++){
        inputfile>> arr[i];
    }
    int x;
    inputfile>> x;

    inputfile.close();
    int result = binarySearch(arr,n,x);
    cout << result << endl;
}    