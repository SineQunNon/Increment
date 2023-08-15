#include<iostream>
#include<vector>
#include<queue>
#include<limits>
#define INF 1e9
#define MAX 101
using namespace std;

int N, E;
int dist[MAX];
vector<pair<int ,int>> graph[MAX];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    fill_n(dist, N+1, INF);
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second;
        pq.pop();

        if(curDist > dist[curNum]) continue;

        for(auto edge : graph[curNum]){
            int adjNum = edge.first;
            int cost = edge.second;
            int newCost = curDist + cost;

            if(dist[adjNum] > newCost){
                dist[adjNum] = newCost;
                pq.push({-newCost, adjNum});
            }
        }
    }
}

int main(){
    cin >> N >> E;

    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        graph[n1].push_back({n2, w});
    }

    
    for(int j=1;j<=N; ++j){
        dijkstra(j);
        for(int i=1; i<=N; ++i){
            if(dist[i] == INF){
                cout << "0" << " ";
            }else{
                cout << dist[i] << " ";      
            }
        }cout << "\n";
    }

    return 0;
}