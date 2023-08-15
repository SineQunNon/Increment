#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int RGB[MAX][3];
int dp[MAX][3]; // dp[i][j]: i번째 집까지 칠할 때, 마지막 집의 색이 j일 때의 최소 비용

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> RGB[i][j];
        }
    }

    // 첫 번째 집까지 칠하는데 드는 비용은 그대로 초기화
    dp[1][0] = RGB[1][0];
    dp[1][1] = RGB[1][1];
    dp[1][2] = RGB[1][2];

    for (int i = 2; i <= n; ++i) {
        // i번째 집을 빨간색으로 칠할 때, 이전 집은 파란색 또는 초록색일 때의 최소 비용 중 작은 값과 현재 집의 비용을 더함
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][0];
        // i번째 집을 초록색으로 칠할 때, 이전 집은 빨간색 또는 파란색일 때의 최소 비용 중 작은 값과 현재 집의 비용을 더함
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + RGB[i][1];
        // i번째 집을 파란색으로 칠할 때, 이전 집은 빨간색 또는 초록색일 때의 최소 비용 중 작은 값과 현재 집의 비용을 더함
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][2];
    }

    // 마지막 집까지 칠한 후, 각 색상별 최소 비용 중 가장 작은 값을 출력
    int answer = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << answer << endl;

    return 0;
}







