/*BOJ 1183*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main(){
    int N;
    cin >> N;

    for(int i =0; i<N;++i){
        int a,b;
        cin >> a >> b;
        v.push_back(a-b);
    }

    sort(v.begin(),v.end());

    if(N%2==0){ //짝수이면 가운데 값
        cout << v[N/2] - v[N/2-1] + 1 << endl;
    }else{
        cout << "1" << endl;
    }

    return 0;
}