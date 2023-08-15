#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int adj[MAX][MAX];
bool visited[MAX];
int N, E, S;

void BFS(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int next_idx = q.front();
        cout << next_idx << " ";
        q.pop();

        for(int i = 1; i<=N; ++i){
            if(adj[next_idx][i] == 1 && visited[i]==false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int s){
    visited[s] = true;
    cout << s << " ";

    for(int i = 1; i<=N; ++i){
        if(adj[s][i] == 1 && visited[i]==false){
            DFS(i);
        }
    }
}

int main(){
    cin >> N >> E >> S; 

    for(int i = 0; i<E; ++i){
        int v,  w;
        cin >> v >> w;

        adj[v][w] = 1;
        adj[w][v] = 1;
    }
    DFS(S);
    cout << endl;
    for(int i =0; i<=MAX;++i){
        visited[i] = false;
    }

    BFS(S);
    return 0;
}