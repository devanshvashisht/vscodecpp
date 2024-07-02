#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int count =0;
    for(int i=s+1;i<=e ;i++){
        if (arr[i] <= arr[s]){
            count ++;
        }

    }
    int temp1 = arr[s+count];
    arr[count+s] = arr[s];
    arr[s] = temp1;
    int partitionIndex = s+count;
    int x = arr[partitionIndex];
    int i =s;
    int j = e;
    
    while(i<partitionIndex && j>partitionIndex){
        if(arr[i] <= x){
        i++;
    }
    else if (arr[j] > x ){
        j--;
    }
    else{
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    }
    return partitionIndex;
}

void quickSort(int arr[], int s ,int e){
    if(s>=e){
        return;
    }
    int c = partition(arr, s,e);
    quickSort(arr, s , c-1);
    quickSort(arr,c+1, e);
}

int main(){
    int a[] ={2,1,7,3,0,6,9,8};
    quickSort(a,0,7);
    for(int i=0;i<8;i++){
        cout << a[i]<< " ";
    }

}