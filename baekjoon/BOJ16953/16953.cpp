/*BOJ 16953 A->B*/
#include <iostream>
#include <queue>
#include <map>
#define MAX 1000000001
typedef long long ll;
using namespace std;

map<ll, ll> dp;
queue<pair<ll, ll> > q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;
    
    dp.insert(make_pair(A, 1));
    q.push(make_pair(A, 1));

    while(!q.empty()){
        ll cur_location = q.front().first;
        ll cur_dist = q.front().second;
        q.pop();
        if(cur_location == B){
            cout << dp[B] << endl;
            return 0;
        }

        ll case1 = cur_location*2;
        ll case2 = cur_location*10 + 1;

        if(case1 < MAX && dp.find(case1)==dp.end()){
            q.push(make_pair(case1, cur_dist+1));
            dp[case1] = cur_dist+1;
        }

        if(case2 < MAX && dp.find(case2)==dp.end()){
            q.push(make_pair(case2, cur_dist+1));
            dp[case2] = cur_dist+1;
        }
    }
    cout << -1 << endl;
    return 0;
}