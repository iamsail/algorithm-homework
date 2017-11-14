//#include <iostream>
//using namespace std;
//
//int max(int a,int b){
//    return (a > b)?a:b;
//}
//
//int main() {
//    string a;
//    cin >> a;
//
//    string str[260];
//    int length = 0,otherLength;  // length  第二行输入的字符串数目
//    for(int i = 0; i < 256; i++){
//        cin >> str[i];
//        length++;
//        if(getchar() == '\n'){  //回车结束
//            break;
//        }
//    }
//
//    int lengthArray[256];
//
//    for(int i = 0;i < length; i++){
//        int  tempLength = 1;
//        bool flag = false; // flag 表示还没有匹配过
//        int preFlag = 0, nowFlag = 0;
//        for(int j = 0; j < str[i].length(); j++){   //对每个字符进行判断
//            for(int k = 0; k < 26;k++){
//                if(str[i][j] == a[k]){
////                    cout<<"==========="<<endl;
//                    if(!flag){      //初次匹配
////                        cout<<" 11111  "<<endl;
//                        nowFlag = k;
//                        flag = true;
//                        tempLength = 1;
//                    }else{         //非初次匹配
//                        nowFlag = k;
////                        cout<<"  preFlag   nowFlag  "<<preFlag<<"    "<<nowFlag<<endl;
//                        if(nowFlag < preFlag){
////                            cout<<" 222222  "<<endl;
//
//                            tempLength = 1;
//                        }else{
////                            cout<<" 333333  "<<endl;
//
//                            tempLength++;
//                        }
//                    }
//                    preFlag = k;
//                }
////                cout<<"23333333333333"<<endl;
//            }
//            cout<<"   tempLength    "<<tempLength<<endl;
//            lengthArray[i] = max(lengthArray[i],tempLength);
//        }
//    }
//
//
//
//        for(int i = 0; i < length; i++){
//            if(lengthArray[i] != 0)
//                cout<<lengthArray[i]<<endl;
//        }
//    return 0;
//}
//
//
//
//

#include<iostream>
#include<string>
using namespace std;

const int maxn = 100000;
int order[26];
int dp[maxn];

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int i, j;
    for(i = 0; i < n; ++i){
        order[s[i] - 'a'] = i;
    }
    int temp, res;
    while(cin >> s){
        n = s.length();
        res = 0;
        for(i = 0; i < n; ++i){
            dp[i] = 1;
            for(j = 0; j < i; ++j){
                if(order[s[j] - 'a'] <= order[s[i] - 'a'] && (temp = dp[j] + 1) > dp[i]){
                    dp[i] = temp;
                }
            }
            res = max(res, dp[i]);
        }
        cout << res;
    }
    cout << endl;
}
