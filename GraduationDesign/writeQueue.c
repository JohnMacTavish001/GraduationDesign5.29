#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
int writeQueue(rowCount)                            //������������Ķ����ʴ����������еĺ���
{
	FILE *fp;
	char ch;
	fp = fopen("D:/writeQueue.txt", "w");

	int losePercentage = 0;
	printf("�����붪����""%%""\n");
	scanf("%d", &losePercentage);

	if (losePercentage<0 || losePercentage>100)
	{
		printf("��������ȷ�Ķ����ʣ�");
		return 1;
	}

	int buff = 0;                                    //������ʱ��Ų�����������ı���

	srand((unsigned)time(NULL));                     //��ʱ�����֣�ÿ�β����������һ��

	for (int i = 0; i < rowCount; i++)
	{
		buff = rand() % 100 + 0;                     //����1-100�������
		if (buff >= losePercentage)
		{
			fputs("-", fp);
			//printf("-");                           //���������֤
		}
		else{
			fputs("|", fp);
			//printf("|");                            //���������֤
		}
	}
	fclose(fp);

	printf("���߻���������������ɹ���\n");

	return 0;


}