/*BOJ 15654*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dp[8];
bool check[8];
vector<int> numbers;

void DFS(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << dp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!check[i]) {
            check[i] = true;
            dp[cnt] = numbers[i];
            DFS(cnt + 1);
            check[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    DFS(0);

    return 0;
}
