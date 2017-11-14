#include <iostream>
#include <cstring>

using namespace std;
int n;
int chess[10][10];
int sum = 0; //统计放法
int xBlack[10],xWhite[10];

bool placeBlack(int k,int column){
    if(chess[k][column] == 0) return false;
    for(int i = 0; i < k; i++){
        if((abs(k - i) == abs(xBlack[k] - xBlack[i])) || (xBlack[i] == xBlack[k])){
            return  false;
        }
    }
    return true;
}

bool placeWhite(int k,int column){
    if(chess[k][column] == 0) return false;
    if(xBlack[k] == column)return false;
    for(int i = 0; i < k; i++){
        if((abs(k - i) == abs(xWhite[k] - xWhite[i])) || (xWhite[i] == xWhite[k])){
            return  false;
        }
    }
    return true;
}

void backTrapWhite(int t){
    if(t == n){
        sum++;
        return;
    }
    for(int i = 0; i < n; i++){
        xWhite[t] = i;
        if(placeWhite(t,i)){
            backTrapWhite(t + 1);
        }
        xWhite[t] = -1;
    }
}

void backTrapBlack(int t){
    if(t == n){
        backTrapWhite(0);
        return;
    }

    for(int i = 0; i < n; i++){
        xBlack[t] = i;
        if(placeBlack(t,i)){
            backTrapBlack(t + 1);
        }
        xBlack[t] = -1;
    }
}

int main() {
    cin >> n;
    memset(xBlack,-1,sizeof(xBlack));
    memset(xWhite,-1,sizeof(xWhite));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> chess[i][j];
        }
    }
    backTrapBlack(0);
    cout << sum;
    return 0;
}








