// ˳��ṹC���԰�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "sqList.h"


int main()
{
	sqlList L;
	initList(&L);
	//���Ա�Ĳ���ĺ���
	insertList(&L, 1, 11);
	insertList(&L, 2, 22);
	insertList(&L, 3, 33);
	insertList(&L, 4, 44);	
	insertList(&L, 5, 55);
	insertList(&L, 6, 66);
	insertList(&L, 3, 31);
	printList(&L);
	printf("\n");

	//���Ա��ɾ������
	ELEMTYPE elem;
	deleteList(&L, 2, &elem);
	printList(&L);
	printf("��ɾ����ֵΪ%d\n", elem);
	printf("\n");

	//���Ա�Ĳ��Һ���
	selectiList(&L, 5, &elem);
	printf("�����ҵ�ֵΪ%d\n", elem);
	int i;
	selecteList(&L, 55, &i);
	printf("�����ҵ�ֵ��λ��Ϊ%d\n", i);

	//���Ա���޸ĺ���
	replaceiList(&L, 1, 12);
	printList(&L);
	printf("\n");
	replaceeList(&L, 55, 51);
	printList(&L);

	system("pause");
    return 0;
}

