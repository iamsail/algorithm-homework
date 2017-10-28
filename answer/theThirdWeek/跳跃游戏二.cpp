#include <iostream>
#define  min(a,b) (a < b)?a:b;

const int inf  = 666666;

using namespace std;

int n,a[102],least = 0,small[102];
int cal(){
    small[0] = 0;
    for(int i = 0 ; i < n; i++){
        //TODO: j <= a[i] 如何理解
        //TODO: 一步跳出  不需要循环
            for(int j = 1 ; j <= a[i] && i + j < n; j++){
               small[i + j] = min(small[i + j] , small[i] + 1);
            }
        }
    cout<< small[n - 1];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        small[i] = inf;
    }
    cal();
    return 0;
}