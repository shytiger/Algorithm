//============================================================================
// Name        : Algorithm.cpp
// Author      : Yan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"SortTestHelper.h"
#include"Student.h"
using namespace std;
using namespace SortTestHelper;

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int n = 40;
	int* arr = SortTestHelper::generateRandomArray(n,0,n);
	//int* arr = SortTestHelper::generateNearlySortedArray(n,(int)n/100);

	//char* arr = generateRandomArray(n,1,n);
	//printArray(arr,n);

	//selectSort(arr,n);
	//cout<<"arr sorted:"<<isSorted(arr,n)<<endl;
	int *arr2 = copyIntArray(arr,n);
	int *arr3 = copyIntArray(arr,n);
	int *arr4 = copyIntArray(arr,n);
	int *arr5 = copyIntArray(arr,n);
	testSort("insertionSort1",insertionSort1,arr,n);
	//testSort("selectSort",selectSort,arr3,n);
	testSort("insertionSort improved",insertionSort,arr2,n);
	testSort("mergeSort",mergeSort,arr4,n);
	printArray(arr5,n);
	testSort("mergeSortBottomUp",mergeSortBottomUp,arr5,n);
	printArray(arr5,n);
	//testSort("mergeSort",mergeSort,arr,0,n);
//	printArray(arr4,n);
//	mergeSort(arr4,0,n-1);
//	cout<<"arr4 sorted "<<isSorted(arr4,n)<<endl;
//	printArray(arr4,n);

	//cout<<"arr sorted: ";
	//printArray(arr,n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

//	string c[4] = {"D","C","A","B"};
//	selectSort(c,4);
//	for(int i=0;i<4;i++)
//	{
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
//	//Student d[3] = {new Student("ÕÅÈý"£¬56),new Student("sdf",89),new Student("d",98)};
//	Student d[3] ={{"d",99},{"a",79},{"f",9}};
//	selectSort(d,3);
//
//	for(int i=0;i<3;i++)
//	{
//		cout<<d[i]<<endl;
//	}
	return 0;
}
