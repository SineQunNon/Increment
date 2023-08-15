#include<iostream>
#include<queue>
#define INF 500
#define MAX 21
using namespace std;

int N, E;
int graph[MAX][MAX];
int alphabet[26];

int x_dist[4] = {-1,1,0,0};
int y_dist[4] = {0,0,-1,1};

queue<pair<int, int>> q;

void BFS(){
    q.push({0,0});
    dist[0][0] = 1;
    alphabet[graph[0][0]] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4; ++i){
            int x_new = x + x_dist[i];
            int y_new = y + y_dist[i];

            if(x_new>=0&&x_new<E&&y_new>=0&&y_new<N){

            }
        }
    }
}


int main(){
    cin >> N >> E;
    for(int y=0;y<N; ++y){
        string row;
        cin >> row;
        for(int x=0;x<E; ++x){
            graph[y][x] = row[x] - 'A';
        }
    }

    for(int y=0;y<N; ++y){
        for(int x=0;x<E; ++x){
            cout << graph[y][x] << " ";
        }cout << "\n";
    }

    return 0;
}