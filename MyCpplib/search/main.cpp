#include <iostream>
#include "BinarySearch.h"

using namespace std;
template <class T>
void output(T a[],int n);
int main()
{
    int a[] = {-5,-3,0,0,2,2,2,2,6,8};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "The a[] ";
    output(a,n);
    int index;

    int test[] = {-6,-5,-3,0,0,1,2,2,2,2,6,8,9};
    int len = sizeof(test)/sizeof(test[0]);
    int i;
    cout << "The test[] ";
    output(test,len);
    cout << "递归二分搜索算法" <<endl;
    for (i = 0;i < len;i++)
    {
        if (binarySearch(test[i],a,0,n-1,&index)==NULL)
        {
            cout << test[i] << " The index is null" << endl;
            continue;
        }
        cout << *binarySearch(test[i],a,0,len-1,&index) << " ";
        cout <<"The index is:"<< index << endl;
    }
    cout << "循环二分搜索算法" <<endl;
    for (i = 0;i < len;i++)
    {
        if (binSearch(test[i],a,n,&index)==NULL)
        {
            cout << test[i] << " The index is null" << endl;
            continue;
        }
        cout << *binSearch(test[i],a,len,&index) << " ";
        cout <<"The index is:"<< index << endl;
    }
    return 0;
}

template <class T>
void output(T a[],int n)
{
    assert(a);
    int i = 0;
    for (; i < n; i++)
        cout << a[i] <<" ";
    cout << endl;
}
