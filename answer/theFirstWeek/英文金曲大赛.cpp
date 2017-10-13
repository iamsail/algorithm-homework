#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
        int a[7]={0},max,min;
        while(cin>>a[0]){
            string name;
            float sumScore=a[0];
            float avgScore;
            max = a[0];
            min = a[0];
            for(int i = 1; i < 7; i++){
                cin>>a[i];
                if(a[i] > max){
                    max = a[i];
                }
                if(a[i] < min){
                    min = a[i];
                }
                sumScore += a[i];
            }
            cin>>name;
            avgScore = (sumScore - max -min) / 5.0;
            cout<<name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<avgScore<<endl;
        }
        return 0;
}




//string name;
//int a[7]={0}, sumScore=0, max=0;
//int min = 0;
//float avgScore;
//for(int i = 0; i < 7; i++){
//cin>>a[i];
//if(i == 0){
//min = a[i];
//}
//
//if(a[i] > max){
//max = a[i];
//}
//if(a[i] < min){
//min = a[i];
//}
//sumScore += a[i];
//}
//cin>>name;
//avgScore = (sumScore - max -min) / 5;
//cout<<name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<avgScore<<endl;
//return 0;