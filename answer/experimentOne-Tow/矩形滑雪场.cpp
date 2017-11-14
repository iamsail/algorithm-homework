#include"iostream"
#include"string.h"
#include"stdlib.h"
#include"algorithm"
using namespace std;
int m,n;
int dp[40400];

struct node
{
    int h,x,y;
}ai[40040];

bool compare(node a,node b)
{
    return a.h<b.h;
}
bool check(node a,node b)
{
    if(((a.x==b.x&&abs(a.y-b.y)==1)||(a.y==b.y&&abs(a.x-b.x)==1))&&b.h>a.h)
        return true;
    return false;
}

int main()
{
    int num=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ai[num].h;
            ai[num].x=i;
            ai[num].y=j;
            num++;
        }
    }
    sort(ai,ai+m*n,compare);
    int mmax=1;
    for(int i=0;i<num;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(check(ai[j],ai[i]))
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(dp[i]>mmax) mmax=dp[i];
    }
    cout<<mmax<<endl;
    return 0;
}