#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 100001

int N;
bool visited[MAX];
int parent[MAX];
vector<int> adj[MAX];

void BFS(){
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int next = q.front();
        q.pop();

        for(auto value : adj[next]){
            if(!visited[value]){
                visited[value] = true;
                parent[value] = next;
                q.push(value);
            }
        }
    }
}

int main(){
    cin >> N;
    
    for(int i=1;i<N;++i){
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    
    BFS();

    for(int i=2;i<=N;++i){
        cout << parent[i] << "\n";

    }

    return 0;
}