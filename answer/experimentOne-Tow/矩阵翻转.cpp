#include <iostream>
using namespace std;
int main() {
    int M,N,T,a[300][200],b[300][200];
    cin>>M>>N>>T;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }

    if(T == 1){
        for(int i = 1; i <= M / 2; i++){
            for(int j = 1; j <= N; j++){
                b[i][j] = a[M - i + 1][j];
                b[M - i + 1][j] = a[i][j];
            }
        }
        if(M % 2){
            for(int j = 1;j <= N; j++)
            b[M / 2 + 1][j] = a[M / 2 + 1][j];
        }
    }else if(T == 0){
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N / 2; j++){
                b[i][j] = a[i][N - j + 1];
                b[i][N - j + 1] = a[i][j];
            }
        }
        if(N % 2){
            for(int i = 1;i <= N; i++)
                b[i][N / 2 + 1] = a[i][N / 2 + 1];
        }
    }


    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cout << b[i][j]<<" ";
            if(j == N){
                cout<< endl;
            }
        }
    }
    return 0;
}