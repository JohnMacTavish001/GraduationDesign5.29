#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

int writeWirelessQueueV2(rowCount)
{
	FILE *fp;
	char ch;

	int lostPercentage = 0;											//�������涪���ʵı���
	int buff = 0;													//�����ݴ�ÿ�β�����������ı���
	int lostPackageAmount = 0;										//���������ܹ������İ�������
	int continueLosingBuff = 0;										//�ڷ�������ʱ�ݴ������ж��Ƿ���������������
	int continueLosingPercentage = 0;								//��һ�����ݰ���ʧ����һ����������ʧ�ĸ���
	BOOL status = TRUE;												//��ʾ��ʱ��״̬���ź�����TRUE��ʾ��������FALSE��ʾ����
	BOOL lastStatus = FALSE;										//��ʾ��һ��ʱ��״̬���ź�����TRUE��ʾ��������FALSE��ʾ����

	fp = fopen("D:/writeQueue.txt", "w");

	printf("�����붪����""(""%%"")""\n");
	scanf("%d", &lostPercentage);

	if (lostPercentage > 100 || lostPercentage < 0)
	{
		printf("������������������");
		fclose(fp);
		return 1;
	}

	lostPackageAmount = lostPercentage * rowCount / 100;			//�������һ��Ҫ����������
	//printf("%d", lostPackageAmount);

	srand((unsigned)time(NULL));

	for (int i = 0; i <= rowCount; i++)								//����rowCount��������������ѭ������д����ȷ�����ġ�-���͡�|��
	{
		buff = rand() % 100 + 0;

		if (lostPackageAmount <= 0)									//����ñ�����������˵���Ѿ���������Ӧ�������У�����ѭ��
		{
			break;
		}

		if (lastStatus == TRUE)
		{
			if (buff >= lostPercentage)
			{
				fputs("-", fp);

				status = TRUE;

			}
			else
			{
				fputs("|", fp);

				status = FALSE;

				lostPackageAmount--;
			}
		}
		else
		{
			srand((unsigned)time(NULL));

			continueLosingBuff = rand() % 100 + 0;

			//continueLosingPercentage = 100 - (100 - lostPercentage) * 0.1;
			continueLosingPercentage = 90;

			if (continueLosingBuff >= continueLosingPercentage)
			{
				fputs("|", fp);

				status = FALSE;

				lostPackageAmount--;
			}
			else
			{
				fputs("-", fp);

				status = TRUE;
			}
		}

		lastStatus = status;
	}
	fclose(fp);
	return 0;
}
