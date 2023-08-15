#include<iostream>
#include<queue>
#include<vector>
#define MAX 5001
#define INF 1e9
using namespace std;

int N, E, start, e;
int dist[MAX];
int parent[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int s){
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
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
                parent[adjNum] = curNum;
            }
        }
    }
}

int main(){
    cin >> N >> E;
    fill_n(dist, N+1, INF);
    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        graph[n1].push_back({n2,w});
        graph[n2].push_back({n1,w});
    }
    cin >> start >> e;

    dijkstra(start);

    cout << dist[e] << endl;



    return 0;
}

