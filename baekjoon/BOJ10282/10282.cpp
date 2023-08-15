#include<iostream>
#include<queue>
#include<vector>

#define MAX 10001
#define INF 1e9
using namespace std;

int dist[MAX];

int main(){
    int test;
    cin >> test;
    
    for(int i=0; i<test; ++i){
        int N, E, START;
        int cnt = 0;
        int max = 0;
        vector<pair<int,int>> computer[MAX];
        cin >> N >> E >> START;
        fill_n(dist, N+1, INF);

        for(int j=0;j<E;++j){
            int n1, n2, w;
            cin >> n1 >> n2 >> w;
            computer[n2].push_back({n1, w});
        }

        priority_queue<pair<int,int>> pq;

        pq.push({0,START});
        dist[START]=0;

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
                    pq.push({-newCost, adjNum});
                }
            }
        }

        for(int j=1;j<=N; ++j){
            if(dist[j]==INF) continue;
            cnt++;
            if(dist[j] > max) max = dist[j];
        }

        cout << cnt << " " << max << "\n";
    }
    
    return 0;
}