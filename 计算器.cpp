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
void cal(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf_s("请输入两个操作数： \n");
	scanf_s("%d %d", &x, &y);
	ret = pf(x, y);
	printf_s("结果为：%d \n", ret);
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

	int input = 0;
	do 
	{
		menu();
		printf_s("请选择： ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			cal(Add);
			break;
		case 2:
			cal(Sub);
			break;
		case 3:
			cal(Mul);
			break;
		case 4:
			cal(Div);
			break;
		case 0:
			printf_s("退出计算器\n");
			break;
		default:
			printf_s("选择错误\n");
			break;
		}
	} while (input);
return 0;
}
