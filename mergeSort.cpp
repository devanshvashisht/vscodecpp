#include<iostream>
using namespace std;
void merge(int arr[], int s , int e){
    int mid = (s+e)/2;
    int *temp = new int[e-s+1];
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            i++;
            k++;

        }else {
            temp[k] = arr[j];
            k++;
            j++;
        }

    }
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        k++;
        j++;
    }

    int m=0;
    while(m<k){
        arr[s+m] = temp[m];
        m++;

    }
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){
    int a[]= {1,2,6,3,9,4};
    mergeSort(a, 0, 5);
    for(int i =0;i<6;i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}