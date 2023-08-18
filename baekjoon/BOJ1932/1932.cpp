/*DP BOJ 1932 정수 삼각형*/
#include<iostream>
using namespace std;

int dp[501];
int triangle[501];

int main(){
    int n;
    int predp = 0;
    int maxValue = 0;
    cin >> n;

    cin >> dp[1];
    for(int i=2; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            cin >> triangle[j];
        }

        for(int j=1; j<=i; ++j){
            int tmp = dp[j];
            if(j==1){
                dp[j] += triangle[j];
            }else if(j==i){
                dp[j] = triangle[j] + predp;
            }else{
                dp[j] = max(triangle[j]+predp, triangle[j] + dp[j]);
            }
            predp = tmp;
        }
    }

    for(int i=1; i<=n; ++i){
        if(dp[i] > maxValue) maxValue = dp[i];
    }

    cout << maxValue << endl;
    return 0;
}