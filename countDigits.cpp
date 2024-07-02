#include<iostream>
using namespace std;

int countDigits(int n){
    if(n/10==0){
        return 1;
    }
    int smallCount = countDigits(n/10);
    return 1 + smallCount;

}
int main(){
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout << countDigits(n);   
}    