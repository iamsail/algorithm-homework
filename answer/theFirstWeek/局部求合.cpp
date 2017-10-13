#include <iostream>
using namespace std;
int main() {
    int a[20];
    int b[20] = {0};
    for(int i = 0; i < 20; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 20 ; i++){

        for(int j = 0; j < 20 ; j++){

                if(i != j && (a[i] % a[j] == 0) && b[i]== 0){
                    cout << a[i]<<endl;
                    b[i] = 1;
                }
        }
    }
    return 0;
}