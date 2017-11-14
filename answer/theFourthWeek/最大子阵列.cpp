//#include <iostream>
//using namespace std;
//
//int main() {
//
//    return 0;
//}


#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[1001],i,sum=0;
        int max = -10000000;
        for(i=0;i<n;i++)
            cin>>a[i];

        for(i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>=max)
            {
                max=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
