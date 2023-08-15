#include<iostream>
#include<queue>
#include<vector>

#define MAX 100001
using namespace std;

int subin, sister;
bool visited[MAX];
int parent[MAX];
queue<pair<int,int>> q;
vector<int> path;

void bfs(){
    while(!q.empty()){
        int cur_location = q.front().first;
        int cur_dist = q.front().second;
        q.pop();

        if(cur_location == sister){
            int idx = cur_location;
            while(idx != subin){
                path.push_back(idx);
                idx = parent[idx];
            }
            cout << cur_dist << "\n";
            break;
        }

        int case1 = cur_location - 1;
        int case2 = cur_location + 1;
        int case3 = cur_location * 2;

        if(case1>=0&&visited[case1]==false){
            q.push({case1, cur_dist+1});
            visited[case1] = true;
            parent[case1] =cur_location;
        }

        if(case2 <= sister && visited[case2]==false){
            q.push({case2, cur_dist+1});
            visited[case2] = true;
            parent[case2] =cur_location;
        }

        if(case3<=sister+1 && visited[case3]==false){
            q.push({case3, cur_dist+1});
            visited[case3] = true;
            parent[case3] =cur_location;
        }
    }
}

int main(){
    cin >> subin >> sister;

    q.push({subin, 0});
    visited[subin] = subin;
    bfs();
    
    cout << subin << " ";
    for (int i = path.size()-1; i >= 0; --i){
        cout << path[i] << ' ';
    }
        
    
    return 0;
}