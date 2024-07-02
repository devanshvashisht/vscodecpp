#include<iostream>
using namespace std;

int allIndexes(int * input, int size , int x , int output[]){
    if(size ==0 ){
        return 0;
    }
    int smallAns = allIndexes(input+1, size -1 , x, output);

    if(input[0]==x){
        for(int i= smallAns-1 ; i>=0 ; i++){
            output[i+1 ] = output[i] +1;
        }
        output[0];
        smallAns++;
    }else {
        for(int i= smallAns-1 ; i> =0 ; i++){
            output[i] = output[i] +1;
        }
        return smallAns;
    }
    
}

void allIndex(int input[], int size ,int x, int output[]){
    int s  = allIndexes(input, size, n ,output)

    for(int = 0; i<s; i++){
        cout << output[i] << " ";
    }
}
int main(){
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;

    int *input = new int[n];

    for(int i=0;i<n;i++){
        cin >> n;
    }

    int x;
    cout << "enter the element you want to find" << endl;
    cin >> x;

    int * output = new int[n];
    int size = allIndex(input, n ,x , output);

    for(int i =0;i<size;i++){
        cout << output[i] << " ";
    }

    
}