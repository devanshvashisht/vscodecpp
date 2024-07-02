#include<iostream>
using namespace std;

void removeX(char input[]){
    if(input[0] == '\0'){
        return;
    }else if (input[0]!='x'){
        removeX(input+1);
    }else {
        int i=0;
        for(;input[i]!= '\0';i++){
            input[i]= input[i+1];
        }
        input[i] = input[i+1];
        removeX(input);
    }
}

int main(){
    char input[1000];
    cin >> input;
    removeX(input);
    cout << input << endl;
}


