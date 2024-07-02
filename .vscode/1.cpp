#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool isCorrect(int arr[][9], int x, int y, int v){
    for(int i=0;i<9;i++){
        if(arr[i][y]==v){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(arr[x][j]==v){
            return false;
        }
    }
    
    
}
int main(){

}