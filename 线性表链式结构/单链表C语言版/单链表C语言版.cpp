// 单链表C语言版.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "nodeSList.h"

int main()
{
	NodeSList *L;
	initNode(&L);
	//测试插入函数
	insertNode(L, 1, 11);
	insertNode(L, 1, 22);
	insertNode(L, 2, 33);
	printNodeList(L);
	printf("\n");

	//测试删除函数
	ELEMTYPE elem;
	deleteNode(L, 1, &elem);
	printNodeList(L);
	printf("被删除的值为%d\n\n", elem);

	//测试查找函数
	selectNode(L, 2, &elem);
	printf("被查找的值的位置为%d\n\n", elem);

	//测试修改函数
	replaceNode(L, 2, 55);
	printNodeList(L);

	system("pause");
    return 0;
}

