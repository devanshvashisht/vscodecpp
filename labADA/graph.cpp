#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void add(int graph[][4],int u,int v, int x){
    graph[u][v] = x;

}

void print(int graph[][4],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (graph[i][j] == INT_MAX) {
                cout << "inf ";
            } else {
                cout << graph[i][j] << " ";
            }
            //cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}
void floyd(int graph[][4],int n){
    int dis[4][4];
    for(int m=0;m<n;m++){
        for(int a = 0;a<n;a++){
            dis[m][a] = graph[m][a];
        }
    }

    print(dis,4);
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    
                }
            }
        }
    

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (dis[i][j] == INT_MAX) {
                cout << "inf ";
            } else {
                cout << dis[i][j] << " ";
            }
        }
        cout << endl; 
    }
    cout<<endl;
    }
}

int main(){
    int n=4;
    int graph[4][4];
    add(graph,0,0,0);
    add(graph,0,1,3);
    add(graph,0,2,INT_MAX);
    add(graph,0,3,5);
    add(graph,1,0,2);
    add(graph,1,1,0);
    add(graph,1,2,INT_MAX);
    add(graph,1,3,4);
    add(graph,2,0,INT_MAX);
    add(graph,2,1,1);
    add(graph,2,2,0);
    add(graph,2,3,INT_MAX);
    add(graph,3,0,INT_MAX);
    add(graph,3,1,INT_MAX);
    add(graph,3,2,2);
    add(graph,3,3,0);
    print(graph,4);
    floyd(graph,4);

}

