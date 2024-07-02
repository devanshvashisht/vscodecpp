#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(int x){
    vector<int> v;
    while(x/10!=0){
        int a = x%10;
        v.push_back(a);
        x = x/10;
    }
    int s = v.size();
    for(int i=0;i<s/2;i++){
        if(v[i]!=v[s-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "enter the number" << endl;
    int n;
    cin >> n;
    cout << isPalindrome(n);
}

