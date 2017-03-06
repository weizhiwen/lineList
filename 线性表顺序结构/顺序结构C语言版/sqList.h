#pragma once
#include <iostream>
#include <stdlib.h>
#define LIST_INIT_SIZE 5 //表的初始长度值
#define LIST_INCREATE 10 //表的每次拓展增加长度值
#define ELEMTYPE int //表的元素类型

//定义顺序结构线性表结构体
typedef struct 
{
	ELEMTYPE *elem; //线性表元素的地址
	int listLengh; //表的元素个数
	int listSize; //表的长度容量
}sqlList;

//初始化顺序结构线性表
bool initList(sqlList *L)
{
	L->elem = (ELEMTYPE *)malloc(LIST_INIT_SIZE * sizeof(ELEMTYPE)); //申请初始的顺序表内存空间
	if (!(L->elem)) 
	{
		printf("存储空间分配失败！\a\n");
		return 0;
	}
	L->listLengh = 0; //空表元素个数为0
	L->listSize = LIST_INIT_SIZE; //空表的长度为为表的初始值
	return 1;
}

//顺序结构线性表任意位置插入元素
bool insertList(sqlList *L, int i, ELEMTYPE elem)
{
	if (i < 1 || i > L->listLengh+1)
	{
		printf("不能插入%d位置，插入失败！\a\n", i);
		return 0;
	}
	if (L->listLengh >= L->listSize)
	{
		ELEMTYPE *newL;
		newL = (ELEMTYPE *)realloc(L->elem, (L->listSize + LIST_INCREATE) * sizeof(ELEMTYPE));
		if (!newL) 
		{
			printf("储存空间不够！\a\n");
			exit(0);
		}
	}
	ELEMTYPE *q = &(L->elem[i - 1]); //q指针来获取即将插入元素位置的前一个位置地址
	for (ELEMTYPE *p = &(L->elem[L->listLengh - 1]); p >= q; --p)
	//for(ELEMTYPE *p = &(L->elem[L->listLengh - 1]); p > q; p--)
		*(p + 1) = *p; //元素右移
	*q = elem;
	L->listLengh += 1;
	return 1;
}

//顺序结构线性表任意位置删除元素
bool deleteList(sqlList *L, int i, ELEMTYPE *e)
{
	if (i < 1 || i > L->listLengh)
	{
		printf("没有%d位置的元素，删除失败", i);
		return 0;
	}
	ELEMTYPE *p = &(L->elem[i - 1]);
	*e = *p; //取出被删除的元素的值
	ELEMTYPE *q = &(L->elem[L->listLengh - 1]); //获取表尾元素位置
	//ELEMTYPE *q = L->elem + (L->listLengh - 1); 
	for (++p; p <= q; ++p)
		*(p - 1) = *p; //元素左移
	L->listLengh -= 1;
	return 1;
}

//顺序结构线性表给位置查找元素，并将值返回给e
bool selectiList(sqlList *L, int i, ELEMTYPE *e)
{
	if (i < 1 || i > L->listLengh)
	{
		printf("没有%d位置的元素，查找失败！\a\n", i);
		return 0;
	}
	ELEMTYPE *p = &(L->elem[i - 1]);
	*e = *p;
	return 1;
}

//顺序结构线性表给位置修改元素，e为想要修改的值
bool replaceiList(sqlList *L, int i, ELEMTYPE e)
{
	if (i < 1 || i > L->listLengh)
	{
		printf("没有%d位置的元素，修改失败！\a\n", i);
		return 0;
	}
	ELEMTYPE *p = &(L->elem[i - 1]);
	*p = e;
	return 1;
}

//顺序结构线性表给元素查找位置，并将位置返回给i
bool selecteList(sqlList *L, ELEMTYPE e, int *i)
{
	ELEMTYPE *p = L->elem;
	ELEMTYPE *q = &(L->elem[L->listLengh - 1]);
	int j;
	for (j = 1; p <= q; j++)
	{
		if (*p == e)
		{
			*i = j;
			break;
		}
		p++;
	}	
	if (j > L->listLengh - 1)
	{
		printf("没有找到元素%d，查找失败！\a\n", e);
	}
	return 1;
}

//顺序结构线性表给元素值替换为另一个元素的值
bool replaceeList(sqlList *L, ELEMTYPE origin, ELEMTYPE result)
{
	ELEMTYPE *p = L->elem;
	ELEMTYPE *q = &(L->elem[L->listLengh - 1]);
	int j;
	for (j = 0; p <= q; j++)
	{
		if (*p == origin)
		{
			*p = result;
			break;
		}
		p++;
	}
	if (j > L->listLengh - 1)
	{
		printf("没有找到元素%d，修改失败！\a\n", origin);
	}
	return 1;
}

//打印顺序结构线性表中的元素值
void printList(sqlList *L)
{
	ELEMTYPE *p = L->elem;
	for (int i = 0; i < L->listLengh; i++)
	{
		printf("%d:%d\n", i + 1, *p);
		p++;
	}
}

