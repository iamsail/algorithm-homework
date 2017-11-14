#include <iostream>
#include <cstring>

#define min(a,b) (a<b)?(a):(b)
using namespace std;

int a[11]={0};
int n;
int leastCost;
int small[102] ;  //记录n公里的最小费用

int cal(){
    memset(small,0x3f3f3f3f,sizeof(small));
    small[0] = 0;
    for(int i = 1; i <= n ; i++){
        for(int j = 0; j <= 10; j++){
            if(i >= j){
                small[i] = min(small[i],small[i -j] + a[j]);
            }
        }
    }
    leastCost = small[n];
    return leastCost;
}

int main() {
    for(int i = 1; i <= 10; i++){
        cin >> a[i];
    }
    cin >> n;
    cout << cal();
    return 0;
}







//#include<iostream>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//int n,a[11],b[205];
//int main()
//{
//    for(int i=1;i<=10;i++)
//        scanf("%d",&a[i]);
//    scanf("%d",&n);
//    memset(b,0x7f,sizeof(b));
//    b[0]=0;
//    for(int i=0;i<=n-1;i++)
//        for(int j=1;j<=10;j++)
//            b[i+j]=min(b[i]+a[j],b[i+j]);
//    printf("%d\n",b[n]);
//    return 0;
//}