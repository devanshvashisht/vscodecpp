#include<iostream>
using namespace std;


int power(int x, int n){
    if(n==0){
        return 1;
    }
    return x * power(x,n-1);
}
int main(){
    int x,n;
    cout << "Enter the number" << endl;
    cin >> x;
    cout << "Enter the power" << endl;
    cin >> n;
    cout << power(x,n);
    
}