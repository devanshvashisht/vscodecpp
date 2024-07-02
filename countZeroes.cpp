#include<iostream>
using namespace std;

int countZeroes(int n){
    if(n==0){
        return 0;
    }
    int digit = n%10;
    if(digit==0){
        return 1+ countZeroes(n/10);
    }
    else {
        return countZeroes(n/10);
    }
}
int main(){
    int n;
    cout << "Enter the number" <<endl;
    cin >>n;
    cout << countZeroes(n);

}