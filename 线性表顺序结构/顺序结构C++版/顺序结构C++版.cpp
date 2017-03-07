// 顺序结构C++版.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "SqList.h"
using namespace std;

int main()
{
	SqList L(5);
	//测试插入函数
	L.insertList(1, 1);
	L.insertList(2, 2);
	L.insertList(3, 3);
	L.insertList(4, 4);
	L.insertList(5, 5);
	L.insertList(6, 6);
	L.printList();
	cout << "元素个数为" << L.listLength() << endl;
	cout << "线性表长度为" << L.listSize() << endl;
	system("pause");
    return 0;
}

