#include<iostream>
#include<queue>
#define MAX 101
#define INF 1e9
using namespace std;

int N, E;
int maze[MAX][MAX];
int weight[MAX][MAX];

int x_dist[4] = {-1, 1, 0, 0};
int y_dist[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

void BFS(){
    q.push({0,0});
    weight[0][0] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<E)){
                if(maze[x_new][y_new] == 1){
                    if(weight[x_new][y_new] > weight[x][y] + 1){
                        weight[x_new][y_new] = weight[x][y] + 1;
                        q.push({x_new, y_new});
                    }
                }else if(maze[x_new][y_new]==0){
                    if(weight[x_new][y_new] > weight[x][y]){
                        weight[x_new][y_new] = weight[x][y];
                        q.push({x_new, y_new});
                    }
                }
            }
        }
    }
}

int main(){
    cin >> E >> N;

    for(int i = 0; i<N; ++i){
        string row;
        cin >> row;
        for(int j = 0; j<E; ++j){
            maze[i][j] = row[j] - '0';
            weight[i][j] = INF;
        }
    }

    BFS();
    
    cout << weight[N-1][E-1] << endl;

    return 0;
}