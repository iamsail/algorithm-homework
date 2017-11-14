#include <iostream>
using namespace std;
int main() {
    int n,a[200000]={0};
    cin >> n;
    for(int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        a[temp + 100000]++;
    }

    int length=0;
    for(int i = 0;i < 200000;i++)
    {
        if(a[i] >=2){
            length += 2;
        }else{
            length += a[i];
        }
    }
    cout<<length;
    return 0;
}