#include <iostream>
#include <algorithm>
using namespace std;

int a[10002] ={0};
int b[10002] ={0};
int n;

bool cmp(int x,int y){
    return x > y;
};

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n,cmp);

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += abs(a[i] - b[i]);
    }
    cout<<sum;
    return 0;
}