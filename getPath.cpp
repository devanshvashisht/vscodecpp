#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
    queue<int> pending;
    map<int,int> mp;
    pending.push(v1);
    visited[v1] = true;
    while(!pending.empty()){
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            if(i == pending.front()){
                continue;
            }
            if(edges[pending.front()][i]){
                pending.push(i);
                mp[i] = pending.front();
                visited[i] = true;
            }
        }
        pending.pop();
    }
    if(!visited[v2]){
        return ;
    }
    int i = v2;
    cout << v2 << " ";
    while (i != v1)
    {
        cout << m[i] << " ";
        i = m[i];
    }
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