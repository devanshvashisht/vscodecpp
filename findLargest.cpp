#include<iostream>
#include<climits>
using namespace std;

int findLargest(int input[][2],int nRows, int mColumns){
    int sum = INT_MIN;
    int temp = 0;
    
    for(int i=0;i<mColumns;i++){
        for(int j=0;j<nRows;j++){
            temp = temp + input[j][i];
            
        }
        if(temp>sum){
            sum = temp;
        
        }
        temp = 0;
    }
    for(int i=0;i<nRows;i++){
        for(int j=0;j<mColumns;j++){
            temp = temp + input[i][j];
            
        }
        
        if(temp>sum){
            sum = temp;
        }
        temp = 0;
    }
    return sum;
}
int main(){
    
    int a[2][2];
    for(int i=0;i<2;i++){
        for(int j = 0;j<2;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<2;i++){
        for(int j = 0;j<2;j++){
            cout << a[i][j] << " " ;

        }
        cout << endl;
    }

    int ans = findLargest(a,2,2);
    cout << ans <<endl;
}