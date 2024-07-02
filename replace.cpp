#include<iostream>
using namespace std;

void replaceCharacter(char input[], char X, char Y){
    if(input[0] == '\0'){
        return ;
    }
    if(input[0]!=X){
        replaceCharacter(input+1, X,Y);
    }else {
        input[0] = Y;
        replaceCharacter(input+1, X , Y);
    }
}
int main(){
    char input[10000];
    char c1, c2;
    cout << "enter the character you want to remove" << endl;
    cin >> c1;
    cout << "Enter the charecter you want to add" << endl;
    cin >> c2;
    cin >>input;
    replaceCharacter(input, c1 , c2);
    cout << input << endl;
}