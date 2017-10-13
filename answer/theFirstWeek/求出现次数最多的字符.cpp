#include <iostream>
using namespace std;
/*
 * 桶排的思想
 *
 * */

int main() {
    string str;
    int countLetter[52]={0};
    int maxCount = 0;
    cin>>str;
    int n = str.length();
    for(int i = 0; i < n ; i++){
        countLetter[str[i]-65]++;
    }

    for(int i = 0; i < 52 ; i++){
        if(countLetter[i] && countLetter[i] > maxCount){
            maxCount = countLetter[i];
        }
    }

    for(int i = 26; i < 52; i++){
        if(countLetter[i] == maxCount){
            cout<<char(i+65)<<" "<<maxCount<<endl;
        }
    }

    for(int i = 0; i < 26; i++){
        if(countLetter[i] == maxCount){
            cout<<char(i+65)<<" "<<maxCount<<endl;
        }
    }
    return 0;
}
