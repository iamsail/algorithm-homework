#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 25;
int vis[maxn][maxn]; //存放一个个状态
int A,B,C;
void dfs(int a,int b,int c)
{
    vis[a][b] = 1;
    if(a<A){//
        if(c>=A-a&&vis[A][b]==0)dfs(A,b,c-A+a);//可倒满
        if(c<A-a&&vis[a+c][b]==0)dfs(a+c,b,0);//从c倒入a，不可倒满，以下也是
        if(b>=A-a&&vis[A][b-A+a]==0)dfs(A,b-A+a,c);
        if(b<A-a&&vis[a+b][0]==0)dfs(a+b,0,c);//从b倒入a
    }
    if(b<B){
        if(c>=B-b&&vis[a][B]==0)dfs(a,B,c-B+b);
        if(c<B-b&&vis[a][b+c]==0)dfs(a,b+c,0);//从c倒入b
        if(a>=B-b&&vis[a-B+b][B]==0)dfs(a-B+b,B,c);
        if(a<B-b&&vis[0][a+b]==0)dfs(0,a+b,c);//从a倒入b
    }
    if(c<C){
        if(a>=C-c&&vis[a-C+c][b]==0)dfs(a-C+c,b,C);
        if(a<C-c&&vis[0][b]==0)dfs(0,b,c+a);//从a倒入c
        if(b>=C-c&&vis[a][b-C+c]==0)dfs(a,b-C+c,C);
        if(b<C-c&&vis[a][0]==0)dfs(a,0,b+c);//从b倒入c
    }
}

int main()
{

    cin>>A>>B>>C;
    memset(vis,0,sizeof(vis));
    dfs(0,0,C);
    int flag = 1;
    for(int i = B;i >= 0;i--)
    {
        if(vis[0][i])
        {
            if(flag)
                flag = 0;
            else cout<<" ";
            cout<<C - i;
        }
    }
    return 0;
}