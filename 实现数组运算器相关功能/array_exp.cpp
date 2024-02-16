/*
*文件描述：数组运算器主程序
*功能：实现数组运算器相关模块功能
*/
#include <stdio.h>
#include <stdlib.h>
#include "arrayCalculator.h"//引入自定义的数组运算器头文件

int main() {
	int a[MAX_LENGTH] = {0};
	char ch;
	while (1) {
		printMenu();
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c", &ch);
		clearCache();
		if (ch == '0')
			break;
		switch (ch) {
			case'1':
				config();//配置系统参数
				break;
		case'2':
				fillArray(a);//生成样本数据
					break;
			case'3':
				printArray(a);//显示数组
				break;
			case'4':
				deleteElement(a);//删除
				break;
			case'5':
				insert(a);//插入
				break;
			case'6':
				search(a);//查找
				break;
			case'7':
				sort(a);//排列数组元素
				break;
			default:
				break;
		}
	}
}
