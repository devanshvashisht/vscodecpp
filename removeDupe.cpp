#include<iostream>
#include<cstring>
using namespace std;

void removeDuplicate(char input[]){
    for(int i=1;input[i]!='\0';i++){
        if(input[i]==input[i+1]){
            for(int j =i+1;input[j]!='\0';j++){
                input[j]=input[j+1];
            }
        }
    }
}

int main(){
    char input[10];
    cin >> input;
    removeDuplicate(input);
    cout << input;
}