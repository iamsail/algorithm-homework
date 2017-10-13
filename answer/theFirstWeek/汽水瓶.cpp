#include <iostream>
using namespace std;
int main() {
    int n;
    while(cin >> n && n){
        int drinkCount = 0;
        int emptyBottle = 0;
        if(n == 0){
            break;
        }else if(n == 1){
            drinkCount = 0;
            cout<<drinkCount<<endl;
        }else if(n <= 3){
            drinkCount = 1;
            cout<<drinkCount<<endl;
        }else if(n == 4){
            drinkCount = 2;
            cout<<drinkCount<<endl;
        }else{
            while(n > 4){
                emptyBottle = n % 3;
                n = n / 3;
                drinkCount += n;
                n += emptyBottle;
            }
             if(n <= 3){
                drinkCount += 1;
                cout<<drinkCount<<endl;
            }else if(n == 4){
                drinkCount += 2;
                cout<<drinkCount<<endl;
            }
        }
    }
    return 0;
}