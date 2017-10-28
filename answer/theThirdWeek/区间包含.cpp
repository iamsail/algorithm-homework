#include<iostream>
#include<vector>
#include<deque>

#include<algorithm>

using namespace std;

#define maxn 100010
#define maxm 18

struct Interval
{
    int l, r;
    Interval(int _l, int _r) : l(_l), r(_r) {}
    Interval(){}
};

bool cmp(Interval i1, Interval i2)
{
    return i1.l < i2.l || (i1.r < i2.r && i1.l == i2.l);
}

int N, M;
Interval in[maxn];
vector<int> V;
int dp[2*maxn][18];//用dp[i][j]表示从横坐标为i开始, 向右走(1 << j)个有效区间的区间的右端点坐标

int main()
{
    while(~scanf("%d %d", &N, &M))
    {
        V.clear();
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d", &in[i].l, &in[i].r);
            V.push_back(in[i].l);
            V.push_back(in[i].r);
        }

        sort(V.begin(), V.end());
        int size = unique(V.begin(), V.end()) - V.begin();
        V.resize(size);
        for(int i = 0; i < N; i++)
        {
            in[i].l = lower_bound(V.begin(), V.end(), in[i].l) - V.begin();
            in[i].r = lower_bound(V.begin(), V.end(), in[i].r) - V.begin();//这里in[i].r一定存在所以没有问题
        }//离散化完成
        sort(in, in + N, cmp);//按左端点第一关键字递增, 右端点为第二关键字递增排序
        //先处理出所有的dp[i][0]
        int R = size, pos = N - 1;
        for(int i = size - 1; i >= 0; i--)//横坐标
        {
            while(pos >= 0 && in[pos].l >= i)
                R = min(R, in[pos--].r);
            dp[i][0] = R;
        }
        for(int j = 1; j < maxm; j++)
            for(int i = 0; i < size; i++)
                if(dp[i][j - 1] < size)
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                else dp[i][j] = size;

        int l, r;
        while(M--)
        {
            scanf("%d %d", &l, &r);
            l = lower_bound(V.begin(), V.end(), l) - V.begin();
            //r = lower_bound(V.begin(), V.end(), r) - V.begin(); lower_bound在元素不存在时返回假设这个元素存在时应该在的位置
            r = upper_bound(V.begin(), V.end(), r) - V.begin() - 1;
            if(l == size || r <= l || r < 0)
            {
                puts("0");
                continue;
            }
            int k = maxm;
            int ans = 0;
            while(k)
            {
                k--;
                if(dp[l][k] <= r)
                {
                    ans += (1 << k);
                    l = dp[l][k];
                }
            }
            printf("%d\n", ans);
        }

    }
    return 0;
}

