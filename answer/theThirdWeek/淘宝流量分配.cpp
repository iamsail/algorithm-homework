#include <iostream>
#define max(a,b) (a>b)?a:b;
using namespace std;

int n,a[10002],maxTime,dp[5002];

int cal(){
   if(n % 2){
       for(int i = 1; i <= n; i += 2){
           maxTime += a[i];
       }
   }else{
       for(int i = 1; i <= n - 2; i+=2){
           maxTime += a[i];
       }
       maxTime += max(a[n],a[n-1]);
   }
    cout<<maxTime;
}

int main() {
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cal();

    return 0;
}