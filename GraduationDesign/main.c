#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void main()                                       //主函数，主逻辑
{
	int choice = 0;

	printf("请选择需要模拟的丢包类型：\n 1.有线环境下丢包。 \n 2.无线环境下丢包。\n\n");

	scanf("%d", &choice);

	switch (choice)
	{
	case 1: writeQueue(rowCount());						  //根据输出的行数，写出用户定义丢包率的丢包序列（离散序列）
		break;
	case 2: writeWirelessQueueV3(rowCount());
		break;
	case 0: printf("请输入您的选择\n\n");
		main();
		break;
	default: printf("您的选择有误\n\n");
		main();
	}


	excicute();											//针对writeQueue文件对rd文件进行操作



	system("pause");



	//countResultRows(rowCount());
}


//int countResultRows(rowCount)
//{
//	FILE *fp;
//	char ch = NULL;
//	int resultRows = 0;
//	int lostAmount = 0;
//	int normalAmount = 0;
//	fp = fopen("D:/writeQueue.txt", "rt");
//	if (fp == NULL)
//	{
//		printf("writeQueue文件不存在！");
//		return 1;
//	}
//	while (ch != EOF)
//	{
//		ch = fgetc(fp);
//		if (ch = "-")
//		{
//			normalAmount++;
//		}
//		if (ch = "|")
//		{
//			lostAmount++;
//		}
//		resultRows++;
//	}
//	
//	printf("rowCount%d\n", rowCount);
//	printf("%d\n", resultRows - 1);
//	//printf("", rowCount == resultRows ? "True" : "False");
//	getchar();
//	getchar();
//	return 0;
//}
