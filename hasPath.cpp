#include<iostream>
#include<queue>
using namespace std;
bool hasPath(bool ** edges, int n, bool * visited, int v1, int v2){
    if(v1>=n || v2>=n){
        return false;
    }
    if(v1==v2){
        return true;
    }
    if(edges[v1][v2] || edges[v2][v1]){
        return true;
    }
    queue<int> pending;
    pending.push(v1);
    visited[v1]=true;
    while(!pending.empty()){
        for(int i=0;i<n;i++){
            if(i==pending.front()){
                continue;
            }
            if(visited[i]){
                continue;
            }
            if (edges[pending.front()][i])
            {
                pending.push(i);
                visited[i] = true;
            }
            pending.pop();
            if (visited[v2]){
                return true;
            }

    }
    return false;

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

    int v1,v2;
    cin >> v1 >> v2;
    if(hasPath(edges,n,0,visited,v1,v2)){
        cout << "true";
    }else{
        cout << "false";
    }
}