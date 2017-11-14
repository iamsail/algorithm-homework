#include <iostream>
#include <cstring>
using namespace std;

const int n = 8;
int x[10] = {0};
int chess[10][10];
int maxValue,tempValue;

bool place(int k){
    for(int i = 0; i < k; i++){
        if((abs(k - i) == abs(x[k] - x[i])) || (x[i] == x[k]))return false;
    }
    return true;
}

void backTrap(int t){
    if(t == n){
        maxValue = max(maxValue,tempValue);
        return;
    }

    for(int i = 0; i < n; i++){
        x[t]  = i;
        tempValue += chess[t][i];
        if(place(t)){
            backTrap(t+1);
        }
//        x[t]  = -1;
        tempValue -= chess[t][i];
    }
}

int main() {
    int k;
    cin >> k;
    while(k--){
        maxValue = 0,tempValue = 0;
        memset(x,-1, sizeof(x));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> chess[i][j];
            }
        }

        backTrap(0);
        cout << maxValue<<endl;
    }
    return 0;
}