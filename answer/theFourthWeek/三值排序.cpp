#include <iostream>
#define max(a,b) (a>b)?a:b;
using namespace std;
int main() {
    int n;
    int a[1002]={0};
    int b[5]={0};
    int x = 0,y = 0,z = 0;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]]++;
    }

    for(int i = 1; i <= b[1]; i++){
        if(a[i] != 1)x++;
    }

    for(int i = b[1]+1; i <= b[1]+b[2]; i++){
        if(a[i] == 3)y++;
    }

    for(int i = b[1] + b[2] + 1; i <= n; i++){
        if(a[i] == 2)z++;
    }

    int temp = max(y,z);
    int result = x + temp;
    cout<<result<<endl;
    return 0;
}
