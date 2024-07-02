#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double geometricSum(int k){
    if(k==0){
        return 1;
    }
    double smallerSum = geometricSum(k-1);
    return 1/pow(2,k) + smallerSum;
}
int main(){
    int k;
    cout << "enter the value of k" << endl;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k);
}