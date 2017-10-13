#include <iostream>
#include <string>
using namespace std;

int index( string &parentStr, string &sonStr)
{
    int i = 0, j = 0;
    int parentStrLength = parentStr.length();
    int sonStrLength = sonStr.length();

    while(i < parentStrLength && j < sonStrLength)
    {
        if(parentStr[i] == sonStr[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i-j+1;
            j = 0;
        }
    }
    if(j == sonStrLength){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int m,n,aimStrLength;
    while(cin >> n >> m){
        string waitAdd[200]={""};
        string aimStr,allStr;
        allStr = "";
        aimStr = "";

        for(int i = 0;i < n;i++){
            cin>>waitAdd[i];
            for(int j = 0;j < m;j++){
                if(waitAdd[i][j] >= 'a'){
                    waitAdd[i][j] = waitAdd[i][j] - 32;
                }
            }
            allStr += waitAdd[i];
        }
        cin>>aimStr;
        aimStrLength = aimStr.length();
        for(int i = 0;i < aimStrLength;i++){
            if(aimStr[i] >= 'a'){
                aimStr[i] = aimStr[i] - 32;
            }
        }
        index(allStr,aimStr);
    }
    return 0;
}




