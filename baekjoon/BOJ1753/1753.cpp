#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
#define MAX 20001
using namespace std;

//노드, 간선, 출발 노드
int N, E, start;

vector<pair<int, int>> graph[MAX];

//최단 거리 테이블
int dist[MAX];

void input(){
    cin >> N >> E >> start;

    // 최단 거리 테이블 초기화
    fill_n(dist, N+1, INF);

    for(int i =0; i<E; ++i){
        int a,b,c;
        cin >> a >> b >> c;

        //a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].push_back({b,c});
    }
}

void dijkstra(){
    /*
    기본적으로 최대 힙으로 선언되기 때문에
    거리가 가장 짧은 노드부터 먼저 꺼내는 '최소 힙'으로 구현하려면
    원소를 삽입, 삭제할 때 마이너스 부호를 붙여주어야 한다.
    */
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

void printResult(){
    for(int i = 1; i<=N; ++i){
        if(dist[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }

    }
}

int main(){
    ios::sync_with_stdio(0);  //C 표준 stream과 C++표준 stream의 동기화를 끊는다.
    cin.tie(0);               //cin을 cout으로부터 untie한다. stream을 tie하면 다른 stream에서 입출력요청이 오기 전에 stream을 flush시킨다.


    //사용 이유 속도를 보다 가속시키기 위해 사용한다.

    input();

    dijkstra();

    printResult();

    return 0;
}