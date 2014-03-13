/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

/* qsortints.c -- Sort input set of integers using qsort */

#include <stdio.h>
#include <stdlib.h>

int intcomp(const void *x, const void *y)
{   
    return *(const int *)x - *(const int *)y;
}

int a[1000000];

int main()
{   
    int i, n=0;
    while (scanf("%d", &a[n]) != EOF)
        n++;
    qsort(a, n, sizeof(int), intcomp);
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}


/*** 
 * 读者注：By duyuqi
 * 这是个单纯地 使用C语言库的快速排序
 *  fix intcomp函数的 Warning
 *
 *
 */
