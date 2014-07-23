 /*************************************************************************
    @File Name: main.cpp
    @Author: duyuqi
    @Mail: duyuqi@baidu.com 
    @CreatedTime: 一  5/26 17:43:01 2014
 ************************************************************************/

#include "sort.cpp"

void output(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
};

void test(int a[], int n, int k)
{
    printf("第%d小的数字为:%d\n", k, SeekMinK(a, 0, n-1, k));
}

int main()
{
    int a[] = {9, 10, 7, 1, 2 ,3 ,4, 6, 7 ,8, -4};
   
    int n = sizeof(a)/sizeof(a[0]);

    output(a, n);
    Quick(a, 0, n-1);
    output(a, n);
   
    for(int i=0;i < n;i++)
    {
        a[0] = 9;
        a[1] = 10;
        a[2] = 7;
        a[3] = 1;
        a[4] = 2;
        a[5] = 3;
        a[6] = 4;
        a[7] = 6;
        a[8] = 7;
        a[9] = 8;
        a[10] = -4;

        test(a, n, i+1);
    } 
//    printf("%d\n", SeekMinK(a, 0, n, 4));
//    output(a, n);

    printf("%d\n", SeekMidValue(a, 0, n-1));
    a[0] = 9;a[1] = 10;a[2] = 7;a[3] = 1;a[4] = 2;a[5] = 3;a[6] = 4;a[7] = 6;a[8] = 7;a[9] = 8;a[10] = -4;
    printf("%d\n", SeekMidValue(a, 0, n-2));
    //output(a, n);

    return 0;
}
