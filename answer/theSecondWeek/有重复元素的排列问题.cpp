#include<iostream>
#include<cstring>
using namespace std;
char aimStr[30];
int ans;
void dfs(int step,int aimStrLength,int a[],int letterToAsciiNumber[])
{
    int r;
    if (step==aimStrLength+1)
    {
        ans++;
        for (r=1;r<=aimStrLength;++r)
            printf("%c",a[r]+96);
        printf("\n");
        return;
    }
    for (r=1;r<=26;++r)
        if (letterToAsciiNumber[r]>0)
        {
            a[step]=r;
            letterToAsciiNumber[r]--;
            dfs(step+1,aimStrLength,a,letterToAsciiNumber);
            letterToAsciiNumber[r]++;
        }
}

void handle(){
    int letterToAsciiNumber[30],a[30],T,aimStrLength;
    scanf("%d",&T);
    while(T--){
        cin>>aimStr;
        aimStrLength = strlen(aimStr);
        ans = 0;
        for(int i = 0; i < 27 ; i++){
            letterToAsciiNumber[i] = 0;
        }

        for (int i=0;i<aimStrLength;++i)
            letterToAsciiNumber[aimStr[i]-96]++;

        dfs(1,aimStrLength,a,letterToAsciiNumber);
        printf("%d\n",ans);
    }
}

int main()
{
    handle();
    return 0;
}






