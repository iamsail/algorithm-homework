#include <iostream>
#include <algorithm>
using namespace std;
int w,n,p[30005];
int compare(int a,int b){
    return a > b;
}

int cal(){
    int least = 0;
    int startIndex = 0;
    int endIndex = n - 1;
    if(n == 1) {cout<<1;return 0;}
    for(int i = startIndex ; i < n; ){
//        cout<<"执行了 startIndex    endIndex   "<<startIndex<<"   "<<endIndex<<"     "<<endl;
        if(p[startIndex] + p[ endIndex] <= w){
            least++;
            startIndex++;
            endIndex--;
//            cout<<"此时least1    "<<least<<endl;
        }else if(p[startIndex] + p[ endIndex] > w){
            startIndex++;
            least++;
//            cout<<"此时least2    "<<least<<endl;
        }

        i = startIndex;

        if(startIndex == endIndex){
          if(p[startIndex] <= w){
              least++;
          }
          break;
        }

        if(startIndex - 1 == endIndex){
            break;
        }
    }
    cout<<least;
}

int main() {
    cin >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p,p+n,compare);
//    for(int i = 0; i < n; i++){
//        cout << p[i] <<"   ";
//    }
//    cout<<endl;
    cal();
    return 0;
}