#include <iostream>
#define MAX 2003
#define max(x,y) (x>=y)?x:y;
using namespace std;

string a,b;
int C[MAX][MAX];

int maxLength(int lenA,int lenB){
    int i,j;
    for( i = 0; i <= lenA; i++ )C[i][0]=0;
    for( i = 0; i <= lenB; i++ )C[0][i]=0;

    for( i = 1; i <= lenA; i++)
        for( j = 1; j <= lenB ; j++){
            if(a[i-1] == b[j-1]){C[i][j] = C[i-1][j-1] + 1;}
//            else C[i][j] = max(C[i-1][j],C[i][j-1]);
            else if(C[i-1][j] >= C[i][j-1]){ C[i][j] =  C[i-1][j];}
            else { C[i][j] =  C[i][j - 1]; }
        }

    return C[lenA][lenB];
}



int main() {
    cin>>a>>b;
    int lenA = a.length(),lenB = b.length();
    cout<<maxLength(lenA,lenB);
    return 0;
}