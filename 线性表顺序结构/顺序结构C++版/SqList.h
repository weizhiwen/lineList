#pragma once
#define ELEMTYPE int
#include <iostream>
using namespace std;

class SqList
{
private:
	int m_listLength; //���Ԫ�ظ���
	int m_listSize; //��ĳ�������
	ELEMTYPE *m_pList; //���Ա�Ԫ��
public:
	SqList(int listSize); //��������ʼ�����Ա�
	int listLength(); //���ص�ǰ����Ԫ�صĸ���
	int listSize(); //���ص�ǰ���������С
	bool insertList(int i, ELEMTYPE elem); //����λ�ò���Ԫ��elem
	bool deleteList(int i, ELEMTYPE &elem); 
	void printList(); //�������Ա�
	~SqList(); //�������Ա�
};

