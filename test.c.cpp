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
	//��ʼ������
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//�ж���Ӯ
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
		printf_s("\n���Ӯ\n");
	}
	else if (ret == '#')
	{

		printf_s("\n����Ӯ\n");
	}
	else
	{
		printf_s("\nƽ��\n");
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
		printf_s("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf_s("�˳���Ϸ\n");
			break;
		default:
			printf_s("ѡ�����");
			break;
		}
	} while (input);
return 0;
}