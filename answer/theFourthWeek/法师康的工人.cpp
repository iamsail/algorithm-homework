#include <iostream>
#include <algorithm>
#define max(a,b) (a>b)?a:b;
using namespace std;

int n;
struct node{
    int left,right;
}a[5050];

bool cmp(node x,node y){
    if(x.left == y.left) return  x.right < y.right;
    else return x.left < y.left;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>a[i].left>>a[i].right;
    }
    sort(a,a+n,cmp);

    int personTime = a[0].right - a[0].left;
    int noPersonTime = 0;
    int startTime = a[0].left,endTime = a[0].right;

    for(int i = 1; i < n; i++){
        if(a[i].left > endTime){
            noPersonTime =max(noPersonTime,a[i].left - endTime);
            startTime = a[i].left;
        }
        endTime = max(endTime,a[i].right);
        personTime = max(personTime,endTime - startTime);
    }
    cout << personTime <<" "<<noPersonTime<<endl;
    return 0;
}

