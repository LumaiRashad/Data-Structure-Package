#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

void InsertionSort( int arr[], int size)
{
	int j;
	for(int i=1; i<size; i++)
	{
		int temp=arr[i];
		for( j=i; j>0 && temp<arr[j-1]; j--)
			arr[j]=arr[j-1];
		arr[j]=temp;
	}

}

void SelectionSort( int arr[], int size)
{
	for(int i=0; i<size; i++)
   {
       int minindex=i;
       for(int j=i; j<size; j++)
       {
           if(arr[j]<arr[minindex])
               minindex=j;
       }
       int temp=arr[i];
       arr[i]=arr[minindex];
       arr[minindex]=temp;
   }
}

void BubbleSort( int arr[], int size)
{
	for(int i=0; i<size-1; i++)
   {
       for(int j=i+1; j<size; j++)
       {
           if(arr[j]<arr[i])
           {
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
       }
   }
}

void CombSort( int arr[], int size)
{
	int gab=size, j, k;
	bool again=true;
	while( (gab=int(gab/1.3)) >1)
		for(j= size-1; j>=gab; j++)
		{
			k=j-gab;
			if(arr[j] < arr[k])
				swap(arr[j], arr[k]);
		}

		for(int i=0; i<size-1 && again; i++)
			for(j=size-1; again=false && j>i; j--)
			{
				if(arr[j]<arr[j-1])
				{
					swap(arr[j], arr[j-1]);
					again=true;
				}
			}
}

void QuickSort( int arr[], int first, int last)
{
	int lower=first+1, upper=last;
	swap (arr[first], arr[first+last]/2);
	int bound=arr[first];
	while(lower<=upper)
	{
		while(bound>arr[lower])
			lower++;
		while(bound<arr[upper])
			upper--;
		if(lower<upper)
			swap(arr[lower++], arr[upper--]);
		else
			lower++;
	}
	swap (arr[upper], arr[first]);
	if(first<upper-1)
		QuickSort(arr, first, upper-1);
	if(upper+1<last)
		QuickSort(arr, upper+1, last);
}
void QuickSort(int arr[], int size)
{
	int i, max=0;
	if(size<2)
		return;
	for(i=1, max=0; i<size; i++)
		if(arr[max]<arr[i])
			max=i;
	swap(arr[size-1], arr[max]);
	QuickSort(arr, 0, size-2);
}

void CountSort(long arr[], long size)
{
	long i, range=arr[0];
	long *tmp=new long[size];
	for(i=0; i<size; i++)
		if(range<arr[i])
			range=arr[i];
	long *count= new long [range+1];
	for( i=0; i<=range; i++)
		count[i]=0;
	for(i=0; i<size; i++)
		count[arr[i]]++;
	for(i=1; i<=range; i++)
		count[i]=count[i-1]+count[i];
	for(i=size-1; i>=0; i--)
	{
		tmp[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	for(i=0; i<size; i++)
		arr[i]=tmp[i];
}


