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
	char mine[ROWS][COLS] = {0};//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = {0};//����Ų�����׵���Ϣ
	//��ʼ����������
	//mine������û�в����׵�ʱ��Ϊ0
	IniteBoard(mine,ROWS,COLS,'0');
    IniteBoard(show,ROWS,COLS,'*');
	//������
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);//չʾ���û�����
	//�Ų���
	FoundMine(mine,show, ROW, COL);//ʵ����λ��
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf_s("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				printf_s("ɨ��\n");
				break;
			case 0:
				printf_s("�˳���Ϸ\n");
				break;
			default:
				printf_s("ѡ�����\n");
				break;
		}
	} while (input);
	return 0;
}