#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int SpaceValue[104][2];
int m[105][1101]={0};


int cal(int n,int c){

    int jMax = min(SpaceValue[n][0] - 1,c);
    for(int j = 0; j <= jMax; j++)m[n][j]=0;
    for(int j = SpaceValue[n][0]; j <= c; j++)m[n][j] =  SpaceValue[n][1];
    for(int i = n -1; i > 1; i--){
        jMax = min(SpaceValue[i][0] - 1, c);
        for(int j = 0;j <= jMax; j++)m[i][j] = m[i + 1][j];
        for(int j = SpaceValue[i][0];j <= c; j++)m[i][j] = max(m[i+1][j],m[i+1][j - SpaceValue[i][0]] + SpaceValue[i][1]);
    }

    m[1][c] = m[2][c];
    if(c >= SpaceValue[1][0])m[1][c] = max(m[1][c],m[2][c - SpaceValue[1][0]] + SpaceValue[1][1]);
    cout<<m[1][c]<<endl;
}



int main() {
    memset(SpaceValue,0, sizeof(SpaceValue));
    int T,M;
    cin >> T >> M;// M是草药树木,T是时间
    for(int i = 1; i <= M ; i++){
        cin >> SpaceValue[i][0] >> SpaceValue[i][1];
    }
    cal(M,T);
    return 0;
}







