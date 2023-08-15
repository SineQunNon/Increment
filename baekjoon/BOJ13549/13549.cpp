#include<iostream>
#include<queue>
#include<list>
using namespace std;
#define MAX 100001

queue<pair<int, int>> q;
queue<int> q_dist;

int main(){
    int subin, K;
    cin >> subin >> K;
    int dist;
    q.push(make_pair(subin, 0));

    while(!q.empty()){
        int cur_location = q.front().first;
        int cur_distance = q.front().second;
        q.pop();

        if(cur_location == K){
            q_dist.push(cur_distance);           
        }
        
        int case1 = cur_location - 1;
        int case2 = cur_location + 1;
        int case3 = cur_location*2;

        if(case1>=0){
            q.push(make_pair(case1, cur_distance+1));
        }
        if(case2<=K){
            q.push(make_pair(case2, cur_distance+1));
        }

        if(case3<=K+1){
            q.push(make_pair(case3, cur_distance));
        }

    }
    
    dist = q_dist.front();
    q_dist.pop();
    cout << dist << " ";
    while(!q_dist.empty()){
        int next = q_dist.front();

        cout << next << " ";

        q_dist.pop();

        if(dist > next){
            dist = next;
        }
    }


    // cout << dist << endl;

    return 0;
}