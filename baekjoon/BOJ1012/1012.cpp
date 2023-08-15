#include<iostream>
#include<queue>
#include<list>
#define MAX 50
using namespace std;

int cabbage[MAX][MAX];
int visited[MAX][MAX];

int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
list<int> earth_num;

queue<pair<int,int>> q;

//0리턴 시 모두 방문됐다는 의미
//1리턴 시 하나의 군집이 있다는 소리
int BFS(int column, int row){
    int x_start=-1, y_start=-1;
    //시작점 찾기
    for(int i = 0; i<column; ++i){
        for(int j =0; j<row; ++j){
            if(cabbage[i][j]==1 &&visited[i][j]==0){
                x_start=i;
                y_start=j;
                break;
            }
        }
        if(x_start != -1 && y_start != -1) break;
    }
    if(x_start == -1 && y_start == -1) return 0;
    
    visited[x_start][y_start] = 1;
    
    q.push(make_pair(x_start, y_start));
    
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
    
        q.pop();
        for(int k=0;k<4;++k){

            int x_new = x + x_dir[k];
            int y_new = y + y_dir[k];

            if((x_new>=0&&x_new<column)&&(y_new>=0&&y_new<row)&&visited[x_new][y_new]==0&&cabbage[x_new][y_new]==1){
                q.push(make_pair(x_new, y_new));
                visited[x_new][y_new]=1;
            }
        }
    }

    return 1;
}

int main(){
    int testcase;

    cin >> testcase;

    for(int i = 0; i<testcase;++i){
        int group_num=0;
        int column, row, K; //가로, 세로, 배추의 수
        cin >> column >> row >> K;

        //배추의 개수
        for(int j = 0; j<K; ++j){
            int v, w;
            cin >> v >> w;
            cabbage[v][w] = 1;
        }

        while(true){
            int num = BFS(column, row);
            if(num == 0) {
                
                earth_num.push_back(group_num);
                break;
            }
            else{
                group_num++;
            }
            
        }

        //배추 및 방문 여부를 저장하는 배열 0으로 초기화
        for(int i = 0; i<MAX; ++i){
            for(int j=0; j<MAX; ++j){
                cabbage[i][j]=0;
                visited[i][j]=0;
            }
        }


    }

    for(auto& i : earth_num){
        cout << i << endl;
    }

    return 0;
}