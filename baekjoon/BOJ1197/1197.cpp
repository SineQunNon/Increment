#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10001
using namespace std;

int N, E;
int parent[MAX];
vector<pair<int ,pair<int, int>>> tree;

void input(){
    cin >> N >> E;
    for(int i=0; i<E; ++i){
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        tree.push_back({w, {n1, n2}});
    }
    sort(tree.begin(), tree.end());
}

int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x != y) parent[y] = x;
}

bool sameParent(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x==y) return true;
    else return false;
}

int Solution(){
    int answer = 0;
    for(int i=1; i<=N; ++i){
        parent[i] = i;
    }

    for(int i=0; i<E; ++i){
        if(sameParent(tree[i].second.first, tree[i].second.second) == false){
            Union(tree[i].second.first, tree[i].second.second);
            answer += tree[i].first;
        }
    }
    return answer;
}

int main(){
    input();

    cout << Solution() << endl;

    return 0;
}