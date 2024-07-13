#include "game.h.cpp"
void menu()
{
	printf_s("**************************\n");
	printf_s("*****1.play    0.exit*****\n");
	printf_s("**************************\n");
}
void game()
{
	char ret=0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//判断输赢
		ret= IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf_s("\n玩家赢\n");
	}
	else if (ret == '#')
	{

		printf_s("\n电脑赢\n");
	}
	else
	{
		printf_s("\n平局\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	unsigned intsleep(unsigned int seconds);
	srand(time(NULL));
	int input = 0;
	do
	{
		menu();
		printf_s("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf_s("退出游戏\n");
			break;
		default:
			printf_s("选择错误：");
			break;
		}
	} while (input);
return 0;
}