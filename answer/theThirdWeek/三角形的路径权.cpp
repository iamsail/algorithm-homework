#include <iostream>
#define max(x,y) (x>y)?x:y;
using namespace std;

//TODO:分析的时候把一个点四周的坐标的表示出来就迎刃而解了
//   [i-1][j-1]       [i-1][j]
//              [i][j]
//   [i+1][j]         [i+1][j+1]

int main(){
    int n,a[1001][1001];
    cin >> n;
    for(int i = 1; i  <= n;i++)
        for(int j = 1; j  <= i;j++)
            cin>>a[i][j];

    for(int i = n - 1; i > 0;i--){
        for(int j = 1;j <= i; j++){
            a[i][j] += max(a[i + 1][j],a[i + 1][j + 1]);
        }
    }
    cout<<a[1][1];
    return 0;
}