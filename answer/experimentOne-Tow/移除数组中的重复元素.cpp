#include <iostream>
using namespace std;
int main() {
    int n,a[2003]= { 0 };
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[temp+1000] ++;

    }

    int length = 0;
    for(int i = 0;i <= 2003;i++){
        if(a[i] > 0) length++;
    }
    cout<<length;
    return 0;
}