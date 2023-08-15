#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001
using namespace std;

int N, E;
int parent[MAX];
vector<pair<int, pair<int, int>>> network; // ê°?ì¤‘ì¹˜ ?…¸?“œ1, ?…¸?“œ2

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

int main(){
    cin >> N >> E;
    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        network.push_back({w, {n1,n2}});
    }
    sort(network.begin(), network.end());

    int answer = 0;

    for(int i=1; i<=N; ++i){
        parent[i] = i;
    }

    for(int i=0;i<E; ++i){
        if(sameParent(network[i].second.first, network[i].second.second) == false){
            Union(network[i].second.first, network[i].second.second);
            answer += network[i].first; // ê°?ì¤‘ì¹˜
        }
    }

    cout << answer << endl;

    return 0;
}