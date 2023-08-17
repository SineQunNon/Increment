/*DP BOJ 2156 포도주 마시기*/

#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int grape[MAX];
int dp[MAX];

int main(){
    int n;
    cin >> n;
    int maxValue = 0;
    //
    for(int i=1; i<=n; ++i){
        cin >> grape[i];
    }
    

    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];
    dp[3] = max({dp[2], grape[1]+grape[3], grape[2]+grape[3]});

    for(int i=4; i<=n; ++i){
        dp[i] = max({dp[i-1], dp[i-2]+grape[i], dp[i-3]+grape[i]+grape[i-1]});
    }
    cout << dp[n] << endl;
    return 0;
}