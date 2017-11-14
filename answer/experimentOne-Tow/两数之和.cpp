#include <iostream>
using namespace std;
int main() {
    int n,target,index1,index2;
    int a[502];
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin>>a[i];
    }
    cin >> target;

    for(int i = 1; i < n;i++){
        for(int j = i + 1; j <= n;j++){
            if(a[i] + a[j] == target){
                index1 = i;
                index2 = j;
                break;
            }
        }
    }
    cout<<index1<<" "<<index2;
    return 0;
}