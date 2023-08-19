/*BOJ 15652*/
#include<iostream>
using namespace std;

int dp[64];
bool check[64];
int N, M;

void DFS(int cnt, int idx){
    if(idx > N*M) return;
    if(cnt == M){
        for(int i=0; i<N*M; ++i){
            if(check[i]) cout << dp[i] << " ";
        }cout << "\n";
        return;
    }

    check[idx] = true;
    DFS(cnt+1, idx+1);

    check[idx] = false;
    DFS(cnt, idx+M);
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            dp[i*M+j] = i+1; 
        }
    }
    

    DFS(0, 0);

    return 0;
}