#include<iostream>
using namespace std;

void mergeArrays(int arr1[],int size1,int arr2[],int size2, int ans[]){
    int i=0;
    int j=0;
    int k=0;
    
    while(i<size1 && j<size2){
        if(arr1[i]>=arr2[j]){
            ans[k] = arr2[j];
            k++;
            j++;
        }else{
            ans[k] = arr1[i];
            k++;
            i++;
        }
    }
    while(i<size1){
        ans[k] = arr1[i];
        k++;
        i++;
    }
    while(j<size2){
        ans[k] = arr2[j];
        k++;
        j++;

    }
}
int main(){
    int arr1[] = {1,4,7,10};
    int arr2[] = {2,3,7,9};
    int ans[8];
    mergeArrays(arr1,4,arr2,4,ans);
    for(int i=0;i<8;i++){
        cout << ans[i] << " ";
    }
}