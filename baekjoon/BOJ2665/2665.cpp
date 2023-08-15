/*2665번 미로 만들기*/
#include<iostream>
#include<queue>
#define INF 1e9
#define MAX 51
using namespace std;

int N;
int maze[MAX][MAX];
int weight[MAX][MAX];

queue<pair<int, int>> q;

int x_dist[4] = {-1,1,0,0};
int y_dist[4] = {0,0,-1,1};

void input(){
    cin >> N;

    for(int i = 0; i<N; ++i){
        string row;
        cin >> row;
        for(int j=0;j<N;++j){
            maze[i][j] = row[j] - '0';
            weight[i][j] = INF;
        }
    }
}

void BFS(){
    q.push({0,0});
    weight[0][0] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if(x_new>=0&&x_new<N&&y_new>=0&&y_new<N){
                if(maze[x_new][y_new] == 1){
                    if(weight[x_new][y_new] > weight[x][y]){
                        weight[x_new][y_new] = weight[x][y];
                        q.push({x_new, y_new});
                    }
                }
                else if(maze[x_new][y_new] == 0){
                    if(weight[x_new][y_new] > weight[x][y] + 1){
                        weight[x_new][y_new] = weight[x][y] + 1;
                        q.push({x_new, y_new});
                    }
                }
                
            }
        }
    }
}

int main(){
    input();

    BFS();

    cout << weight[N-1][N-1] << endl;

    return 0;
}