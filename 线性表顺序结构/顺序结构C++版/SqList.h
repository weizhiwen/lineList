#pragma once
#define ELEMTYPE int
#include <iostream>
using namespace std;

class SqList
{
private:
	int m_listLength; //表的元素个数
	int m_listSize; //表的长度容量
	ELEMTYPE *m_pList; //线性表元素
public:
	SqList(int listSize); //创建并初始化线性表
	int listLength(); //返回当前表中元素的个数
	int listSize(); //返回当前表的容量大小
	bool insertList(int i, ELEMTYPE elem); //任意位置插入元素elem
	bool deleteList(int i, ELEMTYPE &elem); 
	void printList(); //遍历线性表
	~SqList(); //销毁线性表
};

