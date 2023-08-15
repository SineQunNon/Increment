#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, E, K;

vector<pair<int, int>> graph[MAX];
priority_queue <int> dist[MAX];

void djikstra(){
    priority_queue <pair<int, int>> pq;

    pq.push({0, 1});
    dist[1].push(0);

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second; //현재 노드 번호
        pq.pop();

        for(int i=0;i<graph[curNum].size(); ++i){
            int adjNum =graph[curNum][i].first;
            int cost = graph[curNum][i].second + curDist;

            if(dist[adjNum].size() < K){
                dist[adjNum].push(cost);
                pq.push({-cost, adjNum});
            }else if(dist[adjNum].top() > cost){
                dist[adjNum].pop();
                dist[adjNum].push(cost);
                pq.push({-cost, adjNum});
            }
        }
    }
}

int main(){
    cin >> N >> E >> K;

    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        graph[n1].push_back({n2, w});
    }
    
    djikstra();

    for(int i=1;i<=N; ++i){
        if(dist[i].size() < K) cout << "-1\n";
        else cout << dist[i].top() << "\n";
    }

    return 0;
}