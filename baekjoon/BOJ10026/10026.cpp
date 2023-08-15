#include<iostream>
#include<queue>
#define MAX 100
using namespace std;

int picture1[MAX][MAX];
int picture2[MAX][MAX];
int visited[MAX][MAX];
int N;
int x_dist[4] = {-1,1,0,0};
int y_dist[4] = {0,0,-1,1};

queue<pair<int, int>> q;
queue<pair<int, int>> check_q1;
queue<pair<int, int>> check_q2;

void BFS(int x_start, int y_start){
    int value = picture1[x_start][y_start];
    visited[x_start][y_start] = 1;
    q.push({x_start, y_start});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<N)&&visited[x_new][y_new] == 0 && picture1[x_new][y_new]==value){
                q.push({x_new, y_new});
                visited[x_new][y_new] = 1;
            }
        }
    }
}

void BFS_weakness(int x_start, int y_start){
    int value = picture2[x_start][y_start];
    visited[x_start][y_start] = 1;
    q.push({x_start, y_start});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if((x_new>=0&&x_new<N)&&(y_new>=0&&y_new<N)&&visited[x_new][y_new] == 0 && picture2[x_new][y_new]==value){
                q.push({x_new, y_new});
                visited[x_new][y_new] = 1;
            }
        }
    }
}

int main(){
    cin >> N;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<N; ++i){
        string color;
        cin >> color;
        //R : 82, G : 71, B : 66
        for(int j=0;j<N; ++j){
            if(color[j] == 'R'){
                picture1[i][j] = 1;
                picture2[i][j] = 1;
            }else if(color[j] == 'G'){
                picture1[i][j] = 2;
                picture2[i][j] = 1;
            }else if(color[j] == 'B'){
                picture1[i][j] = 3;
                picture2[i][j] = 2;
            }
            check_q1.push({i, j});
            check_q2.push({i, j});
        }
    }
   

    while(!check_q1.empty()){
        int x_start = check_q1.front().first;
        int y_start = check_q1.front().second;
        check_q1.pop();
        if(visited[x_start][y_start] == 0){
            BFS(x_start, y_start);
            cnt1++;
        }
    }
    
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)
            visited[i][j] =0;
    }

    while(!check_q2.empty()){
        int x_start = check_q2.front().first;
        int y_start = check_q2.front().second;
        check_q2.pop();
        if(visited[x_start][y_start] == 0){
            BFS_weakness(x_start, y_start);
            cnt2++;
        }
    }

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}