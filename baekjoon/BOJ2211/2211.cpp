#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, E;
int dist[MAX];
int parent[MAX];
vector<pair<int, int>> computer[MAX];


void djikstra(){
    priority_queue<pair<int,int>> pq;
    fill_n(dist, N+1, INF);
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second;
        pq.pop();

        if(curDist > dist[curNum]) continue;

        for(auto edge : computer[curNum]){
            int adjNum = edge.first;
            int cost = edge.second;
            int newCost = curDist + cost;

            if(dist[adjNum] > newCost){
                dist[adjNum] = newCost;
                parent[adjNum] = curNum;
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

        computer[n1].push_back({n2, w});
        computer[n2].push_back({n1, w});
    }


    djikstra();
    cout << N-1 << "\n";
    for(int i=2;i<=N;++i){
        cout << parent[i] << " " << i << "\n";
    }

    return 0;
}