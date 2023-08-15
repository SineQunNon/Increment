#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define INF 1e9
#define MAX 1001

int N, M, X;
int dist[MAX];
int X_dist[MAX];
vector<pair<int, int>> graph[MAX];

void input(){
    cin >> N >> M >> X;
    fill_n(X_dist, N+1, INF);
    for(int i = 0; i<M; ++i){
        int student, path, weight;
        cin >> student >> path >> weight;

        graph[student].push_back({path, weight});
    }
}

void dijkstra(int start){
    fill_n(dist, N+1, INF);

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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0;

    input();

    dijkstra(X);
    for(int i = 1; i<=N; ++i){
        X_dist[i] = dist[i];
    }

    for(int i=1;i<=N; ++i){
        if(i==X) continue;
        dijkstra(i);

        int value = dist[X] + X_dist[i];
        if( value > max ) max = value;
    }

    cout << max << endl;

    return 0;
}