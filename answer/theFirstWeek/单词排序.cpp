#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    string str[26];
    for(int i = 0; i < n ; i++)
        cin >> str[i];
    sort(str, str + n);
    for (int i = 0; i < n; i++)
    {
        (i == 0)?(cout << str[i]):(cout << " " << str[i]);
    }
    return 0;
}