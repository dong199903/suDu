/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-12-22
 >
 > 1）数独main函数
 > 2）
 > 3）
 ************************************************************************/
#include "Sudu_Construct.h"
#include "Sudu_Deal.h"
#include<cstring>
#include <iostream>
using namespace std;
void main(int argc, char* argv[])
{
	Sudu_Construct * suDu;//数独生成指针
	Sudu_Deal * suDel;
	FILE * stream;
	if (strcmp(argv[1], "-c") == 0)//生成数独
	{
		freopen_s(&stream, "sudoku.txt", "w", stdout);
		int num = 0, fla = 0;
		for (int i = 0; i < strlen(argv[2]); i++)
		{
			if (argv[2][i]<'0' || argv[2][i]>'9')
			{
				printf("输入错误\n");
				fla = 1;
				break;
			}
			num = num * 10 + (argv[2][i] - '0');
		}
		if (fla);
		else
		{
			suDu = new Sudu_Construct(num);
			suDu->getSudu();
		}	
	}
	else if (strcmp(argv[1], "-s") == 0)//解数独
	{
		suDel = new Sudu_Deal();
		freopen_s(&stream, argv[2], "r", stdin);
		freopen_s(&stream, argv[2], "w", stdout);
		int final = 0;
		while (~scanf_s("%d", &suDel->data[1][1]))
		{
			if (final)
				printf("\n\n");
			memset(suDel->biaoji, 0, sizeof(suDel->biaoji));
			if (suDel->data[1][1] > 0)
				suDel->biaoji[1][1] = 1;
			for (int i = 1; i <= 9; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					if (i == 1 && j == 1)
						continue;
					scanf_s("%d", &suDel->data[i][j]);
					if (suDel->data[i][j] > 0)
						suDel->biaoji[i][j] = 1;
					if (suDel->data[i][j] == 7)
					{
						cout << i << " " << j << endl;
					}
				}
			}
			suDel->deal();
			final = 1;//回溯
		}
	}
	else {
		cout << "error";
	}
	system("pause");
}