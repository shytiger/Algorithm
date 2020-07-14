/*
 * SortTestHelper.h
 *
 *  Created on: 2020年7月13日
 *      Author: cxz
 */

#ifndef SORTTESTHELPER_H_
#define SORTTESTHELPER_H_

#include<iostream>
#include<ctime>
#include<cassert>

using namespace std;

namespace SortTestHelper{
	int* generateRandomArray(int n,int RangeL, int RangeR){
		int *arr = new int[n];
		assert(RangeL<=RangeR);
		srand(time(NULL));
		for(int i=0; i<n ; i++)
		{
			arr[i] = rand()%(RangeR-RangeL+1)+RangeL;
		}
		return arr;

	}

	template<typename T>
	void printArray(T arr[],int n){
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	template<typename T>
	void swap(T& a,T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<typename T>
	void selectSort(T arr[],int n){
		assert(n>0);
		int minIndex;
		for(int i=0;i<n;i++){
			minIndex = i;
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]<arr[minIndex])
				{
					minIndex = j;//swap(arr[i],arr[j]);/
				}
			}
			swap(arr[i],arr[minIndex]);
		}
	}


	template<typename T>
	bool isSorted(T arr[],int n){
		for(int i=0;i<n-1;i++)
		{
			if(arr[i+1]<arr[i]) return false;
		}
		return true;
	}

	template<typename T>
	void testSort(string sortName, void(*sort)(T arr[],int),T arr[], int n){

		clock_t startTime = clock();
		sort(arr,n);
		clock_t endTime = clock();

		cout<<sortName<<": sorted: "<<isSorted(arr,n)<<" , time: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	}

	template<typename T>
	void insertionSort1(T arr[], int n){
		assert(n>0);
		for(int i=0;i<n-1;i++)
		{
			//int tmp = i+1;
			for(int j=i;j>=0&&arr[j+1]<arr[j];j--)
			{
					swap(arr[j],arr[j+1]);
			}
		}
	}

	template<typename T>
	void insertionSort(T arr[], int n){ //improve
		assert(n>0);
		for(int i=0;i<n-1;i++)
		{
			//int tmp = i+1;
			int tmp = arr[i+1];
			for(int j=i;j>=0;j--)
			{
				if(tmp<arr[j])
				{
					arr[j+1] = arr[j];
				}
				else
				{
					arr[j+1] = tmp;
					break;
				}
			}
		}
	}

	int* copyIntArray(int a[],int n){
		int*arr = new int[n];
		copy(a,a+n,arr);
		return arr;
	}

	int *generateNearlySortedArray(int n, int swapTimes){
		int *arr = new int[n];
		for(int i=0;i<n;i++){
			arr[i]=i;
		}
		srand(time(NULL));
		for(int i=0;i<swapTimes;i++)
		{
			int posX= rand()%n;
			int posY = rand()%n;
			swap(arr[posX],arr[posY]);
		}
		return arr;
	}

	template<typename T>
	void bubbleSort(T arr[],int n){

	}




	template<typename T>
	void insertSort(T arr[],int left,int right)
	{
		for(int i=left;i<right;i++)
		{
			int tmp = arr[i];
			for(int j=i;j>=left;j--)
			{
				if(tmp<arr[j])
				{
					arr[j+1]=arr[j];
				}
				else
				{
					arr[j+1] = tmp;
					break;
				}
			}
		}
	}


	template<typename T>
	void __mergeSort(T arr[],int startIndex,int endIndex){
		assert(endIndex>=startIndex);
		if(endIndex==startIndex) return;

		if(endIndex-startIndex<=15)  //improve
		{
			insertSort(arr,startIndex,endIndex);
			return;
		}

		int middle = int (endIndex+startIndex)/2;// 如果两个加数大于 int类型范围怎么办？？
		if(endIndex-startIndex+1>2)
		{
			__mergeSort(arr,startIndex,middle);
			__mergeSort(arr,middle+1,endIndex);
			//mergeSort(arr,startIndex,endIndex);
		}

		if(arr[middle]<=arr[middle+1]) return;  //improved much for Nearly ordered arrays!!!

		T *res = new T[endIndex-startIndex+1];
		//int middle = int (endIndex+startIndex)/2;
		int l = startIndex, r=middle+1;
		int i = 0;
		while(i<(endIndex-startIndex+1)&&l<=middle&&r<=endIndex)
		{
			if(arr[l]<=arr[r])
			{
				//cout<<arr[l]<<" ";
				res[i++] = arr[l++];
				//l++;
			}
			else
			{
				//cout<<arr[r]<<" ";
				res[i++] = arr[r++];
			}
		}
		while(i<(endIndex-startIndex+1))
		{
			while(r<=endIndex)
			{
				res[i++] = arr[r++];
			}
			while(l<=middle)
			{
				res[i++] = arr[l++];
			}
		}
		i=0;
		l=startIndex;
		while(l<=endIndex&&i<(endIndex-startIndex+1))
		{
			//cout<<res[i]<<" ";
			arr[l++] = res[i++];
		}
		delete[] res;
		//int middle = int (endIndex+startIndex)/2;
	}



	template<typename T>
	void __merge(T arr[], int left, int middle,int right)
	{
		if(left>=right) return;
		T* tmp = new T[right-left+1];
		for(int l=left;l<=right;l++)
		{
			tmp[l-left] = arr[l];
		}
		//int middle = (int)(left+right)/2;
		int l=left, r=middle+1;
		for(int k=left;k<=right;k++)
		{
			if(l>middle)
			{
				arr[k] = tmp[r-left];
				r++;
			}
			else if(r>right)
			{
				arr[k] = tmp[l-left];
				l++;
			}
			else if(tmp[l-left]>tmp[r-left])
			{
				arr[k] = tmp[r-left];
				r++;
			}
			else
			{
				arr[k] = tmp[l-left];
				l++;
			}
		}

	}

	template<typename T>
	void mergeSortBottomUp(T arr[],int n){
		for(int sz=1;sz<= n; sz +=sz)
		{
			for(int i=0; i+sz<n; i+=sz+sz)
			{
				__merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
			}
		}
	}


	template<typename T>
	void __mergeSort2(T arr[],int startIndex,int endIndex){
		assert(endIndex>=startIndex);
		if(endIndex==startIndex) return;

		if(endIndex-startIndex<=15)  //improve
		{
			insertSort(arr,startIndex,endIndex);
			return;
		}

		int middle = int (endIndex+startIndex)/2;// 如果两个加数大于 int类型范围怎么办？？
		if(endIndex-startIndex+1>2)
		{
			__mergeSort(arr,startIndex,middle);
			__mergeSort(arr,middle+1,endIndex);
			//mergeSort(arr,startIndex,endIndex);
		}

		if(arr[middle]<=arr[middle+1]) return;  //improved much for Nearly ordered arrays!!!
		__merge(arr,startIndex,(int)(endIndex+startIndex)/2,endIndex);

	}
	template<typename T>
	void mergeSort(T arr[],int n){
		__mergeSort2(arr,0,n-1);
	}
}


#endif /* SORTTESTHELPER_H_ */
