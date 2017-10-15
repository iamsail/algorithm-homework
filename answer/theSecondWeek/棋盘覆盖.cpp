#include <iostream>
#include <algorithm>
using namespace std;

int tile = 1;
int Board[1026][1026];

void ChessBoard(int tr,int tc,int dr,int dc,int size){
    if(size == 1) return;
    int t = tile++,s = size / 2;
    if(dr < tr + s && dc < tc + s){
        ChessBoard(tr,tc,dr,dc,s);
    }else{
        Board[tr + s -1][tc + s -1] = t;
        ChessBoard(tr,tc,tr + s -1,tc + s -1,s);
    }

    if(dr < tr + s && dc >= tc + s){
        ChessBoard(tr,tc + s,dr,dc,s);
    }else{
        Board[tr + s -1][tc + s] = t;
        ChessBoard(tr,tc + s,tr + s -1,tc + s,s);
    }

    if(dr >= tr + s && dc < tc + s){
        ChessBoard(tr + s,tc,dr,dc,s);
    }else{
        Board[tr + s][tc + s - 1] = t;
        ChessBoard(tr + s,tc ,tr + s ,tc + s - 1,s);
    }

    if(dr >= tr + s && dc >= tc + s){
        ChessBoard(tr + s,tc + s,dr,dc,s);
    }else{
        Board[tr + s][tc + s] = t;
        ChessBoard(tr + s,tc + s,tr + s ,tc + s,s);
    }
}


int main() {
    int k,x,y,size;
    while(cin >> k >> x >> y){
        size = pow(2,k);
        tile = 1;
        ChessBoard(0,0,x,y,size);1
        for(int i = 0;i < size; i++){
            for(int j = 0;j < size; j++){
                if(j == size -1){
                    cout<<Board[i][j]<<endl;
                }else{
                    cout<<Board[i][j]<<" ";
                }
            }
        }
    }
    return 0;
}