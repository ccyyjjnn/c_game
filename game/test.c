/*
����̨����
������������  mine�����������׵���Ϣ��   //   11*11
			  show(������ʾ�׵���Ϣ)     //    9*9



*/
#include "game.h"

void menu()
{
	printf("--------------------\n");
	printf("------1.play--------\n");
	printf("------0.exit--------\n");
	printf("--------------------\n");


}


void game()
{
	//�׵���Ϣ�洢
	//1.�������沼�úõ�����Ϣ
	char mine[ROWS][COLS] = {0};   //11*11
	//2.�����Ų�õ��׵���Ϣ
	char show[ROWS][COLS] = {0};

	//��ʼ��mine show
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	
	//��ӡ����
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);

	//ɨ��
	FindMine(mine,show,ROW,COL);

}



void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{

		menu();
		printf("��ѡ��:>");
		scanf_s("%d",&input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ���������ѡ��");
			break;
		}
	} while (input);

}

int main()
{
	test();
	return 0;

}