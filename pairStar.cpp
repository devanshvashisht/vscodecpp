#include<iostream>
using namespace std;
int length(char *input){
    int length =0;
    for(int i =0;input[i]!='\0';i++){
        length ++;
    }
    return length;
}
void pairStar(char *input){
    if(input[0]=='\0' || input[1] == '\0'){
        return;
    }
    
    int len = length(input);
    if(input[0]!=input[1]){
        pairStar(input+1);
    }else if (input[0]==input[1]){
        input[len+1] = '\0';
        int i =len-1;
        for(;i>0;i--){
            input[i+1]=input[i];
        }
        input[1] = '*';
        pairStar(input+1);
        
    }
}

int main(){
    char input[1000];
    cout << "Enter the string"<<endl;
    cin >> input;
    pairStar(input);
    cout << input;
}