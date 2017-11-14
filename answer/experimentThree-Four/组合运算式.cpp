#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10;
int fa[maxn];

void dfs(int cur,int n)
{
    if(cur == n+1)
    {
        int sum = 0;
        int temp = 1;
        int x = 1;
        for(int i = 2; i <= n; i++){
            if(fa[i] == 1)
            {
                if(x == 1)
                    sum += temp;
                else
                    sum -= temp;
                temp = i;  //记录运算数字
                x = 1;     //记录运算符号
            }
            else if(fa[i] == 2)
            {
                if(x == 1)
                    sum += temp;
                else
                    sum -= temp;
                temp = i;
                x = 2;
            }
            else
                temp = temp*10+i;
        }
        //记录sum值
        if(x == 1)
            sum += temp;
        else
            sum -= temp;
        if(!sum)
        {
            printf("1");
            for(int i = 2; i <= n; i++)
                if(fa[i] == 1)
                    printf("+%d", i);
                else if(fa[i] == 2)
                    printf("-%d", i);
                else if(fa[i] == 3)
                    printf(" %d", i);
            printf("\n");
        }
        return ;
    }
    fa[cur] = 3; // 空格
    dfs(cur+1, n);
    fa[cur] = 1; // 加号
    dfs(cur+1, n);
    fa[cur] = 2; // 减号
    dfs(cur+1, n);
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        memset(fa,0,sizeof(fa));
        dfs(2,n);
    }
    return 0;
}
