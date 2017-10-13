#include <iostream>
using namespace std;
int main() {
    int n,a[10],i = 0;
    for(int i = 0;i<10;i++)
        a[i] = -1;

    cin >> n;
    while(n >= 8){
        a[i] = n % 8;
        n = n / 8;
        i++;
    }
    cout<<n;
    for(int i = 9;i >= 0 ; i--){
        if(a[i] >= 0){
            cout<<a[i];
        }
    }
    return 0;
}