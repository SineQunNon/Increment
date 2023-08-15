/*BOJ 1647번 도시 분할 계획(최소 스패닝 트리)*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAX 100001
using namespace std;

int N, E;
int parent[MAX];
int visit[MAX];
vector<pair<long, pair<int, int>>> city;
vector<int> graph[MAX];


int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x!=y) parent[y] = x;
}

bool sameParent(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x==y) return true;
    else return false;
}

void bfs(){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int next = q.front();
        visit[next] = 1;
        q.pop();

        for(auto edge : graph[next]){
            if(visit[edge] == false){
                q.push(edge);
                visit[edge] = 1;
            }
        }
    }
}

int main(){
    cin >> N >> E;
    bool status = true;
    for(int i=0;i<E;++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        city.push_back({w, {n1, n2}});
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    bfs();

    for(int i=1;i<=N; ++i){
        if(visit[i] == 0){
            status = false;
        }
    }

    if(!status){
        cout << "-1" << endl;
    }else{
        sort(city.begin(), city.end());

        long answer = 0;
        long cost = 0;

        for(int i=1; i<=N; ++i){
            parent[i] = i;
        }

        for(int i=0;i<E;++i){
            cost += city[i].first;
            if(sameParent(city[i].second.first, city[i].second.second)==false){
                Union(city[i].second.first, city[i].second.second);
                answer += city[i].first;
            }
        }
        cout <<  cost - answer << endl;
    }

    
    

    return 0;
}