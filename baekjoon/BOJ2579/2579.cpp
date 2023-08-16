/* DP 2579번 계단 오르기 */

#include<iostream>
#define MAX 301
using namespace std;

int stairs[MAX];
int dp[MAX];

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> stairs[i];
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1]+stairs[2];
    dp[3] = max(stairs[3]+stairs[1], stairs[3]+stairs[2]);

    for(int i=4;i<=n;i++){
        dp[i] = max(stairs[i] + dp[i-2], stairs[i] + stairs[i-1] + dp[i-3]);
    }
    
    cout << dp[n] << endl;

    return 0;
}