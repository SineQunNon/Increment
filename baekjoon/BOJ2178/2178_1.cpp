#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int N, M; //미로 크기 입력 받기
int maze[MAX][MAX]; //미로 정보 저장
int visited[MAX][MAX]; //방문했는가 여부 저장
int dist[MAX][MAX]; //이동 거리 저장

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0 , -1, 1};

queue<pair<int, int>> q;

void BFS(int x_start, int y_start){
    visited[x_start][y_start] = 1;
    q.push(make_pair(x_start, y_start));
    dist[x_start][y_start]++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4;++i){
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<M)&&!visited[x_new][y_new]&&maze[x_new][y_new]==1){
                visited[x_new][y_new] = 1;
                q.push(make_pair(x_new, y_new));
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i<N; ++i){
        string row;
        cin >> row;

        for(int j = 0; j<M; ++j){
            maze[i][j] = row[j] -'0';
        }
    }

    BFS(0, 0);

    cout << dist[N-1][M-1];

    return 0;
}