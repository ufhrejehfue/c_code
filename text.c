#include"game.h"
void menu()
{
	printf_s("*****************************\n");
	printf_s("*****       1.play      *****\n");
	printf_s("*****       0.exit      *****\n");
	printf_s("*****************************\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息
	//初始化数组内容
	//mine数组在没有布置雷的时候为0
	IniteBoard(mine,ROWS,COLS,'0');
    IniteBoard(show,ROWS,COLS,'*');
	//设置雷
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);//展示给用户看的
	//排查雷
	FoundMine(mine,show, ROW, COL);//实际雷位置
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf_s("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				printf_s("扫雷\n");
				break;
			case 0:
				printf_s("退出游戏\n");
				break;
			default:
				printf_s("选择错误\n");
				break;
		}
	} while (input);
	return 0;
}