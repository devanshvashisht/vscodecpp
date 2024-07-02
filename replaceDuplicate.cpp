#include<iostream>
using namespace std;

void replaceDuplicate(char input[]){
    if(input[0]=='\0' || input[1]=='\0'){
        return;
    }
    if(input[0]!=input[1]){
        replaceDuplicate(input+1);

    }else if(input[0]==input[1]){
        int i=0;
        for(;input[i]!='\0';i++){
            input[i]= input[i+1];

        }
        input[i]=input[i+1];
        replaceDuplicate(input);
    }
}

int main(){
    char input[1000];
    cout << "Enter the input" << endl;
    cin >> input;
    replaceDuplicate(input);
    cout << input;
}