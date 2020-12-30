#include "game.h"


//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (  i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i <=col; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for ( i =1 ; i <=row; i++)
	{
		printf("%d ",i);
		for ( j = 1; j <=col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}

}

//������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;
		if (board[x][y]=='0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

//ɨ�ס���������������Χ�м�����
int get_mine_count(char mine[COLS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';


}

//ɨ��
void FindMine(char mine[][COLS], char show[][COLS], int row, int col)
{
	int x = 0, y = 0,win = 0;
	//9*9-10;
	while (win<row*col-EASY_COUNT)
	{
		printf("�������Ų��׵�����:>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			if (mine[x][y]=='1')
			{
				printf("���ź��㱻ը��\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else
			{
				//�����ף�����xy������Χ�м�����
				int count=get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show,row,col);
				win++;
			}
		}
		else
		{
			printf("����������������������\n");
		}
	}


	if (win=row*col-EASY_COUNT)
	{
		printf("���׳ɹ�\n");
		DisplayBoard(mine,row,col);
	}
}

