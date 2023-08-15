#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
#define MAX 50001
using namespace std;

int N, E;
int dist[MAX];
vector<pair<int, int>> cow[MAX];

void dijkstra(){
    priority_queue<pair<int, int>> pq;
    fill_n(dist, N+1, INF);
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second;
        pq.pop();

        if(curDist > dist[curNum]) continue;

        for(auto edge : cow[curNum]){
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
    for(int i=0;i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        cow[n1].push_back({n2, w});
        cow[n2].push_back({n1, w});
    }
    dijkstra();

    cout << dist[N] << endl;

    return 0;
}