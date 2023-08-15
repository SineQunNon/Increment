/*BOJ 1504 특정한 최단경로(그래프)*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define INF 98765432
#define MAX 801
using namespace std;

int N, E, path1, path2;

vector<pair<int, int>> graph[MAX];
int dist[MAX];

void input(){
    cin >> N >> E;
    for(int i= 0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        graph[n1].push_back({n2, w});
        graph[n2].push_back({n1, w});
    }
    cin >> path1 >> path2;
}

void dijkstra(int start){
    fill_n(dist, N+1, INF);
   priority_queue<pair<int, int>> pq;

   //출발 노드에 대한 초기화
   pq.push({0, start});
   dist[start] = 0;

   while(!pq.empty()){
        int curDist = -pq.top().first; //출발 노드에서 현재 노드까지의 거리
        int curNum = pq.top().second; //현재 노드 번호
        pq.pop();

        //현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if(curDist > dist[curNum]) continue;

        //현재 노드와 연결된 다른 인접 노드들을 확인
        for(auto edge : graph[curNum]){
            int adjNum = edge.first;
            int cost = edge.second;
            int newCost = curDist + cost;

            //현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if(dist[adjNum] > newCost){
                dist[adjNum] = newCost; //최단거리 테이블 갱신
                pq.push({-newCost, adjNum}); //우선순위 큐 삽입
            }
        }
   }
}

int main(){
    ios::sync_with_stdio(0);  //C 표준 stream과 C++표준 stream의 동기화를 끊는다.
    cin.tie(0);               //cin을 cout으로부터 untie한다. stream을 tie하면 다른 stream에서 입출력요청이 오기 전에 stream을 flush시킨다.
    int res;
    int S_to_N1, S_to_N2;
    int N1_to_N2;
    int N1_to_NN, N2_to_NN;

    input();

    dijkstra(1);
    S_to_N1 = dist[path1];
    S_to_N2 = dist[path2];

    dijkstra(path1);
    N1_to_N2 = dist[path2];
    N1_to_NN = dist[N];

    dijkstra(path2);
    N2_to_NN = dist[N];

    res = min(INF, S_to_N1 + N1_to_N2 + N2_to_NN);
    res = min(res, S_to_N2 + N1_to_N2 + N1_to_NN);

    if(res >= INF)
        cout << -1;
    else
        cout << res;

    return 0;
}