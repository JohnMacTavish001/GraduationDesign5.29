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
	case 2: writeWirelessQueueV2(rowCount());
		break;
	case 0: printf("����������ѡ��\n\n");
		main();
		break;
	default: printf("����ѡ������\n\n");
		main();
	}


	excicute();											//���writeQueue�ļ���rd�ļ����в���



	system("pause");




}
