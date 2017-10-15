#include <iostream>
const int mod=100000007;
using namespace std;

long long int fastPower(long long a,long long b){
    long long ans= 1,base = a;
    while(b){
        if( b&1 ){ans *= base;ans %=mod;}
        base*=base%mod;
        base%=mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int x;
    while(cin>>x){
        if(x){
            long long finalResult = 0;
            while(x > 0){
                finalResult += fastPower(x,x);
                x--;
            }
            cout<<(finalResult + 1) % 100000007 <<endl;
        }
    }
    return 0;
}


