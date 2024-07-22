#include<stdio.h>
#include<stdlib.h>
int cmp_int(const void* e1, const  void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++)
	{
		printf_s("%d  ", arr[i]);
	}
	return 0;
}