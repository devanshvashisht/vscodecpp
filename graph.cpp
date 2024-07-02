#include<iostream>
#include<queue>
using namespace std;
void print(int ** edges, int n, int sv, bool * visited){
    cout << sv << endl;
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            print(edges,n,i,visited); 
        }
    }

}
void printBFS(int ** edges, int n, int sv){
    queue<int> pending;
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    pending.push(sv);
    visited[sv] = true;
    while(!pending.empty()){
        int current = pending.front();
        pending.pop();
        cout << current<<endl;
        for(int i=0;i<n;i++){
            if(i==current){
                continue;
            }
            if(edges[current][i]==1 && !visited[i]){
                pending.push(i);
                visited[i]=true;
            }
        }

    }
}

int main(){
    int n;
    int e;
    cin >> n >> e;
    int ** edges = new int* [n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }

    }

    for(int i=0;i<e;i++){
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    cout << "DFS" << endl;
    print(edges,n,0,visited);

    cout << "BFS" << endl;
    printBFS(edges,n,0);
}