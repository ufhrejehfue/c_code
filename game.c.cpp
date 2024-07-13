#include "game.h.cpp"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < col; j++)
	{
		printf_s(" ---");
	}
	printf_s("\n");
	for (i = 0; i< row; i++)
	{
		for (j = 0; j < col; j++)//��ӡ���̵�һ��
		{
			printf_s("|");
			printf_s(" %c ", board[i][j]);
	    }
		printf_s("|");
		printf_s("\n");
		if (i < row - 1)//��ӡ�ָ��
		{
			for (j = 0; j < col; j++)
			{
				printf_s("|---");
			}
			printf_s("|");
			printf_s("\n"); 
		}
	}
	for (j = 0; j < col; j++)
	{
		printf_s(" ---");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf_s("������壺>\n"); 
	while (1)
	{
		printf_s("����������:>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
					break;
			}
			else
			{
				printf_s("���걻ռ�ã�����������λ��\n");
			}
		}
		else
		{
			printf_s("����Ƿ�������������\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf_s("��������:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		Sleep(100);
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{//��
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][1];
		}
	}
	//��
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�Խ���
if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
 {
	return board[1][1];
  }
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[1][1];
	}
	if (IsFull(board, row, col))
	{
		return 'q';
	}
	//��Ϸ����
	return 'c';
}