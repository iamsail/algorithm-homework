#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T,n,m,H,lightSourceLocation[100002];
    cin>>T;
    while(T--){
        scanf("%d %d %d",&n,&m,&H);
        for(int i = 1; i <= m;i++){
            scanf("%d",&lightSourceLocation[i]);
        }
        sort(lightSourceLocation + 1,lightSourceLocation + m +1);
        for(int i = 1; i <=n ; i++){
           int  Subscript = lower_bound(lightSourceLocation + 1,lightSourceLocation +1+m,i)-lightSourceLocation;
           int  height = 0;
           if(m && Subscript ==1){
               height = max(height,H-lightSourceLocation[Subscript] + i);
           }else if(m && Subscript == m + 1){
               height = max(height,H -i + lightSourceLocation[Subscript - 1]);
           } else if(m){
               height = max(0,max(H -i + lightSourceLocation[Subscript - 1],H-lightSourceLocation[Subscript] + i));
           }
            printf("%d\n",height);
        }
    }
    return 0;
}




