#ifndef BinarySearch_H
#define BinarySearch_H
#include <assert.h>
template<class T>
T *binarySearch(T value,T a[],int left,int right,int *index)
{
    assert(a);
    if (left > right)
    {
        *index = -1;
        return NULL;
    }
    int mid = (right + left)/2;
    if (value == a[mid])
    {
        *index = mid;
        return &a[mid];
    }
    else if (value < a[mid])
    {
        return binarySearch(value,a,left,mid-1,index);
    }
    else
    {
        return binarySearch(value,a,mid+1,right,index);
    }
}

template<class T>
T *binSearch(T value,T a[],int n,int *index)
{
    assert(a);
    int left = 0;
    int right = n-1;
    int mid;
    while (left <= right)
    {
        mid = (left+right)/2;
        if (a[mid] == value)
        {
            *index = mid;
            return &a[mid];
        }
        else if (a[mid] > value)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    *index = -1;
    return NULL;
}
#endif
