#include<iostream>
using namespace std;


int multiply(int m, int n){
    if(n==0){
        return 0;
    }
    return m + multiply(m , n-1);
}

int main(){
    int m,n;
    cout << "Enter the numbers you want to multiply" << endl;
    cin >> m >> n;
    cout << multiply(m,n);
}