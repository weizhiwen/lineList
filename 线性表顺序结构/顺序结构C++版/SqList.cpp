#include "stdafx.h"
#include "SqList.h"


SqList::SqList(int listSize)
{
	m_listSize = listSize;
	m_listLength = 0;
	m_pList = new ELEMTYPE[m_listSize];
}

int SqList::listLength()
{
	return m_listLength;
}

int SqList::listSize()
{
	return m_listSize;
}

bool SqList::insertList(int i, ELEMTYPE elem)
{
	if (i < 0 || i > m_listLength + 1)
	{
		cout << "���ܲ���" << i << "λ�ã�" << "����ʧ�ܣ�" << endl;
		return false;
	}
	//if (m_listLength >= m_listSize)
	//{
	//	m_pList = new ELEMTYPE;
	//	cout << "��ǰ����Ԫ�صĸ����ѳ�����ĳ�ʼ������С�����Զ����������" << endl;
	//	if (!m_pList)
	//	{
	//		cout << "����ռ䲻����\a" << endl;
	//		return false;
	//	}
	//	m_listSize++;
	//}
	for (int j = m_listLength - 1; j > i - 1; j--)
		m_pList[j + 1] = m_pList[j];
	m_pList[i - 1] = elem;
	m_listLength++;
	return true;
}

bool SqList::deleteList(int i, ELEMTYPE &elem)
{
	if(i < 0 || i > m_listLength -1)
	{
		cout << "û��" << i << "λ�õ�Ԫ�أ�ɾ��ʧ��!";
		return false;
	}
	elem = m_pList[i - 1]; //���ص�ǰɾ����Ԫ��ֵ
	for (int j = i; j < m_listLength; j++)
		m_pList[i - 1] = m_pList[i];
	m_listLength--;
	return true;
}

void SqList::printList()
{
	int lengh = listLength();
	for (int i = 0; i < lengh; i++)
		cout << m_pList[i] << endl;
}


SqList::~SqList()
{
	delete[]m_pList;
	m_pList = NULL;
}
