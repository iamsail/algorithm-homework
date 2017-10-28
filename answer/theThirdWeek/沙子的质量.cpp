#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f
#define M 305

using namespace std;

int sum[M],f[M][M],sand[M],n;


int dp(int l,int r){
    if(f[l][r] != -1)return f[l][r];
    if(l == r)return 0;
    int ans = inf;
    for(int i = l;i < r; i++)
        ans = min(ans,dp(l,i)+dp(i+1,r));
    return f[l][r] = (ans + sum[r] - sum[l - 1]);
}




int main(){
    memset(f,-1,sizeof(f));
    cin>>n;
    for(int i = 1;i <= n; i++)cin>>sand[i];
    for(int i = 1;i <= n; i++)sum[i] += sum[i -1] + sand[i];
    cout<<dp(1,n);

    return 0;
}

