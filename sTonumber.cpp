#include<iostream>
#include<cmath>
using namespace std;
int stringTonumber(char input[]){
    if(input[1]=='\0'){
        int a = input[0];
        return a - 48;
    }
    int smallNumber = stringTonumber(input+1);
    int length =0;
    for (int i=0;input[i] != '\0';i++){
        length ++;
    }
    int a = input[0] - 48;
    return a* pow(10, length -1) + smallNumber; 

}
int main(){
    char input[1000];
    cout << "Enter the number" << endl;
    cin >> input;
    cout << stringTonumber(input) << endl;
}