#include<iostream>
#include<string.h>
#include<queue>
#define MAX 1000
using namespace std;

int N, E;
int tomato[MAX][MAX];
int dist[MAX][MAX];
int visited[MAX][MAX];

int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ((x_new >= 0 && x_new < N) && (y_new >= 0 && y_new < E) && visited[x_new][y_new] == 0 && tomato[x_new][y_new] == -1) {
                visited[x_new][y_new] = 1;
                q.push(make_pair(x_new, y_new));
                if (dist[x_new][y_new] == 0) {
                    dist[x_new][y_new] = dist[x][y] + 1;
                }
                else if (dist[x_new][y_new] > dist[x][y] + 1) {
                    dist[x_new][y_new] = dist[x][y] + 1;
                }

            }
        }
    }
}

int Check_dist() {
    int max_dist = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < E; ++j) {
            if (tomato[i][j] == -1 && dist[i][j] == 0) return -1;
            if (dist[i][j] > max_dist) {
                max_dist = dist[i][j];
            }
        }
    }
    return max_dist;
}


int main() {
    cin >> E >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < E; ++j) {
            int status;
            cin >> status;

            //비어 있는 토마토
            if (status == -1) {
                tomato[i][j] = 0;
                //익은 토마토
            }
            else if (status == 1) {
                tomato[i][j] = 1;
                //익지 않은 토마토
                q.push(make_pair(i, j));
            }
            else if (status == 0) {
                tomato[i][j] = -1;
            }
        }
    }

    BFS();

    cout << Check_dist() << endl;

    return 0;
}