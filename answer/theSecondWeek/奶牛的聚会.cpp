#include <iostream>
#include <algorithm>
using namespace std;
int n;
double negativeIndex(double Xi,double inputArray[500001][2]){
    double ans=0,temp;
    for(int i = 1; i <= n; i++ ){
        temp = fabs(Xi - inputArray[i][0]);
        if(inputArray[i][1] && temp){       ans += (temp * temp * temp * inputArray[i][1]); }
    };
    return ans;
}

double countMinWi(){
    scanf("%d",&n);
    double low,high,mid1,mid2,inputArray[50001][2],xArray[50001];
    for(int i = 1; i <= n;i++){
        scanf("%lf%lf",&inputArray[i][0],&inputArray[i][1]);
        xArray[i] = inputArray[i][0];
    }

    sort(xArray,xArray + n);
    low = xArray[1];
    high = xArray[n];
    for(int i = 0;i < 200;i++){
        mid1 = (low + high) / 2;
        mid2 = (mid1 + high) / 2;
        double f1 = negativeIndex(mid1,inputArray);
        double f2 = negativeIndex(mid2,inputArray);
        if(f1 < f2){
            high = mid2;
        }else if(f1 > f2){
            low = mid1;
        }else{break;}
    }
    double flow = negativeIndex(low,inputArray);
    return flow;
}

int roundDouble(double number)
{
    return (number > 0.0) ? (number + 0.5) : (number - 0.5);
}

int main() {
    int Ca,temp;
    double ans;
    scanf("%d",&Ca);
    temp = Ca;
    while(Ca && Ca--){
        ans = countMinWi();
        printf("Case #%d: %d\n",(temp-Ca),roundDouble(ans));
    }
    return 0;
}