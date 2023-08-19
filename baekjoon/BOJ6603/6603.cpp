#include<iostream>
using namespace std;


int lottery[13];
bool check[13];
int n;

void DFS(int cnt, int idx){
    if(idx>n) return;
    if(cnt == 6){
        for(int i=0;i<13;i++){
            if(check[i]==true){
                cout << lottery[i] << " ";
            }
        }cout << "\n";
        return;
    }
    check[idx] = true;
    DFS(cnt+1, idx+1);

    check[idx] = false;
    DFS(cnt, idx+1);
}

int main(){
    cin >> n;

    while(n!=0){
        for(int i=0; i<n; ++i){
            cin >> lottery[i];
        }

        DFS(0, 0);
        cout << "\n";
        for(int i=0;i<13;++i){
            check[i] =false;
        }
        cin >> n;
    }

    return 0;
}