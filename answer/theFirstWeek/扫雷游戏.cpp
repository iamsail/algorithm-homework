#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin >> n >>m;
    string str[500];
    for(int i = 0; i < n;  i++){
        cin >> str[i];
    }

    for(int i = 0; i < n ; i++){

        for(int j = 0; j < m ; j++){
            int tempCount = 0;
            if((str[i][j] != '*')){
                if( i > 0 && j > 0){
                    if(  str[i-1][j-1] == '*')tempCount++;
                }
                if(i>0){
                    if( str[i-1][j]   == '*')tempCount++;
                    if(str[i-1][j+1]  == '*')tempCount++;
                }

                if(j>0){
                    if( str[i][j-1]   == '*')tempCount++;
                    if( str[i+1][j-1] == '*')tempCount++;
                }

                if( str[i][j+1]   == '*')tempCount++;
                if(str[i+1][j]    == '*')tempCount++;
                if( str[i+1][j+1] == '*')tempCount++;
                cout<<tempCount;
            }else{
                cout<<"*";
            }
            if(j == m-1)cout<<endl;
        }
    }
    return 0;
}