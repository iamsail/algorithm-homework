#include <iostream>
using namespace std;

int n,a[502];
bool allPositive = true;
int maxInex = 1;

int cal(){
    for(int i = 1; i <= n; i++){
        if( i > maxInex ){
            cout<<"false";return 0;
        }
        if( i + a[i] > maxInex){
            maxInex = i + a[i];
        }
    }
    cout<<"true";return 0;
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) allPositive = false;
    }

    if(allPositive) {cout <<"true";return 0;}
    cal();
    return 0;
}

































