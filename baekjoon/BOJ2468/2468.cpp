#include<iostream>
#include<queue>
#define MAX 100
using namespace std;

int N;
int safty[MAX][MAX];
int visited[MAX][MAX];

int x_dist[4] = {-1,1,0,0};
int y_dist[4] = {0,0,-1,1};

queue<pair<int,int>> q;
queue<pair<int,int>> start_q;

void BFS(int max){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;
        q.pop();

        for(int i = 0; i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<N)&&visited[x_new][y_new]==0&&safty[x][y]>max){
                q.push({x_new, y_new});
                visited[x_new][y_new] = 1;
            }
        }
    }    
}

int main(){
    int max=0;
    cin >> N;

    for(int x=0; x<N; ++x){
        for(int y=0; y<N; ++y){
            int height;
            cin >> height;
            safty[x][y] = height;
            
        }
    }

    for(int i=1;i<100;++i){
        int cnt=0;
        //방문 인접행렬 초기화
        for(int x=0;x<N;++x){
            for(int y=0;y<N;++y){
                visited[x][y] = 0; 
                if(safty[x][y] > i){
                    start_q.push({x, y});
                }
            }
        }

        while(!start_q.empty()){
            int x = start_q.front().first;
            int y = start_q.front().second;
            start_q.pop();
            if(visited[x][y] == 0 && safty[x][y] > i){
                q.push({x, y});
                BFS(i);
                cnt++;
            }
        }
        if(cnt > max) max = cnt;
    }

    cout << max << endl;

    return 0;
}