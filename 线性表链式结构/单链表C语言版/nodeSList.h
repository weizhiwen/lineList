#pragma once
#include <iostream>
#define ELEMTYPE int

//�����ͷ�ڵ�ĵ�����ṹ��
typedef struct NodeSList
{
	ELEMTYPE data;
	struct NodeSList *next;
}NodeSList, *pList;

//��ʽ�ṹ���Ա��ʼ��ͷ�ڵ�
bool initNode(NodeSList **L)
{
	*L = (NodeSList *)malloc(sizeof(NodeSList));
	if (!*L)
	{
		printf("������ͷ�ڵ��ʼ��ʧ��\a\n");
		return 0;
	}
	(*L)->data = 0;
	(*L)->next = NULL;
	return 1;
}

//��ʽ�ṹ���Ա�����λ�ò���Ԫ��
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
		printf("���ܲ���%dλ�ã�����ʧ�ܣ�\a\n", i);
		return 0;
	}
	pList s = (pList)malloc(sizeof(NodeSList));
	s->data = elem;
	s->next = p->next;
	p->next = s;
	return 1;
}

//��ʽ�ṹ���Ա�����λ��ɾ��Ԫ�أ�������ɾ��Ԫ�ص�ֵ
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
		printf("û��%dλ�õ�Ԫ�أ�ɾ��ʧ�ܣ�\a\n", i);
		return 0;
	}
	pList q;
	q = p->next;
	p->next = q->next;
	*elem = q->data;
	free(q);
	return 1;
}

//��ʽ�ṹ���Ա��λ�ò���Ԫ�أ�����ֵ���ظ�elem
bool selectNode(NodeSList *L, int i, ELEMTYPE *elem)
{
	NodeSList *p = L->next; //������һ���սڵ�
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("û��%dλ�õ�Ԫ�أ�����ʧ�ܣ�\a\n", i);
		return 0;
	}
	*elem = p->data;
	return 1;
}

//��ʽ�ṹ���Ա��λ���޸�Ԫ�أ�elemΪ��Ҫ�޸ĵ�ֵ
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
		printf("û��%dλ�õ�Ԫ�أ��޸�ʧ�ܣ�\a\n", i);
		return 0;
	}
	p->data = elem;
	return 1;
}

//��ӡ��ʽ�ṹ���Ա�����
void printNodeList(NodeSList *L)
{
	pList p = L->next;
	int i = 1;
	while (p)
	{
		printf("%d��%d\n",i, p->data);
		p = p->next;
		i++;
	}
}