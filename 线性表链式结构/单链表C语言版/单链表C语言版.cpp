// ������C���԰�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "nodeSList.h"

int main()
{
	NodeSList *L;
	int n = 0;
	//���Դ���������
	printf("������n=");
	scanf_s("%d", &n);
	createNode(&L, n);
	printNodeList(L);
	printf("\n");

	//���Բ��뺯��
	insertNode(L, 1, 11);
	insertNode(L, 1, 22);
	insertNode(L, 6, 33);
	printNodeList(L);
	printf("\n");

	//����ɾ������
	ELEMTYPE elem;
	deleteNode(L, 1, &elem);
	printNodeList(L);
	printf("��ɾ����ֵΪ%d\n\n", elem);

	//���Բ��Һ���
	selectNode(L, 2, &elem);
	printf("�����ҵ�ֵ��λ��Ϊ%d\n\n", elem);

	//�����޸ĺ���
	replaceNode(L, 2, 55);
	printNodeList(L);

	system("pause");
    return 0;
}

