#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	char arr1[] = { "abcdef" };//abcdef\0
//	char arr2[] = { 'b','c','i' };
//	int len = strlen(arr);
//	//strlen���ص���\0ǰ����ַ����������ص����޷�������
//	int len2 = strlen(arr2);
//	//���ص������������Ϊarr2���治֪���Ǹ�λ����\0
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf_s(">  ");
//		//һ���Ǵ��ڣ���Ϊstrlen���ص����޷������Σ�
//		// 3-6=-3������-3ҲҪ�����޷������β��뵱������ԭ���Ϊһ���ܴ����
//	}
//	return 0;
//}
// ���Ȳ����޵��ַ�������
//strcpy
//strcat
//strcmp
// 
//�������޵��ַ�������
//strncpy
//strncat
//strncpy(arr1, arr2,5)�����������Ǹ��Ƶ��ֽ���

char* my_strcpy(char* arr2,const char* arr1)
{
	assert(arr1&& arr2);
	char* ret = arr2;
	while (*arr2++ = *arr1++)
		;
	return ret;
}

//�ַ���׷��
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest!='\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while ((*str1 == *str2) && *str1)
	{
		*str1++;
		*str2++;
	}
	return (*str1 - *str2);
}


char* my_strstr(char* str1, char* str2)
{
	assert(*str1 && *str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' &&*s2!='\0' &&  *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void*  my_memove(void* dest,const void* src,size_t num)
{
	assert(dest &&src);
	void* ret=dest;
	if(dest<src)
	{
		while(num--)
		{
			*(char*)dest=*(char*)src;
			dest=(char*)dest+1;
			src=(char*)src+1;
		}
		//前到后
	}
	else
	{
     while(num--)
	  {
		*((char*)dest+num)=*((char*)src+num);
	  }
	}
	return ret;
}

//strtok
// �и��ַ���
//int main()
//{
//	char arr1[20] = "zhangsan";
//	char arr2[] = "zhangsanfeng";
//	int ret = strcmp(arr1, arr2);
//	if (ret < 0)
//		printf_s("<\n");
//	else if (ret == 0)
//		printf_s("==\n");
//	else
//		printf_s(">\n");
//	return 0;
//}
//const char* strstr(const char* str1,const char* str2)
//��str1�������ִ�str2�������ִ��ڴ��������Ԫ�ص�ַ
int main()
{
	//const char* sep= "@";
	//char email[] = "zhangpengdwei@bitjfjf";
	////char email[] = "zhangpengdwei\0bitjfjf";
  //strtok(email, sep);�ѵڶ���������ֵ��Ϊ\0���������ֶ���ʼλ��
	//char cp[30] = { 0 };
	//char* ret = NULL;
	//for (ret = strtok(cp, sep); ret != NULL; ret = strtok(NULL, sep))
	//{
	//	printf_s("%s\n", ret);
	//}
	//return 0;


}

