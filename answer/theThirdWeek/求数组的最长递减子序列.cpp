#include <iostream>
#define max(a,b) (a>b)?a:b;
using namespace std;
int n,number[1001],length = 0,result[1001] = {1};//result是辅助数组
//http://blog.csdn.net/army_war/article/details/38236085

int other[1001];
int otherIndex = 0;

/**
    * @param PLA
    *
    */
/*算法描述：
 * 用动态规划解决此问题，设A为原数组，另设数组B（大小与A相同）做为辅助数组，其中
 * B[i]用来存储以A[i]为结尾的最长递减子序列的长度，比如i=3，A[3]=2比其前面任何
 * 元素都小，所以B[3]=4.
 * 可以得出：B[i]=max(B[k]+1,A[k]>A[i]&&0=<k<i),且B[0]=1
 * 遍历一遍，得出最长递减子序列长度，设为K，并设max_i为取得最长长度是在原数组A中的位置，
 * 则A[max_i]必为最小值。
 * 且A[max_i]为自序列中最后一个元素，从K开始，往回搜索，当满足B[i]+1==B[k]&&
 * A[i]>A[k]时，则A[i]就是前一个元素，递归求出该自序列。
 * 算法复杂度为O(n^2)。
 * */

int count = 0;

int print(int finalIndex){
    for(int i = finalIndex; i >= 0 ; i--){
        if(number[i] > number[finalIndex] && result[finalIndex] == result[i] + 1){
            print(i);
            break;
        }
    }
    other[otherIndex] = number[finalIndex];
    otherIndex++;
    length++;
}

int cal(){
    int finalIndex = 0; // 最长长度序列末尾在数组中的位置
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < i; j++){
            if(number[j] > number[i] && (result[j] + 1) > result[i]){
                result[i] = result[j] + 1;
                finalIndex = i;
            }
        }
    }
    print(finalIndex);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> number[i];
    }
    cal();
    for(int i = 0; i < length; i++){
        cout << other[i];
        if(i < length -1)cout<<" ";

    }
    return 0;
}






//
//
//
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#define maxn 5006
//#define inf 0x3f3f3f3f
//#include <cstring>
//#define ll long long
//using namespace std;
//int a[maxn];
//int dp[maxn];
//int num[maxn];
//int my[maxn];
//int main(){
//    int n;
//    while(scanf("%d",&n)!=EOF){
//        for(int i=1;i<=n;++i)scanf("%d",&a[i]),dp[i]=1;
//        int tmp=0,ans=0,z;
//        for(int i=1;i<=n;++i){
//            bool flag=true;
//            for(int j=i-1;j>=1;--j)
//                if(a[i]==a[j]){flag=false;break;}
//                else if(a[j]>a[i]&&dp[j]+1>dp[i])dp[i]=dp[j]+1,num[i]=num[j];
//                else if(a[j]>a[i]&&dp[j]+1==dp[i])num[i]+=num[j];
//            if(flag)num[i]=max(num[i],1),dp[i]=max(dp[i],1);
//            ans=max(ans,dp[i]);
//        }
//        int res=0;
//        for(int i=1;i<=n;++i)if(dp[i]==ans)res+=num[i];
//        printf("%d %d\n",ans,res);
//    }
//    return 0;
//}
//
//






