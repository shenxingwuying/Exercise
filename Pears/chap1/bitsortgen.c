/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

/* bitsortgen.c -- gen $1 distinct integers from U[0,$2) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 2000000
int x[MAXN];

int randint(int a, int b)
{
    return a + (unsigned int)(RAND_MAX * rand() + rand()) % (b + 1 - a);
//    return (a+(RAND_MAX * rand() + rand())) % b;    
//    return a + (RAND_MAX * rand() + rand()) % (b + 1 - a);
}

int main(int argc, char *argv[])
{	
    int i, k, n, t, p;
	srand((unsigned int) time(NULL));
    if (argc < 2)
    {
        printf("paramter is not enough\n");
        return 1;
    }
    printf("%d\n", RAND_MAX);
	k = atoi(argv[1]);
	n = atoi(argv[2]);
	for (i = 0; i < n; i++)
		x[i] = i;
	for (i = 0; i < n; i++) 
    {
		p = randint(i, n-1);
		t = x[p]; x[p] = x[i]; x[i] = t;
    }
    for (i = 0; i < k; i++)
    {
		printf("%d\n", x[i]);
	}
	return 0;
}

/**  求 小于n，且没有重复的k个整数
 *   读者注：by dyq
 *   思路：打散前n个数的位置，然后输出前n个数
 *  扩展： 求 n个数，随机的k个不重复的数
 */
