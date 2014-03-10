/**快速排序**/
template <class T>
void QuickSort(T a[],int left,int right)
{
	if (left >= right)
		return;
	T pivot = a[left];
	
	int i = left;
	int j = right+1;
	
	while(true)
	{
		do
		{
			i++;
		}while (i <= right && a[i] <= pivot );//左边，找大于pivot的元素
		do
		{
			j--;
		}while (j >= left && a[j] > pivot);//右边，找不大于pivot的元素

		if(i >= j)
			break;
		T t;//交换
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	a[left] = a[j];
	a[j] = pivot;

	QuickSort(a,left,j-1);
	QuickSort(a,j+1,right);
}

