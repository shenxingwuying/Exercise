/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

/* sortints.cpp -- Sort input set of integers using STL set */

#include <iostream>
#include <set>
using namespace std;

int main()
{	
    set<int> S;
	int i;
	set<int>::iterator j;
	while (cin >> i)
		S.insert(i);
 	for (j = S.begin(); j != S.end(); ++j)
		cout << *j << "\n";
	return 0;
}


/*  读者注
 *  利用 C++的 容器类 <set>的有序性，进行排序。 
 *  十分现成的方法
 *
 */
