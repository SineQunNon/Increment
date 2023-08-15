#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 1e9
#define MAX 1001
using namespace std;

int N, E, START, END;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
int route[MAX];

void input(){
    cin >> N >> E;

    fill_n(dist, N+1, INF);
    for(int i = 0; i<E; ++i){
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;

        graph[n1].push_back({n2, weight});
    }
    cin >> START >> END;
}

void dijkstra(){
    priority_queue<pair<int, int>> pq;

    pq.push({0, START});
    dist[START] = 0;
    route[START] = 0;

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curNum = pq.top().second;
        pq.pop();

        //현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if(curDist > dist[curNum]) continue;

        for(auto edge : graph[curNum]){
            int adjNum = edge.first;    //인접한 노드
            int cost = edge.second;     //가중치
            int newCost = curDist + cost;   //시작 노드부터 인접한 노드까지 가는 비용

            if(dist[adjNum] > newCost){
                dist[adjNum] = newCost;
                route[adjNum] = curNum;
                pq.push({-newCost, adjNum});
            }
        }
    }
}

int main(){
    input();

    dijkstra();

    cout << dist[END] << "\n";
    
    int path = END;
    int cnt = 1;
    vector<int> min_route;
    while(path != START){
        min_route.push_back(route[path]);
        path = route[path];
    }
    cout << min_route.size() + 1 << "\n";
    while(min_route.size()!=0){
        cout << min_route.back() << " ";
        min_route.pop_back();
    }
    cout << END << endl;
    return 0;
}