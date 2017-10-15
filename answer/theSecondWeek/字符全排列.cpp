#include <iostream>
using namespace std;

int aimStrLength,letterToAsciiNumber[30],a[30],count,finalStrLength;
string aimStr;
string finalStr;
void dfs(int step){
    if(step == aimStrLength + 1){
        count++;
        for(int i = 1;i <= aimStrLength;i++){
            finalStr += char(a[i]+ 96);

        }
        finalStr += " ";
        return;
    }
    for(int i = 1; i <= aimStrLength; i++){
        if (letterToAsciiNumber[i]>0)
        {
            a[step]=i;
            letterToAsciiNumber[i]--;
            dfs(step+1);
            letterToAsciiNumber[i]++;
        }
    }
    return;
}

int main() {
    cin>>aimStr;
    aimStrLength = static_cast<int>(aimStr.length() - 1);
    for (int i=0;i < aimStrLength;++i){
        letterToAsciiNumber[aimStr[i] - 96]++;
    }
    dfs(1);
    finalStrLength = static_cast<int>(finalStr.length() -1);
    for(int i = 0; i < finalStrLength; i++) {
        cout<<finalStr[i];
    }
    return 0;
}









