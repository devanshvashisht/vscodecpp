#include<iostream>
#include<cstring>
using namespace std;
string removeDuplicate(string str){
   int len = str.size();
   string output= ""; 
   bool isPresent = true;
   output.push_back(str[0]);
   int length = 1;
   for(int i=1;i<len;i++){
    for(int j=0;j<length;j++){
        if(str[i]!=output[j]){
            isPresent = false;
        }else{
            isPresent = true;
            break;
        }
    }
    if(!isPresent){
        output.push_back(str[i]);
        length++;

    }
   
   }
   return output;
}
int main(){
    string s;
    cin >> s;
    string output;
    s = removeDuplicate(s);
    cout << s << endl; 
}    