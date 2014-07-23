 /*************************************************************************
    @File Name: sort.h
    @Author: duyuqi
    @Mail: duyuqi@baidu.com 
    @CreatedTime: 一  5/26 18:43:01 2014
 ************************************************************************/
#ifndef DU_SORT_H
#define DU_SORT_H

#include<iostream>
using namespace std;

template <class T>
int Partition(T a[],int left,int right);

template <class T>
void Quick(T a[],int left,int right);

template <class T>
int SeekMinK(T a[], int left, int right, int k);

template <class T>
int SeekMidValue(T a[], int left, int right);

#endif
