#include<iostream>
using namespace std;
int staircase(int n){
    if(n==0){
        return 1;
    }else if (n<0){
        return 0;
    } else {
        return staircase(n-1) + staircase(n-2) + staircase (n-3);
    }
}
int main(){
    int n;
    cout << "enter the number of stairs" << endl;
    cin >> n;
    cout << staircase(n) << endl;

}