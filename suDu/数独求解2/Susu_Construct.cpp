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
#include <iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;
//构造函数
Sudu_Construct::Sudu_Construct(int num)
{
	this->count = num;
}
//析构函数
Sudu_Construct::~Sudu_Construct()
{
	cout << "";
}
//构造数独
void  Sudu_Construct::getSudu()
{
	int count = 0,temp;
	int port[10] = { 0,0,6,5,4,3,2,1,7,8 };
	char str[10] = { '9','3','1','2','7','4','5','6','8','9' };
	if (count < this->count)
	{
		for (int a = 0; a < 6; a++)
		{
			if (count == this->count)
				break;
			if (a)
				next_permutation(port + 4, port + 6);
			for (int b = 0; b < 6; b++)
			{
				if (b)
					next_permutation(port + 7, port + 9);
				int t = 0;
				char kong = ' ';
				do {
					if (t)
						next_permutation(str + 2, str + 9);
					for (int i = 1; i <= 9; i++)
					{
						for (int j = 1; j <= 9; j++)
						{

							if (j - port[i] >= 0)
								temp = j - port[i];
							else
								temp = j - port[i] + 9;
							putchar(str[temp % 9]);
							if (j < 9)
								putchar(kong);
						}
						putchar('\n');
					}
					count++;
					t++;
					if (count == this->count)
						break;
					else
						putchar('\n');
				} while (t<40320);
				if (count == this->count)
					break;
			}
		}
	}
}
//返回用户传递参数
int Sudu_Construct::getCount()
{
	return this->count;
}