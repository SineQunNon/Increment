/*BOJ 11727 2xn타일2 */
#include <iostream>
using namespace std;

int tiling[1001];

int main(){
    int n;
    cin >> n;

    tiling[1] = 1;
    for(int i=2; i<=n; ++i){
        if(i%2==0){ //짝수 항이면 x2 + 1
            tiling[i] = tiling[i-1]*2 + 1;
        }else{ //홀수 항이면 x2 - 1
            tiling[i] = tiling[i-1]*2 - 1;
        }

        if(tiling[i]>=10007){
            tiling[i] %= 10007;
        }
    }
    cout << tiling[n] << endl;
    return 0;
}