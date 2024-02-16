#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/********************************************/
// 读取csv格式文件示例
// 成绩表可使用excel制作另存为csv格式
/********************************************/
int main() {
	FILE* fp;
	fp = fopen("example.csv", "r"); //读取csv文件
	
	if(fp == NULL) { //提示读取失败
		printf("fopen() failed\n");
	}
	
	float num;
	
	char row[100];
	while(fgets(row, 100, fp) != NULL) { //读取一行字符到row，最大字符数量100
		printf("Row: %s", row);
		row[strlen(row) - 1] = '\0'; //去除row的末尾换行符
		
		//按逗号分割字符串并依次读取
		for(char* token = strtok(row, ","); token != NULL; token = strtok(NULL, ",")) {
			/*************/
			// Your code
			/*************/
			//示例1，直接打印token字符串
			printf("[%s] ", token);
			//示例2，将字符串转为数字并打印
			num = strtod(token, NULL);
			printf("[%.2f] ", num);
		}
		printf("\n");
	}
	
	fclose(fp);
	
	return 0;
}

