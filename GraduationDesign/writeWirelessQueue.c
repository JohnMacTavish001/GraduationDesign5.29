#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int writeWirelessQueue(rowCount)
{
	FILE *fp;

	char ch;

	fp = fopen("D:/writeQueue.txt", "w");

	int losePercentage = 0;

	printf("�����붪���ʣ�'%'��\n");

	scanf("%d", &losePercentage);

	int lostPackage = rowCount * losePercentage / 100;	//�����һ����ʧ�����ݰ��Է����Ժ�ļ���

	int buff = 0;										//������ʱ��Ų�����������ı���

	int lostPackageAmount = 0;							//�����ݴ�ÿ������ʱ�̶������ݰ��ı���

	srand((unsigned)time(NULL));						//��ʱ�����֣�ÿ�β����������һ��

	for (int i = 0; i<rowCount; i++)
	{
		buff = rand() % 100 + 0;						//����1-100�������



	}
	if (buff >= losePercentage)
	{
		fputs("-", fp);
	}
	else
	{
		srand((unsigned)time(NULL));			//ÿ�ζ�������ĿҲ��ʱ������

		lostPackageAmount = rand() % lostPackage + 0;//ÿ�ζ�������Ŀ��������Ƕ�������Ŀ��0������������������*��rowCount�����ó�����������֮��

		while (lostPackage > 0)
		{
			for (int j = lostPackageAmount; j > 0; j--)
			{
				fputs("-", fp);

				lostPackage--;
			}
		}
	}

	fclose(fp);
	getchar();
	getchar();
	return 0;
}