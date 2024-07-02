#include<iostream>
using namespace std;
#include<string>
void selectionSort(int input[],int n){
    for(int i=0;i<n-1;i++){
        int min = input[i], minIndex = i;
        for(int j=i+1;j<n;j++){
            if(input[j]<min){
                min = input[j];
                minIndex = j;

            }
            int temp = input[i];
            input[i] = min;
            input[minIndex] = temp;
        }
    }
}

void bubbleSort(int input[],int n){
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
    char a[10];
    cin >> a;
    cout << a;
}