#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void add(int graph[][4], int u, int v , int x){
    graph[u][v] = x;
}
void print(int graph[][4], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

void floyd(int graph[][4],int n){
    int dis[4][4];
    for(int m=0;m<n;i++){
        for(int a = 0;a<n;a++){
            dis[m][a] = graph[m][a];
        }
    }
    print(dis,4);

    for(int k=0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[k][j] != INT_MAX && dis[i][k]!= INT_MAX && dis[i][k] + dis[k][j] < dis[i][j])
                dis[i][j] = dis[i][k] + dis [k][j];
            }
        }
    }

    for(int i = 0;i<4;i++){
        for(int j=0;j<4;j++){
            if(dis[i][j]==INT_MAX){
                cout << inf;
            }else{
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool isSafe(int ** arr, int x, int y , int n){
    for(int row = 0;row < n;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    int row = x;
    int col = y;
    while(row>=0 && col >= 0){
        if(arr[row][col]==1){
            return false;
        }
        row --;
        col --;
    }

    row = x;
    col = y;

    while(row >=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row --;
        col++;
    }
    return true;
}

bool nQueen(int ** arr, int x, int n){
    if(x>=n){
        return true;
    }

    for(int col = 0; col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;

            if(nQueen(arr,x,col,n)){
                return true;
            }

            arr[x][col] = 0;
        }
    }
}