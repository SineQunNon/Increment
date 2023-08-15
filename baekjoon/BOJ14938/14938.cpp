#include<iostream>
#include<queue>
#include<vector>
#define MAX 101
#define INF 1e9
using namespace std;

int N, M, E;
int item[MAX];
int dist[MAX];

vector<pair<int, int>> ground[MAX];

void input(){
    cin >> N >> M >> E;

    for(int i=1;i<=N;++i){
        cin >> item[i];
    }
    for(int i=0;i<E;++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        ground[n1].push_back({n2, w});
        ground[n2].push_back({n1, w});
    }
}

void djikstra(int start){
    fill_n(dist, N+1, INF);
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second;
        pq.pop();

        if(curDist > dist[curNum]) continue;

        for(auto edge : ground[curNum]){
            int adjNum = edge.first;
            int cost = edge.second;
            int newCost = curDist + cost;

            if(dist[adjNum] > newCost && newCost <=M){
                dist[adjNum] = newCost;
                pq.push({-newCost, adjNum});
            }
        }
    }
}

int main(){
    int max = 0;
    input();

    

    for(int i=1; i<=N; ++i){
        int value = 0;
        djikstra(i);
        for(int j=1;j<=N; ++j){
            if(dist[j]==INF) continue;
            value += item[j];
        }
        if(value > max) max = value;
    }

    cout << max << endl;

    return 0;
}