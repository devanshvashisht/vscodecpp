#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int countPairs(vector<pair<int,int> > a){
    int count=0;
    for (int i=0; i!= a.end();i++){
        if(a[i].first > a[i].second){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter the number of pairs"<< endl;
    cin >> n;
    vector <pair<int,int> > a(n);
    for (int i=0;i<n;i++){
        cin >>a[i].first>> a[i].second;
    }
    cout << countPairs(a);
    return 0;
}