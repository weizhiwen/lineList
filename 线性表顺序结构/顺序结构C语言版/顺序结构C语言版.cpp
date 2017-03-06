// 顺序结构C语言版.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "sqList.h"


int main()
{
	sqlList L;
	initList(&L);
	//测试表的插入的函数
	insertList(&L, 1, 11);
	insertList(&L, 2, 22);
	insertList(&L, 3, 33);
	insertList(&L, 4, 44);	
	insertList(&L, 5, 55);
	insertList(&L, 6, 66);
	insertList(&L, 3, 31);
	printList(&L);
	printf("\n");

	//测试表的删除函数
	ELEMTYPE elem;
	deleteList(&L, 2, &elem);
	printList(&L);
	printf("被删除的值为%d\n", elem);
	printf("\n");

	//测试表的查找函数
	selectiList(&L, 5, &elem);
	printf("被查找的值为%d\n", elem);
	int i;
	selecteList(&L, 55, &i);
	printf("被查找的值的位置为%d\n", i);

	//测试表的修改函数
	replaceiList(&L, 1, 12);
	printList(&L);
	printf("\n");
	replaceeList(&L, 55, 51);
	printList(&L);

	system("pause");
    return 0;
}

