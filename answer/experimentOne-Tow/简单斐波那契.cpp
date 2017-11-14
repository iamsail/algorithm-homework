#include <iostream>
using namespace std;
int Count(int N){
    int sum = 0;

    if(N == 0){sum =0;}
    else if(N == 1){sum =1;}
    else if(N > 1){
            sum += Count(N -1);
            sum += Count(N -2);
    }
    return sum;
}


int main() {
    int N;
    cin >> N;
    cout<<Count(N);
    return 0;
}