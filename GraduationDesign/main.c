#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void main()                                       //�����������߼�
{
	int choice = 0;

	printf("��ѡ����Ҫģ��Ķ������ͣ�\n 1.���߻����¶����� \n 2.���߻����¶�����\n\n");

	scanf("%d", &choice);

	switch (choice)
	{
	case 1: writeQueue(rowCount());						  //���������������д���û����嶪���ʵĶ������У���ɢ���У�
		break;
	case 2: writeWirelessQueueV3(rowCount());
		break;
	case 0: printf("����������ѡ��\n\n");
		main();
		break;
	default: printf("����ѡ������\n\n");
		main();
	}


	//excicute();											//���writeQueue�ļ���rd�ļ����в���



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
//		printf("writeQueue�ļ������ڣ�");
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
