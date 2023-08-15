#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
#define INF 1e7
using namespace std;

int N, E;
int maze[MAX][MAX];
int weight[MAX][MAX];
bool visited[MAX][MAX][2];

int x_dist[4] = {-1,1,0,0};
int y_dist[4] = {0,0,-1,1};

void BFS(){
    queue<pair<int,pair<int, int>>> q;
    q.push({0,{0,0}});
    weight[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(x == E-1&&y==N-1) return;

        for(int i=0; i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];
            

            if(x_new>=0&&x_new<E&&y_new>=0&&y_new<N){
                if(maze[y_new][x_new]==1&&cnt ==0){
                    if(weight[y_new][x_new] > weight[y][x] + 1){
                        weight[y_new][x_new] = weight[y][x] + 1;
                        q.push({x_new, {y_new, 1}});
                    }
                }else if(maze[y_new][x_new] == 0&&cnt == 1){
                    if(weight[y_new][x_new] >= weight[y][x] + 1){
                        weight[y_new][x_new] = weight[y][x] + 1;
                        q.push({x_new, {y_new, 1}});
                    }
                }else if(maze[y_new][x_new] == 0&&cnt == 0){
                    if(weight[y_new][x_new] >= weight[y][x] + 1){
                        weight[y_new][x_new] = weight[y][x] + 1;
                        q.push({x_new, {y_new, 0}});
                    }
                }
            }
        }
    }
}

int main(){
    cin >> N >> E;

    for(int y=0;y<N; ++y){
        string row;
        cin >> row;
        for(int x=0; x<E; ++x){
            maze[y][x] = row[x] -'0';
            weight[y][x] = INF;
        }
    }

    BFS();

    // for(int y=0;y<N;++y){
    //     for(int x=0;x<E;++x){
    //         cout << weight[y][x] << " ";
    //     }cout << "\n";
    // }
    cout << INF << endl;

    if(weight[N-1][E-1]==INF) cout << "-1" << endl;
    else cout << weight[N-1][E-1] << endl;

    return 0;
}