#include <iostream>
using namespace std;

int M,S,T;
int initialTime;
int cal(){
   initialTime = T;
   int distance = 0;
   int tempDistance = 0;
    while(initialTime--){
        if(M >= 10){
            M -= 10;
            distance += 60;
        }else{
            M += 4;
        }
        tempDistance += 17;
        if(distance > tempDistance)tempDistance = distance;
        if(tempDistance > S)break;
   }
    return tempDistance;
}

int main() {
    cin >> M >> S >> T; //魔法初值 M，他所在的初始位置与岛的出口之间的距离 S，岛沉没的时间 T
    int distance = cal();
    if(distance >= S && T >= 0){cout<<"Yes"<<endl<<T - initialTime;}
    else cout<<"No"<<endl<<distance;
    return 0;
}