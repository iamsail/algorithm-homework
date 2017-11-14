#include <iostream>
using namespace std;
const int maxNumber = 105;

int N;
int a[maxNumber][maxNumber];

int prim(){
    int ans = 0;
    int lowCost[maxNumber] = {0};
    bool s[maxNumber];

    s[1] = true;
    for(int i = 2; i <= N; i++){
        lowCost[i] = a[1][i];
        s[i] = false;
    }

    for(int i = 1; i < N; i++){
        int min = 99999999;
        int j = 1;
        for(int k = 2; k <= N; k++){
            if((!s[k]) && lowCost[k] < min){
                min = lowCost[k];
                j = k;
            }
        }

        s[j] = true;
        ans += min;

        for(int k = 2; k <= N; k++){
            if(a[j][k] < lowCost[k] && (!s[k])){
                lowCost[k] = a[j][k];
            }
        }
    }
    return ans;

}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }

    cout << prim() <<endl;
    return 0;
}