#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, E, K;
vector<int> all_dist[MAX];
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void djikstra(){
    priority_queue<pair<int, int>> pq;

    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second; //현재 노드 번호
        pq.pop();


        if(curDist > dist[curNum]) continue;

        for(auto edge : graph[curNum]){
            int adjNum = edge.first;
            int cost = edge.second;
            int newCost = curDist + cost;

            all_dist[adjNum].push_back(newCost);
            if(dist[adjNum] > newCost){
                dist[adjNum] = newCost;
                pq.push({-newCost, adjNum});
            }
        }
    }
}

int main(){
    fill_n(dist, N+1, INF);
    cin >> N >> E >> K;
    
    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        graph[n1].push_back({n2, w});
    }

    djikstra();
    // for(int i=1;i<=N;++i){
    //     cout << dist[i] << " ";
    // }cout << "\n";

    for(int i=1;i<=E;++i){
        sort(all_dist[i].begin(), all_dist[i].end());
    }

    // for(int i=1;i<=N;++i){
    //     for(int value : all_dist[i]){
    //         cout << value << " ";
    //     }cout << "\n";
    // }
    
    for(int i=2;i<=N; ++i){
        all_dist[i].push_back(INF);
    }

    if(K==1) cout << "0" << "\n";
    else cout << "-1" << "\n";

    
    for(int i=2;i<=N;++i){
        for(int j=0;j<K;++j){
            if(all_dist[i][j] == INF){
                cout << "-1\n";
                break;
            }
            if(j==K-1){
                cout << all_dist[i][j] << "\n";
            }
        }
    }

    return 0;
}