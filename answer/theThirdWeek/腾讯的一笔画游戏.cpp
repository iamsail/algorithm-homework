#include <iostream>
#include <tgmath.h>

using namespace std;

const double PI = 3.1415926;

int n,k;
double L,finalScore;


double cal(){
    double angle;
    angle = (n - 2) * 180 / n;
    finalScore = (n -1) * L;

    if (k != 0)//k不等于0再加上L/2
        finalScore += L / 2;

    for(int i = 1; i <= k; i++){
        L = 2 * (L/2 * L / 2) - 2 * (L/2 * L / 2)* cos(angle / 180 * PI);
        L =sqrt(L);
        finalScore += (n -1) * L;
        if( i != k)
            finalScore += L / 2;
    }
    printf("%lf", finalScore);
}

int main() {
    cin>>n>>k;
    cin>>L;
    cal();
    return 0;
}












//#include<bits/stdc++.h>
//using namespace std;
//const double PI = 3.1415926;
//int main()
//{
//    int n, k;
//    double L,area,ans;
//    cin >> n >> k>>L;
//    area = (n-2)*180/n;//正n边形的内角计算
//    ans = (n - 1)*L;//当K==0的时候
//    if (k != 0)//k不等于0再加上L/2
//        ans += L / 2;
//    for (int i = 1; i <= k; i++)
//    {
//        L = 2*(L / 2 * L / 2)  - 2 * (L / 2 * L / 2)*cos(area / 180 * PI);
//        L = sqrt(L);
//                cout<<"L   "<<L<<endl;
//        ans += (n - 1)*L;
//        if (i != k)
//            ans += L / 2;
//    }
//    printf("%lf", ans);//默认小数点后保留6位
//    //cout<<ans;  输出562.132 默认6位精度
//    return 0;
//}
//









