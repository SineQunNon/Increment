#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

int N, E;
int adj[MAX][MAX];
bool visited[MAX];
queue<int> q;
queue<int> node;

void BFS(int s){
    q.push(s);

    while(!q.empty()){
        int next = q.front();
        q.pop();
        visited[s] =true;
        
        for(int i = 1; i<=N; ++i){
            if(adj[next][i]==1&& visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

int main(){
    int factor=0;
    cin >> N >> E;

    for(int i =1; i<=N; ++i){
        
        node.push(i);
    }//1~N까지의 노드 정보를 만든다.

    for(int i =0; i<E; ++i){
        int v, w;
        cin >> v >> w;
        adj[v][w] = 1;
        adj[w][v] = 1;
    }

    while(!node.empty()){
        int start = node.front();
        node.pop();
        if(visited[start] == false){
            BFS(start);
            factor++;
        }
    }
    cout << factor << endl;

    return 0;
}