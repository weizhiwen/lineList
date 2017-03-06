#pragma once
#include <iostream>
#include <stdlib.h>
#define LIST_INIT_SIZE 5 //��ĳ�ʼ����ֵ
#define LIST_INCREATE 10 //���ÿ����չ���ӳ���ֵ
#define ELEMTYPE int //���Ԫ������

//����˳��ṹ���Ա�ṹ��
typedef struct 
{
	ELEMTYPE *elem; //���Ա�Ԫ�صĵ�ַ
	int listLengh; //���Ԫ�ظ���
	int listSize; //��ĳ�������
}sqlList;

//��ʼ��˳��ṹ���Ա�
bool initList(sqlList *L)
{
	L->elem = (ELEMTYPE *)malloc(LIST_INIT_SIZE * sizeof(ELEMTYPE)); //�����ʼ��˳����ڴ�ռ�
	if (!(L->elem)) 
	{
		printf("�洢�ռ����ʧ�ܣ�\a\n");
		return 0;
	}
	L->listLengh = 0; //�ձ�Ԫ�ظ���Ϊ0
	L->listSize = LIST_INIT_SIZE; //�ձ�ĳ���ΪΪ��ĳ�ʼֵ
	return 1;
}

//˳��ṹ���Ա�����λ�ò���Ԫ��
bool insertList(sqlList *L, int i, ELEMTYPE elem)
{
	if (i < 1 || i > L->listLengh+1)
	{
		printf("���ܲ���%dλ�ã�����ʧ�ܣ�\a\n", i);
		return 0;
	}
	if (L->listLengh >= L->listSize)
	{
		ELEMTYPE *newL;
		newL = (ELEMTYPE *)realloc(L->elem, (L->listSize + LIST_INCREATE) * sizeof(ELEMTYPE));
		if (!newL) 
		{
			printf("����ռ䲻����\a\n");
			exit(0);
		}
	}
	ELEMTYPE *q = &(L->elem[i - 1]); //qָ������ȡ��������Ԫ��λ�õ�ǰһ��λ�õ�ַ
	for (ELEMTYPE *p = &(L->elem[L->listLengh - 1]); p >= q; --p)
	//for(ELEMTYPE *p = &(L->elem[L->listLengh - 1]); p > q; p--)
		*(p + 1) = *p; //Ԫ������
	*q = elem;
	L->listLengh += 1;
	return 1;
}

//˳��ṹ���Ա�����λ��ɾ��Ԫ��
bool deleteList(sqlList *L, int i, ELEMTYPE *e)
{
	if (i < 1 || i > L->listLengh)
	{
		printf("û��%dλ�õ�Ԫ�أ�ɾ��ʧ��", i);
		return 0;
	}
	ELEMTYPE *p = &(L->elem[i - 1]);
	*e = *p; //ȡ����ɾ����Ԫ�ص�ֵ
	ELEMTYPE *q = &(L->elem[L->listLengh - 1]); //��ȡ��βԪ��λ��
	//ELEMTYPE *q = L->elem + (L->listLengh - 1); 
	for (++p; p <= q; ++p)
		*(p - 1) = *p; //Ԫ������
	L->listLengh -= 1;
	return 1;
}

//˳��ṹ���Ա��λ�ò���Ԫ�أ�����ֵ���ظ�e
bool selectiList(sqlList *L, int i, ELEMTYPE *e)
{
	if (i < 1 || i > L->listLengh)
	{
		printf("û��%dλ�õ�Ԫ�أ�����ʧ�ܣ�\a\n", i);
		return 0;
	}
	ELEMTYPE *p = &(L->elem[i - 1]);
	*e = *p;
	return 1;
}

//˳��ṹ���Ա��λ���޸�Ԫ�أ�eΪ��Ҫ�޸ĵ�ֵ
bool replaceiList(sqlList *L, int i, ELEMTYPE e)
{
	if (i < 1 || i > L->listLengh)
	{
		printf("û��%dλ�õ�Ԫ�أ��޸�ʧ�ܣ�\a\n", i);
		return 0;
	}
	ELEMTYPE *p = &(L->elem[i - 1]);
	*p = e;
	return 1;
}

//˳��ṹ���Ա��Ԫ�ز���λ�ã�����λ�÷��ظ�i
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
		printf("û���ҵ�Ԫ��%d������ʧ�ܣ�\a\n", e);
	}
	return 1;
}

//˳��ṹ���Ա��Ԫ��ֵ�滻Ϊ��һ��Ԫ�ص�ֵ
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
		printf("û���ҵ�Ԫ��%d���޸�ʧ�ܣ�\a\n", origin);
	}
	return 1;
}

//��ӡ˳��ṹ���Ա��е�Ԫ��ֵ
void printList(sqlList *L)
{
	ELEMTYPE *p = L->elem;
	for (int i = 0; i < L->listLengh; i++)
	{
		printf("%d:%d\n", i + 1, *p);
		p++;
	}
}

