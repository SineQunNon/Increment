/*1697 숨바꼭질*/
#include<iostream>
#include<queue>
using namespace std;
#define MAX 100001

bool visited[MAX];
queue<pair<int, int>> q;

int main(){
    int subin, K;
    cin >> subin >> K;

    q.push(make_pair(subin, 0));
    visited[subin] = true;

    while(!q.empty()){
        int cur_location = q.front().first;
        int cur_distance = q.front().second;
        q.pop();
        if(cur_location == K){
            cout << cur_distance << endl;
            break;
        }
        
        int case1 = cur_location - 1;
        int case2 = cur_location + 1;
        int case3 = cur_location*2;

        if(case1>=0&&visited[case1]==false){
            q.push(make_pair(case1, cur_distance+1));
            visited[case1] = true;
        }
        if(case2<=K && visited[case2]==false){
            q.push(make_pair(case2, cur_distance+1));
            visited[case2] = true;
        }

        if(case3<=K+1 && visited[case3] == false){
            q.push(make_pair(case3, cur_distance+1));
            visited[case3] = true;
        }

    }

    return 0;
}