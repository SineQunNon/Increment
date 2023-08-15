#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int N, E, H;
int tomato[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
queue<pair<int, pair<int, int>>> q;

int x_dist[6] = {-1,1,0,0,0,0};
int y_dist[6] = {0,0,-1,1,0,0};
int z_dist[6] = {0,0,0,0,-1,1};

void BFS(){
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int z = q.front().first;
        
        visited[x][y][z] = 1;
        q.pop();

        for(int i =0; i<6; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];
            int z_new = z + z_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<E)&&(z_new>=0&&z_new<H)&&visited[x_new][y_new][z_new]==0&&tomato[x_new][y_new][z_new]==-1){
                visited[x_new][y_new][z_new] = 1;
                q.push({z_new,{x_new,y_new}});
                if(dist[x_new][y_new][z_new] == 0){
                    dist[x_new][y_new][z_new] = dist[x][y][z] + 1;
                }else if(dist[x_new][y_new][z_new] > dist[x][y][z] +1){
                    dist[x_new][y_new][z_new] = dist[x][y][z] + 1;
                }
            }
        }
    }
}

int Check_dist(){
    int max_dist = 0;
    for(int z = 0; z < H; ++z){
        for(int x = 0; x < N; ++x){
            for(int y = 0; y < E; ++y){
                if(tomato[x][y][z] == -1 && dist[x][y][z] == 0) return -1;
                if(dist[x][y][z] > max_dist){
                    max_dist = dist[x][y][z];
                }
            }
        }
    }

    return max_dist;
}

int main(){
    cin >> E >> N >> H;

    for(int z=0;z<H;++z){
        for(int x = 0; x<N; ++x){
            for(int y = 0; y<E; ++y){
                int status;
                cin >> status;
                if(status == 1){
                    //익은 토마토
                    tomato[x][y][z] = 1;
                    q.push({z,{x,y}});
                }else if(status == 0){ 
                    //익지 않은 토마토
                    tomato[x][y][z] = -1;
                }
                //비어 있는 토마토는 0
            }
        }
    }

    BFS();

    cout << Check_dist() << endl;
    return 0;
}