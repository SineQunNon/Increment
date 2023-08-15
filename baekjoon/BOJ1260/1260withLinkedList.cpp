#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

class Graph{

public:
    map<int, list<int>> adj;
    map<int, bool> visited;

    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(w);
        visited[v] = false;
        visited[w] = false;
    }

    void BFS(int s){
        queue<int> q;
        q.push(s);
        visited[s]=true;

        while(!q.empty()){
            int next = q.front();
            cout << next << " ";
            q.pop();

            for(auto iter : adj[next]){
                if(visited[iter] == false){
                    q.push(iter);
                    visited[iter] =true;
                }
            }
        }
    }

    

};

int main(){
    Graph g;
    
    g.addEdge(1,3);
    g.addEdge(3,5);
    g.addEdge(5,2);
    g.addEdge(2,4);

    g.BFS(1);

    return 0;
}