#include <iostream>
#include <algorithm>
using namespace std;

int N;

int cal(int a[],int b[]){
    int count = 0;
    for(int i = 0, j = 0; i < N && j < N;i++){
        if(a[i] > b[j]){
            count++;
            j++;

            if(count > N/2){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a[1002]={0};
    int b[1002]={0};

    while(cin >> N && N != 0){
        for(int i = 0 ; i < N; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < N; i++){
            cin >> b[i];
        }
        sort(a,a+N);
        sort(b,b+N);
        if(cal(a,b)){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}