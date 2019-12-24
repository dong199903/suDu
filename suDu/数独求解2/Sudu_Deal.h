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
#pragma once
class Sudu_Deal {
public:
	int data[10][10];
	int biaoji[10][10];
public:
	Sudu_Deal();
	void deal();
	int find(int x,int y);
	~Sudu_Deal();
};
