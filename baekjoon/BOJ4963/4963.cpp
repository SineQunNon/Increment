#include<iostream>
#include<queue>
#define MAX 50
using namespace std;

int N, E;
int island[MAX][MAX];
int visited[MAX][MAX];

int x_dist[8] = {-1,1,0,0,-1,1,-1,1}; 
int y_dist[8] = {0,0,1,-1,-1,1,1,-1};
queue<pair<int,int>> q;
queue<pair<int,int>> start_q;

void BFS(int x_start, int y_start){
    q.push({x_start,y_start});
    visited[x_start][y_start] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        for(int i=0;i<8;++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<E)&&island[x_new][y_new]==1&&visited[x_new][y_new]==0){
                q.push({x_new,y_new});
                visited[x_new][y_new] = 1;
            }
        }
    }
}

int main(){
    
    while(true){
        int cnt=0;
        cin >> E >> N;
        if(E==0&&N==0) break;

        for(int i = 0; i<N; ++i){
            for(int j = 0; j<E; ++j){
                int status;
                cin >> status;
                island[i][j] = status;
                if(status == 1){
                    start_q.push({i,j});
                }
            }
        }

        for(int i=0; i<N; ++i){
            for(int j = 0; j<E; ++j){
                visited[i][j] = 0;
            }
        }

        while(!start_q.empty()){
            int x = start_q.front().first;
            int y = start_q.front().second;
            start_q.pop();
            if(visited[x][y]==0){
                BFS(x,y);
                cnt++;
            }
        }
        cout << cnt << endl;
        
    }

    return 0;
}