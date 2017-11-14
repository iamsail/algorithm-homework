#include <iostream>
using namespace std;
struct node{
    int time;
    int value;
    double averageValue;
}paper[22];

void sort(node *paper ,int m){
    for(int i = 0; i < m -1; i++){
        for(int j = i +1; j < m ;j++){
            if(paper[j].averageValue > paper[i].averageValue){
                swap(paper[j].averageValue,paper[i].averageValue);
                swap(paper[j].time,paper[i].time);
                swap(paper[j].value,paper[i].value);
            }
        }
    }
}

int main() {
    int m,n;
    while(cin >> m >> n &&(m||n)){
        for(int i = 0; i < m; i++){
            int t,v;
            cin >> t >>v;
            paper[i].time = t;
            paper[i].value = v;
            paper[i].averageValue = double(v) / double(t);
        }
        //TODO:排序
        sort(paper,m);
        int sTime = 0;
        double sumValue = 0;
        for(int paperIndex = 0; paperIndex < m; paperIndex++){
            if(sTime + paper[paperIndex].time < n){
                sumValue += paper[paperIndex].value;
                sTime += paper[paperIndex].time;
            }else{
                sumValue += (n -sTime) * paper[paperIndex].averageValue;
                break;
            }
        }
        printf("%.2lf\n",sumValue);
    }
    return 0;
}