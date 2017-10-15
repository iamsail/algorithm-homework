#include <iostream>
using namespace std;

int CFArray[12];
int main(){
    int T;
    while(cin>>T){
        if(T==0)break;

        for(int i = 0; i <= T; i++){
            cin >> CFArray[i];
        }
        float IRR,irrLeft = -1.0, irrRight = 9999.0;
        for(int i = 0; i < 100;i++){
            IRR = ( irrLeft + irrRight ) / 2;
            float sum = 0,Denominator = 1;
            for(int i = 0; i <= T ; i++){
                sum += CFArray[i] / Denominator;
                Denominator *= (1 + IRR);
            }
            if(sum >= 0)irrLeft = IRR;
            else irrRight = IRR;
        }
        printf("%.2lf\n", irrLeft);
    }
    return 0;
}



