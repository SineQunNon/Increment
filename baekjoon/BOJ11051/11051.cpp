#include<iostream>
#define MAX 1001
using namespace std;

int K, N;
int dp[MAX][MAX];

//점화식 dp[N][K] = dp[N-1][K-1] + dp[N-1][K] 
int main(){
    cin >> N >> K;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=N; ++i){
        for(int j=0; j<=i; ++j){
            if( j == 0 ) dp[i][0] = 1;
            else if( j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K];
    
    return 0;
}