/*BOJ 15650*/
#include<iostream>
using namespace std;

int dp[8];
bool check[8];
int N, M;

void DFS(int cnt, int idx){
    if(idx > N) return;
    if(cnt == M){
        for(int i=0; i<N; ++i){
            if(check[i]) cout << dp[i] << " ";
        }cout << "\n";
        return;
    }

    check[idx] = true;
    DFS(cnt+1, idx+1);

    check[idx] = false;
    DFS(cnt, idx+1);
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        dp[i] = i+1;
    }

    DFS(0, 0);

    return 0;
}