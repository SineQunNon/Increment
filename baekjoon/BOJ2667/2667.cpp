#include<iostream>
#include <queue>
#include <list>
#define MAX 26
using namespace std;

int N;
int matrix[MAX][MAX];  //0과 1을 저장할 2차원 배열
int visited[MAX][MAX]; //방문 여부를 저장할 2차원 배열
list<int> house;

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

queue<pair<int,int>> q;

int BFS(){
    int x_start=0, y_start=0;
    //시작점 찾기
    for(int i = 1; i<=N; ++i){
        for(int j = 1; j<=N; ++j){
            if(matrix[i][j]==1 && visited[i][j]==0){
                x_start = i;
                y_start = j;
                break;
            }
        }
        if(x_start != 0 && y_start != 0) break;
    }
    if(x_start==0 && y_start==0) return 0;

    visited[x_start][y_start] = 1;
    q.push(make_pair(x_start, y_start));
    int house_num = 1;
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        for(int i=0;i<4; ++i){
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            if((x_new>=1&&x_new<=N)&&(y_new>=1&&y_new<=N)&&visited[x_new][y_new]==0&&matrix[x_new][y_new]==1){
                q.push(make_pair(x_new, y_new));
                visited[x_new][y_new]=1;
                house_num++;
            }
        }
    }
    return house_num;
}

int main(){
    cin >> N;

    for(int i = 1; i<=N; ++i){
        string row;
        cin >> row;

        for(int j = 1; j<=N; ++j){
            matrix[i][j] = row[j-1] -'0';
        }
    }
    
    while(true){
        int num = BFS();
        if(num == 0) break;
        else{
            house.push_back(num);
        }
    }
    
    cout << house.size() << endl;
    house.sort();
    for(auto& i : house){
        cout << i << endl;
    }
    return 0;
}