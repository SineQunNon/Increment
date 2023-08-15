#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
#define MAX 5001

using namespace std;

int V, E, P;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int start){
    fill_n(dist, V+1, INF);

    priority_queue<pair<int, int>> pq;
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
    int toP = INF;
    int toV = INF;
    int PtoV = INF;
    cin >> V >> E >> P;

    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        graph[n1].push_back({n2, w});
        graph[n2].push_back({n1, w});
    }

    dijkstra(1);
    toP = dist[P];
    toV = dist[V];

    dijkstra(P);
    PtoV = dist[V];

    if(toP + PtoV > toV){
        cout << "GOOD BYE" << endl;
    }else{
        cout << "SAVE HIM" << endl;
    }

    return 0;
}