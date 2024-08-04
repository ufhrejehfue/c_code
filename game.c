#include "game.h"
void IniteBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf_s("-----------扫雷游戏----------\n");
    for(j = 0; j <= col; j++)
	{
		printf_s("%d ", j);
	}
	printf_s("\n");
	for (i = 1; i <=row; i++)
	{
		printf_s("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf_s("%c ",board[i][j]);
		}
		printf_s("\n");
	}
	printf_s("-----------扫雷游戏----------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row+1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS],int x,int y)
{
	return(board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1]
		+ board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]-8*'0');
}

void FoundMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//排查非雷次数
	while (win < row * col - EASY_COUNT)
	{
		printf_s("请输入排查坐标：");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf_s("该坐标已经被排查过了，不能重复排查\n");
			}
			else
			{
				if (mine[x][y] == '1')//是雷
				{
					printf_s("很遗憾，你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
				}
				else//不是雷，统计旁边雷个数
				{
					win++;
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//转换成数字字符
					DisplayBoard(show, ROW, COL);
				}
			}
		}
	}
	if(win == row * col - EASY_COUNT)
	{
		printf_s("恭喜你排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}
 