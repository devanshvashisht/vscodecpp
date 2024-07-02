#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main(){
    unordered_map<string, int> map;
    //insert
    pair<string,int> p("abc",100);
    map.insert(p);
    map["def"] = 1;

    //find
    cout << map["abc"] << endl;
    cout << map.at("abc");
    //check presence count function used 
}


\