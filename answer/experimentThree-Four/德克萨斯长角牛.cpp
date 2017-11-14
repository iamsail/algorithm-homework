//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int t,c,ts,te,rs,re,ci,i,j,minj,Min;
//int s[2505],a[2505][2505];
//bool b[2505];
//
//int main()
//{
//    scanf("%d%d%d%d",&t,&c,&ts,&te);
//    for (i=1;i<=c;++i)
//    {
//        scanf("%d%d%d",&rs,&re,&ci);
//        a[rs][re]=ci;
//        a[re][rs]=ci;
//    }
//    for (i=1;i<=t;++i)
//        s[i]=0x7777777;
//    s[ts]=0;
//    minj=ts;
//    for (i=1;i<=t-1;++i)
//    {
//        Min=0x7777777;
//        for (j=1;j<=t;++j)
//            if (!b[j]&&s[j]<Min)
//            {
//                Min=s[j];
//                minj=j;
//            }
//        b[minj]=true;
//        for (j=1;j<=t;++j)
//            if (!b[j]&&a[minj][j])
//                if (s[minj]+a[minj][j]<s[j])
//                    s[j]=s[minj]+a[minj][j];
//    }
//    if (s[te]!=0x7777777)
//        printf("%d",s[te]);
//    return 0;
//}




#include<iostream>
using namespace std;

int main(){
    int a[2505][2505];
    int x;
    cin >>x;
    return 0;
}