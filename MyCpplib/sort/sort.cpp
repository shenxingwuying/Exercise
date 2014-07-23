#ifndef DU_SORT_H
#define DU_SORT_H

#include<iostream>
using namespace std;

//#include "sort.h"


/**
 * 论曰：快速排序，算法导论实现版本。
 * PS：个人感觉这一版很简洁，故而收录。
 * 快速排序另一种实现方式**/

/**
 *@function Partition:
 *@desc: 第把pivot,放在它应该在的位置，并且将数组数字分成两组
 *@return: 
 */
template <class T>
int Partition(T a[],int left,int right)
{
	T pivot = a[right];
	int i = left - 1;
	for(int j=left;j<=right-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[right]);
	return (i+1);
}
/**快速排序另一种实现方式, 原地重排**/
template <class T>
void Quick(T a[],int left,int right)
{
	if(left < right)
	{
		int mid = Partition(a,left,right);
		Quick(a,left,mid-1);
		Quick(a,mid+1,right);
	}
}

/**
 * 找第k小的数 
 */
template <class T>
int SeekMinK(T a[],int left, int right, int k)
{
    if(left < right)
    {
        int mid = Partition(a, left, right);

        int temp = mid-left+1;

        if(temp == k)
            return a[mid];
        else if(temp > k)
            return SeekMinK(a, left, mid-1, k);
        else
            return SeekMinK(a, mid+1, right, k-temp);
    }
    return a[left];
}


/**
 * 取中位数，如果双中位数，则取左中位数
 */
template <class T>
int SeekMidValue(T a[], int left, int right)
{
    int k, r = (right - left)%2;
    if (r==0)
        k = (right - left)/2;
    else
        k = (right - left)/2+1;

//    int k = (right - left + 1)/2 + 1;
    return SeekMinK(a, left, right, k);
}

#endif
