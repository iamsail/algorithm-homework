#include <iostream>
using namespace std;

#define N 10
int p[15];
void qucikSort(int start, int end)
{
    if(start > end)return;
    int i,j,temp;
    int mid = p[start];

    i = start;
    j = end;
    while(i != j)
    {
        while(p[j] >= mid && i < j)
            j--;
        while(p[i] <= mid && i < j)
            i++;
        if(i < j)
        {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
    p[start] = p[i];
    p[i] = mid;
    qucikSort(start,i-1);
    qucikSort(i+1,end);
}

int printArray(int data[], int size)
{
    int i;
    for(i = 1; i <= size; i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

int main()
{
    for(int i = 1; i <= N; i++)
        cin>>p[i];
    qucikSort(1, N);
    printArray(p, N);
    return 0;
}

