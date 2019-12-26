/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include "Sudu_Deal.h";
#include <iostream>
using namespace std;
Sudu_Deal::Sudu_Deal()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->biaoji[i][j] = 0;
		}
	}
}
void Sudu_Deal::deal()
{
	find(1, 1);
	this->data[0][0] = 3;
	int flag = 0, countcolumn[10] = { 0 };
	for (int i = 1; i <= 9; i++)
	{
		int counts[10] = { 0 };
		for (int j = 1; j <= 9; j++)
		{
			if (!this->data[i][j])
			{
				flag = 1;
				break;
			}
			else
			{
				if (j == 1)
					countcolumn[this->data[i][j]]++;
				counts[this->data[i][j]]++;
				if (counts[this->data[i][j]] > 1 || countcolumn[this->data[i][j]] > 1)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)
		{
			//error
			break;
		}
	}
	if (!flag)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				putchar(this->data[i][j]);
				//printf("%d", Tdarray[i][j]);
				if (j < 9)
					putchar(' ');
			}
			if (i < 9)
				putchar('\n');
		}
	}
}
int Sudu_Deal::find(int x, int y)
{
	if (x > 9 || y > 9) return 1;
	if (biaoji[x][y])
	{
		if (y < 9)
		{
			if (find(x, y + 1))
				return 1;
		}
		else
		{
			if (x < 9)
			{
				if (find(x + 1, 1))
					return 1;
			}
			else
				return 1;
		}
	}
	else
	{
		for (int n1 = 1; n1 <= 9; n1++)
		{
			int temp = 1;
			for (int i = 1; i <= 9; i++)//看列有没有
			{
				if (this->data[i][y] == n1)
				{
					temp = 0;
					break;
				}
			}
			if (temp)//看行有没有
			{
				for (int j = 1; j <= 9; j++)
				{
					if (this->data[x][j] == n1)
					{
						temp = 0;
						break;
					}
				}
			}
			if (temp)//行和列都没有的话看小矩阵有没有
			{
				int rawtop, columntop;
				if (x % 3 == 0)
					rawtop = x;
				else
					rawtop = (x / 3) * 3 + 3;
				if (y % 3 == 0)
					columntop = y;
				else
					columntop = (y / 3) * 3 + 3;
				for (int i = rawtop - 2; i <= rawtop; i++)
				{
					for (int j = columntop - 2; j <= columntop; j++)
					{
						if (this->data[i][j] == n1)
						{
							temp = 0;
							break;
						}
					}
					if (!temp)
						break;
				}
			}
			if (temp)//判断过后看1-9放哪一个
			{
				this->data[x][y] = n1;
				if (y < 9)
				{
					if (find(x, y + 1))
						return 1;
				}
				else
				{
					if (x < 9)
					{
						if (find(x + 1, 1))
							return 1;
					}
					else
						return 1;
				}
				this->data[x][y] = 0;
			}
		}
	}
	return 0;
}
Sudu_Deal::~Sudu_Deal()
{
	cout << " ";
}