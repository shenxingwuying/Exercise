#ifndef SomeSort_H
#define SomeSort_H

#include <iostream>
using namespace std;

/**********************************************************
******以下算法都是非降序排列（或者统称为升序排列）*********
******基本原则是：原地重排*********************************
***********************************************************/
template <class T>
void InsertSort(T a[],int left,int right);
template <class T>
void MergeSort(T a[],int left,int right);
template <class T>
void Merge(T a[],int left,int mid,int right);
template <class T>
void Output(T a[],int n);

/**插入排序 复杂度O(n^2)**/
template <class T>
void InsertSort(T a[],int left,int right)
{
	int n = right-left+1;
	for (int i = left+1;i < n;i++)
	{
		T temp = a[i];
		int j = i-1;
		while(j >= 0 && temp < a[j])	
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

/**归并排序,
复杂度O(n*log n)
**/
template <class T>
void MergeSort(T a[],int left,int right)
{
	int mid = (right+left)/2;
	if (left<right)
	{	
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,mid,right);
	}
}

/**归并排序，辅助**/
template <class T>
void Merge(T a[],int left,int mid,int right)
{
	T *temp = new T[right-left+1];//额外开销
	int i = left;
	int j = mid+1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (a[i] > a[j])
		{	
			temp[k++] = a[j];
			j++;
		}
		else
		{
			temp[k++] = a[i];
			i++;
		}
	}
	if (i > mid)
		while (j<=right) 
			temp[k++] = a[j++];
	if (j > right)
		while (i<=mid) 
			temp[k++] = a[i++];
	int end = right;
	while (k>0)
		a[end--] = temp[--k];
	delete[] temp;
}

/**按照非降序（升序）打印输出**/
template <class T>
void Output(T a[],int n)
{
	int i = 0;
	for(;i < n-1;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<a[i]<<endl;
}
#endif
