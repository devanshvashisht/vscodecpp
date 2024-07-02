#include<iostream>
using namespace std;

int sumOfdigits(int n){
    if (n==0){
        return 0;
    }

    int smallSum = sumOfdigits(n/10);
    return n%10 + smallSum;
}


int main(){
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout << sumOfdigits(n);
}

