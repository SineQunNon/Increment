#include<iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, E; //노드의 수 및 엣지의 수
int adj[MAX][MAX];
int visited[MAX];
queue<int> q;

void BFS(int s){
    int cnt = 0;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        s = q.front();
        cnt++;
        q.pop();

        for(int i = 1; i<=N; ++i){
            if(adj[s][i]==1 && visited[i]==0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << cnt-1 << endl;
}

int main(){
    cin >> N;
    cin >> E;

    for(int i = 0; i< E; ++i){
        int v, w;
        cin >> v >> w;
        adj[v][w] = 1;
        adj[w][v] = 1;
    }

    BFS(1);

    return 0;
}