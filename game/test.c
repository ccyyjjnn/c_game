/*
控制台排雷
设置俩个数组  mine（用来保存雷的信息）   //   11*11
			  show(用来显示雷的信息)     //    9*9



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
	//雷的信息存储
	//1.用来保存布置好的雷信息
	char mine[ROWS][COLS] = {0};   //11*11
	//2.用来排查好的雷的信息
	char show[ROWS][COLS] = {0};

	//初始化mine show
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);

	//扫雷
	FindMine(mine,show,ROW,COL);

}



void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{

		menu();
		printf("请选择:>");
		scanf_s("%d",&input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (input);

}

int main()
{
	test();
	return 0;

}