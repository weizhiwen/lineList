#pragma once
#include <iostream>
#define ELEMTYPE int

//定义带头节点的单链表结构体
typedef struct NodeSList
{
	ELEMTYPE data;
	struct NodeSList *next;
}NodeSList, *pList;

//链式结构线性表初始化头节点
bool initNode(NodeSList **L)
{
	*L = (NodeSList *)malloc(sizeof(NodeSList));
	if (!*L)
	{
		printf("单链表头节点初始化失败\a\n");
		return 0;
	}
	(*L)->data = 0;
	(*L)->next = NULL;
	return 1;
}

//链式结构线性表任意位置插入元素
bool insertNode(NodeSList *L, int i, ELEMTYPE elem)
{
	NodeSList *p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
	{
		printf("不能插入%d位置，插入失败！\a\n", i);
		return 0;
	}
	pList s = (pList)malloc(sizeof(NodeSList));
	s->data = elem;
	s->next = p->next;
	p->next = s;
	return 1;
}

//链式结构线性表任意位置删除元素，并返回删除元素的值
bool deleteNode(NodeSList *L, int i, ELEMTYPE *elem)
{
	NodeSList *p = L;
	int	j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
	{
		printf("没有%d位置的元素，删除失败！\a\n", i);
		return 0;
	}
	pList q;
	q = p->next;
	p->next = q->next;
	*elem = q->data;
	free(q);
	return 1;
}

//链式结构线性表给位置查找元素，并将值返回给elem
bool selectNode(NodeSList *L, int i, ELEMTYPE *elem)
{
	NodeSList *p = L->next; //跳过第一个空节点
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("没有%d位置的元素，查找失败！\a\n", i);
		return 0;
	}
	*elem = p->data;
	return 1;
}

//链式结构线性表给位置修改元素，elem为想要修改的值
bool replaceNode(NodeSList *L, int i, ELEMTYPE elem)
{
	NodeSList *p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("没有%d位置的元素，修改失败！\a\n", i);
		return 0;
	}
	p->data = elem;
	return 1;
}

//打印链式结构线性表内容
void printNodeList(NodeSList *L)
{
	pList p = L->next;
	int i = 1;
	while (p)
	{
		printf("%d：%d\n",i, p->data);
		p = p->next;
		i++;
	}
}