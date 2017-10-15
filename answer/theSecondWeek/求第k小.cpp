#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,k,numberArrays[1000000];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d",&numberArrays[i]);
    }
    sort(numberArrays,numberArrays + n);
    printf("%d",numberArrays[k - 1]) ;
    return 0;
}