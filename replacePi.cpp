#include<iostream>
using namespace std;

void replacePi(char s[]){
    if(s[0]=='\0' || s[1] == '\0'){
        return;
    }
    int lastIndex = 0;
    if(s[0] != 'p' || s[1] != 'i'){
        replacePi(s+1);
    } else{
        while(s[lastIndex]!= '\0'){
            lastIndex++;
        }
    }
    while(lastIndex>=2){
        s[lastIndex+2] =s[lastIndex];
        lastIndex--;  
    }
    s[0] = '3';
    s[1] = '.';
    s[2] = '1';
    s[3] = '4';
    replacePi(s+4);
}

int main(){
    char input[1000];
    cin >> input;
    replacePi(input);
    cout << input << endl;

}