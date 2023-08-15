#include<iostream>
#define MAX 1001

using namespace std;

int RGB[MAX][3];
int t;

int get_min(int start){
    int pre = start;
    int min = RGB[0][start];
    for(int i=1;i<t; ++i){
        if(pre==0&&i!=t-1){
            int k1, k2;
            k1 = RGB[i+1][0] > RGB[i+1][2] ? RGB[i][1] + RGB[i+1][2] : RGB[i][1] + RGB[i+1][0];
            k2 = RGB[i+1][0] > RGB[i+1][1] ? RGB[i][2] + RGB[i+1][1] : RGB[i][2] + RGB[i+1][0];

            if(k1 > k2){
                min += RGB[i][2];
                pre = 2;
            }else if(k1 < k2){
                min += RGB[i][1];
                pre = 1;
            }else if(RGB[i][1] > RGB[i][2]){
                min += RGB[i][2];
                pre = 2;
            }else if(RGB[i][1] < RGB[i][2]){
                min += RGB[i][1];
                pre = 1;
            }else if(RGB[i+1][1] > RGB[i+1][2]){
                min += RGB[i+1][2];
                pre = 2;
            }else if(RGB[i+1][1] <= RGB[i+1][2]){
                min += RGB[i+1][1];
                pre = 1;
            }
        }else if(pre==1 && i!=t-1){ //이전 값이 G였다면
            int k0, k2;
            k0 = RGB[i+1][1] > RGB[i+1][2] ? RGB[i][0] + RGB[i+1][2] : RGB[i][0] + RGB[i+1][1];
            k2 = RGB[i+1][0] > RGB[i+1][1] ? RGB[i][2] + RGB[i+1][1] : RGB[i][2] + RGB[i+1][0];

            if(k0 > k2){
                min += RGB[i][2];
                pre = 2;
            }else if(k0 < k2){
                min += RGB[i][0];
                pre = 0;
            }else if(RGB[i][1] > RGB[i][2]){
                min += RGB[i][2];
                pre = 2;
            }else if(RGB[i][0] < RGB[i][2]){
                min += RGB[i][0];
                pre = 0;
            }else if(RGB[i+1][0] > RGB[i+1][2]){
                min += RGB[i+1][2];
                pre = 2;
            }else if(RGB[i+1][0] <= RGB[i+1][2]){
                min += RGB[i+1][0];
                pre = 0;
            }
        }else if(pre==2&& i!=t-1){//이전 값이 B였다면
            int k0, k1;
            k0 = RGB[i+1][1] > RGB[i+1][2] ? RGB[i][0] + RGB[i+1][2] : RGB[i][0] + RGB[i+1][1];
            k1 = RGB[i+1][0] > RGB[i+1][2] ? RGB[i][1] + RGB[i+1][2] : RGB[i][1] + RGB[i+1][0];

            if(k0 > k1){
                min += RGB[i][1];
                pre = 1;
            }else if(k0 < k1){
                min += RGB[i][0];
                pre = 0;
            }else if(RGB[i][1] > RGB[i][0]){
                min += RGB[i][0];
                pre = 0;
            }else if(RGB[i][0] < RGB[i][1]){
                min += RGB[i][0];
                pre = 0;
            }else if(RGB[i+1][0] > RGB[i+1][1]){
                min += RGB[i+1][1];
                pre = 1;
            }else if(RGB[i+1][0] <= RGB[i+1][1]){
                min += RGB[i+1][0];
                pre = 0;
            }           
        }else if(pre==0){
            if(RGB[i][1] >=RGB[i][2]){
                min += RGB[i][2];
            }else{
                min += RGB[i][1];
            }
        }else if(pre==1){
            if(RGB[i][0] >=RGB[i][2]){
                min += RGB[i][2];
            }else{
                min += RGB[i][0];
            }
        }else if(pre==2){
            if(RGB[i][1] >=RGB[i][0]){
                min += RGB[i][0];
            }else{
                min += RGB[i][1];
            }
        }
    }

    return min;
}

int main(){
    int min[3];
    int value;
    cin >> t;


    for(int i=0;i<t; ++i){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }

    min[0] = get_min(0);
    min[1] = get_min(1);
    min[2] = get_min(2);

    // cout << min[0] << " " << min[1] << " " << min[2];
    if(min[0] >= min[1]){
        if(min[1] >= min[2]){
            cout << min[2];
        }else{
            cout << min[1];
        }
    }else{
        if(min[0] >= min[2]){
            cout << min[2];
        }else{
            cout << min[0];
        }
    }
    

    return 0;
}