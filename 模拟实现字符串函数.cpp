#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	char arr1[] = { "abcdef" };//abcdef\0
//	char arr2[] = { 'b','c','i' };
//	int len = strlen(arr);
//	//strlen返回的是\0前面的字符个数，返回的是无符号整形
//	int len2 = strlen(arr2);
//	//返回的是随机数，因为arr2里面不知道那个位置有\0
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf_s(">  ");
//		//一定是大于，因为strlen返回的是无符号整形，
//		// 3-6=-3，但是-3也要当成无符号整形补码当成正数原码成为一个很大的数
//	}
//	return 0;
//}
// 长度不受限的字符串函数
//strcpy
//strcat
//strcmp
// 
//长度受限的字符串函数
//strncpy
//strncat
//strncpy(arr1, arr2,5)第三个参数是复制的字节数

char* my_strcpy(char* arr2,const char* arr1)
{
	assert(arr1&& arr2);
	char* ret = arr2;
	while (*arr2++ = *arr1++)
		;
	return ret;
}

//字符串追加
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

//strtok
// 切割字符串
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
//在str1里面找字串str2，返回字串在串里面的首元素地址
int main()
{
	//const char* sep= "@";
	//char email[] = "zhangpengdwei@bitjfjf";
	////char email[] = "zhangpengdwei\0bitjfjf";
  //strtok(email, sep);把第二个参数的值改为\0，并返回字段起始位置
	//char cp[30] = { 0 };
	//char* ret = NULL;
	//for (ret = strtok(cp, sep); ret != NULL; ret = strtok(NULL, sep))
	//{
	//	printf_s("%s\n", ret);
	//}
	//return 0;


}

