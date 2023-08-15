#include<iostream>
#include<queue>
#include<vector>
#define MAX 101
#define INF 1e9
using namespace std;


int main(){
    int testcase;
    cin >> testcase;

    for(int t=0;t<testcase;++t){
        int min_dist = INF;
        vector<pair<int, int>> room[MAX]; //그래프 정보
        queue<int> st; //학생 위치 정보 저장큐
        int dist[MAX]; //방 사이의 거리
        int dist_sum[MAX];
        int node, edge;

        cin >> node >> edge; //각 방의 개수와 비밀 연결 통로 입력 받기
        fill_n(dist_sum, node+1, 0);
        
        /*방의 정보 저장*/
        for(int i=0; i<edge; ++i){
            int n1, n2, w;
            cin >> n1 >> n2 >> w;

            room[n1].push_back({n2, w});
            room[n2].push_back({n1, w});
        }

        int stu_num;
        cin >> stu_num;
        /*학생 위치 정보 저장*/
        for(int i=0; i<stu_num; ++i){
            int student;
            cin >> student;
            st.push(student);
        }

        while(!st.empty()){
            fill_n(dist, node+1, INF);
            
            int start = st.front();
            st.pop();

            priority_queue<pair<int,int>> pq;
            pq.push({0,start});
            dist[start] = 0;

            while(!pq.empty()){
                int curDist = -pq.top().first;
                int curNum = pq.top().second;
                pq.pop();

                if(curDist > dist[curNum]) continue;

                for(auto next : room[curNum]){
                    int adjNum = next.first;
                    int cost = next.second;
                    int newCost = curDist + cost;

                    if(dist[adjNum] > newCost){
                        dist[adjNum] = newCost;
                        pq.push({-newCost, adjNum});
                    }
                }
            }

            for(int i=1;i<=node; ++i){
                dist_sum[i] += dist[i];
            }
        }
        int min_node;


        for(int i=1;i<=node; ++i){
            if(min_dist > dist_sum[i]){
                min_dist = dist_sum[i];
                min_node = i;
            }
        }
        cout << min_node << "\n";
    }

    return 0;
}