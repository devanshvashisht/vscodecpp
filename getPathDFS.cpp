#include<iostream>
#include<vector>
using namespace std;

vector<int> getPathDFS(bool ** edges, int n, bool * visited, int v1,int v2){
    vector<int> path;
    if(v1==v2){
        path.push_back(v1);
        return path;
    }
    for(int i=0;i<n;i++){
        if(i==v1){
            continue;
        }
        if(visited[i]){
            continue;
        }
        if(edges[v1][i]){
            visited[i] = true;
            path = getPathDFS(edges,n,visited,i,v2);
            if(path.size()){
                path.push_back(v1);
                return path;
            }
        }
    }
    return path;
}
vector<int> getPathBFS(bool ** edges, int n, bool * visited, int v1 , int v2){
    
}

int main(){
    int n;
    int e;
    cin >> n >> e;
    bool ** edges = new bool* [n];
    for(int i=0;i<n;i++){
        edges[i] = new bool[n];
        for(int j=0;j<n;j++){
            edges[i][j] = false;
        }

    }

    for(int i=0;i<e;i++){
        int f,s;
        cin >> f >> s;
        edges[f][s]=true;
        edges[s][f]=true;
    }

    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int v1, v2;
    cin >> v1 >> v2;
    visited[v1] = true;
    vector<int> path = getPath(edges, v, visited, v1, v2);
    if (path.size())
    {
        for (int  i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    return 0;
}    