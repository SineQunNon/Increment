/*4485번 녹색 입은 애가 젤다지?*/
#include<iostream>
#include<queue>
#include<vector>
#define INF 2e9
#define MAX 126
using namespace std;

int N;
int cave[MAX][MAX];
int weight[MAX][MAX];

int x_dist[4] = {-1, 1, 0, 0};
int y_dist[4] = {0, 0, -1, 1};

void BFS(){
    queue<pair<int, int>> q;

    q.push({0,0});
    weight[0][0] = cave[0][0];

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<N)){
                if(weight[x_new][y_new] > weight[x][y] + cave[x_new][y_new]){
                    weight[x_new][y_new] = weight[x][y] + cave[x_new][y_new];
                    q.push({x_new, y_new});
                }
            }
        }
    }
}

void input(){
//동굴 값 입력 받기
    for(int i=0;i<N; ++i){
        for(int j = 0; j<N; ++j){
            cin >> cave[i][j];
            weight[i][j] = INF;
        }
    }
}


int main(){
    int order = 1;
    do{
        cin >> N;
        if(N==0) break;
        
        input();
        BFS();
        cout << "Problem " << order++ << ": "<< weight[N-1][N-1] << "\n";
    }while(N!=0);
    
    return 0;
}