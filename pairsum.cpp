#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int countPairs(vector<pair<int,int> > a){
    int count =0;
    int size = a.size();
    for(int i =0;i<size;i++){
        if(a[i].first > a[i].second){
            count ++;
        }
    }
    return count;
}


int main(){
    cout << "Enter the size of vector" << endl;
    int n;
    cin >> n;

    vector<pair<int,int> > a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;

    }
    cout << countPairs(a);

}