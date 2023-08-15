#include<iostream>
#include<vector>
#include<queue>
#define MAX 201
#define INF 1e9
using namespace std;

int N, E;
vector<pair<int, int>> deliver[MAX];
int dist[MAX];
int path[MAX][MAX];
int parent[MAX];

void dijkstra(int start){
    fill_n(dist, N+1, INF);
    fill_n(parent, N+1, 0);
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    dist[start] = 0;



    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second;
        pq.pop();

        if(curDist > dist[curNum]) continue;

        for(auto edge : deliver[curNum]){
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
    
    for(int i=0;i<E;++i){
        int n1, n2 ,w;
        cin >> n1 >> n2 >> w;
        
        deliver[n1].push_back({n2, w});
        deliver[n2].push_back({n1, w});
    }

    for(int i=1;i<=N; ++i){
        dijkstra(i);

        for(int j=1;j<=N; ++j){
            if(parent[j] == 0) continue;
            int idx = j;
            
            while(true){
                if(parent[idx]== i){
                    path[i][j] = idx;
                    break;
                }
                idx = parent[idx];
            }
        }
    }
    // for(int i=1;i<=N;++i){
    //     dijkstra(i);

    //     for(int j=1;j<=N;++j){
    //         cout << parent[j] << " ";
    //     }cout << "\n";
    // }
    
    
    for(int i=1;i<=N;++i){
        for(int j=1; j<=N; ++j){
            if(path[i][j]==0) cout << "- ";
            else{
                cout << path[i][j] << " ";
            }
        }cout << "\n";
    }

    return 0;
}