#include <iostream>

using namespace std;

template<class T>
void ShellSort(T a[],int n);
template<class T>
void Output(T a[],int n);

template<class T>
void ShellSort(T a[],int n)
{
	int gap, i, j;

	for (gap = (n+1)/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i-gap; j >= 0 && a[j] > a[j+gap]; j -= gap)
				swap(a[j],a[j+gap]);
		}
	}
}

template<class T>
void Output(T a[],int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] <<" ";
	cout << endl;
}
