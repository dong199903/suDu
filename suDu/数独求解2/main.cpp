/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-12-22
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include "Sudu_Construct.h"
#include<cstring>
#include <iostream>
using namespace std;
void main(int argc, char* argv[])
{
	Sudu_Construct * suDu;//数独生成指针
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
			suDu = new Sudu_Construct(num);
	}
	system("pause");
}