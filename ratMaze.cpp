#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool> > & visited, vector<vector <int> > & arr,int n){
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && visited[newx][newy]!=1 && arr[newx][newy]==1){
        return true;
    }else{
        return false;
    }
}

void solve(int x, int y, vector< vector<int> > & arr, int n, vector<string> &ans, vector<vector<bool> > &vis, string path){
    if(x==n-1 && y ==n-1){
        ans.push_back(path);
        return ;
    }
    vis[x][y] = 1;

    //D
    if(isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,arr,n,ans,vis,path+'D');
    }

    //L
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,arr,n,ans,vis,path+'L');
    }

    //R
    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,arr,n,ans,vis,path+'R');
    }

    //U
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y,arr,n,ans,vis,path+'U');
    }
    vis[x][y]=0;
}
vector <string> searchMaze(vector<vector<int> > &arr,int n){
    vector<string> ans;
    vector<vector<bool> > visited(n,vector<bool> (n,0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    
}

int main(){

}