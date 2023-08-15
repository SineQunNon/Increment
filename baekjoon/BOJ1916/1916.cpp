#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
#define MAX 1001
using namespace std;

int N, E, START, END;
vector<pair<int,int>> bus[MAX];

//최단 거리 테이블
int dist[MAX];

void input(){
    cin >> N >> E;

    fill_n(dist, N+1, INF);

    for(int i = 0; i<E;++i){
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        //node1에서 node2로 가는 비용이 weight라는 의미
        bus[node1].push_back({node2, weight});
    }

    cin >> START >> END;
}

void dijkstra(){
    priority_queue<pair<int, int>> pq;

    //출발 노드에 대한 초기화
    pq.push({0, START});
    dist[START] = 0;

    while(!pq.empty()){
        int curDist = -pq.top().first; //출발 노드에서 현재 노드까지의 거리
        int curNum = pq.top().second;   //현재 노드 번호
        pq.pop();

        //현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if(curDist > dist[curNum]) continue;

        //현재 노드와 연결된 다른 인접 노드들을 확인
        for(auto edge : bus[curNum]){
            int adjNum = edge.first;
            int cost = edge.second;
            int newCost = curDist + cost;

            //현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if(dist[adjNum] > newCost){
                dist[adjNum] = newCost; //최단거리 테이블 갱신
                pq.push({-newCost, adjNum});
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    dijkstra();
    
    cout << dist[END] << endl;

    return 0;
}