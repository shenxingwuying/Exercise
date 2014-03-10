/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

/* bitsort.c -- bitmap sort from Column 1
 *   Sort distinct integers in the range [0..N-1]
 */

#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N/BITSPERWORD];

void set(int i) 
{ 
    a[i>>SHIFT] |=  (1<<(i & MASK)); 
}
void clr(int i) 
{ 
    a[i>>SHIFT] &= ~(1<<(i & MASK)); 
}
int test(int i)
{ 
    return a[i>>SHIFT] & (1<<(i & MASK)); 
}

int main()
{	
    printf("test bit operation\n");
    int a = 1, b = 66;
    printf("%d\t%d\t%d\t%d\n", a>>SHIFT, a, b<<SHIFT, b);
    int i;
	for (i = 0; i < N; i++)
		clr(i);
    printf("clr is over, input your numbers, end by CTRL+D\n");
/*	Replace above 2 lines with below 3 for word-parallel init
	int top = 1 + N/BITSPERWORD;
	for (i = 0; i < top; i++)
		a[i] = 0;
 */
	while (scanf("%d", &i) != EOF)
		set(i);
	for (i = 0; i < N; i++)
		if (test(i))
			printf("%d\n", i);
	return 0;
}

/* "读者注"By DuYuqi
 * 位操作：i>>SHIFT, 把i向右移动SHIFT位 
 * a[0], 为一个32位整形，代表了 0-31
 * a[1], 代表了 32-63, 以此类推。
 * i & MASK = i % 32。求余数的间接表示法。
 *
 * 此处将位运算用到极致，需要领会
 *
 * 位图数据结构，描述了一个有限定义域内的稠密集合。
 * 理论和文献中充斥着时空折中：即通过时间换空间，通过空间换时间。
 * 但是，当原始涉及远非最佳方案时，有可能达到时空双赢。
 * */
