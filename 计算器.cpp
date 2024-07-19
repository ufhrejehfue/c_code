#include<stdio.h>
int Add(int x, int y)
{
	return (x+y);
}
int Sub(int x, int y)
{
	return (x - y);
}
int Mul(int x, int y)
{
	return(x * y);
}
int Div(int x, int y) 
{
	return (x / y);
} 

void menu()
{
	printf_s("***********************************\n");
	printf_s("*********    1.add   2.sub  ********\n");
	printf_s("************ 3.mul   4.div  *******\n");
	printf_s("*************0.exit********\n");
	printf_s("***********************************\n");
}

int main()
{
	int x = 0;
	int y = 0;
	int ret = 0;
    int (*pfArr[5]) (int,int)={0,Add,Sub,Mul,Div};
	int input = 0;
	printf_s("请选择： ");
	scanf_s("%d", &input);
	if(input==0)
	{
		printf_s("退出计算器  \n");
	}
	else if(input>=1&&input<=4)
	{
      printf_s("请输入两个操作数： \n");
	scanf_s("%d %d", &x, &y);
	ret = pfArr[input](x, y);
	printf_s("结果为：%d \n", ret);
	}
	else
	{
     printf_s("选择错误 \n");
	}
return 0;
}
