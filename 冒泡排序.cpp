#include<stdio.h>
#include<stdlib.h>
int cmp_int(const void* e1, const  void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}


void bubble_sort(void*base,int sz,int width,int(*cmp)(const void*e1,const void*e2))
{
   for(int i=0;i<sz-1;i++)
   {
    int flage=1;
      for(int j=0;j<sz-1-i;j++)
		{
			if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
				flage=0;
			}
		}
		if(flage==1)
		{
			break;
		}
   }
}

void Swap(char*buf1,char*buf2,int width)
{
  for(int i=0;i<width;i++)
  {
	char tmp=*buf1;
   *buf1=*buf2;
	*buf2=tmp;
	buf1++;
	buf2++;
  }
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