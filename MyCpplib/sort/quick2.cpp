/**快速排序另一种实现方式**/
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
