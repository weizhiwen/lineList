// ˳��ṹC++��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "SqList.h"
using namespace std;

int main()
{
	SqList L(5);
	//���Բ��뺯��
	L.insertList(1, 1);
	L.insertList(2, 2);
	L.insertList(3, 3);
	L.insertList(4, 4);
	L.insertList(5, 5);
	L.insertList(6, 6);
	L.printList();
	cout << "Ԫ�ظ���Ϊ" << L.listLength() << endl;
	cout << "���Ա���Ϊ" << L.listSize() << endl;
	system("pause");
    return 0;
}

