/*�ú�������GEģ�ͣ�ǰ����Ĭ���ڡ��á���״̬�¶�����Ϊ0���ڡ�����������¶�����Ϊ100%��*/
/*�ڴ�����£�ͨ������ɵ�ƽ�������ʧ��Paverage=Pgb/(Pgb+Pbg)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

int writeWirelessQueueV3(rowCount)
{
	BOOL	status = 0;
	BOOL	lastStatus = 1;

	float lostPercentageBuff = 0;							//����1-100֮�����������
	float Paverage = 0;										//������

	printf("�����붪����""%%""\n");
	scanf("%f", &lostPercentageBuff);

	if (lostPercentageBuff > 100 || lostPercentageBuff < 0)
	{
		printf("��������ȷ�Ķ����ʣ�");
		return 1;
	}

	Paverage = lostPercentageBuff / 100;					//ƽ�������ʧ��

	float Pbb = 0.88888889;									//GEģ���е�Pbb����
	float Pbg = 1 - Pbb;									//GEģ���е�Pbg����

	float Pgb = Paverage * Pbg / (1 - Paverage);			//GEģ���е�Pgb����
	float Pgg = 1 - Pgb;									//GEģ���е�Pgg����
	float intBuff = 0;										//�ݴ�ÿ�����ʱ���������ֵ�ı���
	float buff = intBuff / 100;								//�����ݴ�ÿ�������������ֵ�ı���

	int lostPackageAmount = rowCount * Paverage;			//���ڼ����ܹ���ʧ�����ݰ���ȷ������������׼ȷ��

	FILE *fp;
	fp = fopen("D:/writeQueue.txt", "w");					//��ֻд�ļ������ļ��������ļ�������Ϊ0�������ļ����ݻ���ʧ�����ļ��������������ļ�

	srand((unsigned)time(NULL));							//��ʱ������������������ӣ�ע��һ������ѭ������

	for (int i = 0; i < rowCount; i++)
	{
		intBuff = rand() % 100 + 0;							//���������
		buff = intBuff / 100;

		if (lostPackageAmount < 1)							//����ò����������㣬˵���Ѿ������˹涨���������ݰ�
		{
			break;											//����ѭ��(�������Ա�֤�ܶ�������׼ȷ�ԣ����ǵ����붪����Ϊ��ʱ�����������ڲ���д������)
		}

		if (lastStatus == 0)								//�����һʱ�̵�״̬�Ƕ��������������Pbg��Pbb���бȽ�
		{
			if (buff > Pbg)
			{
				fputs("|", fp);
				//printf("|");
				status = 0;
				lostPackageAmount--;
			}
			if (buff < Pbg)
			{
				fputs("-", fp);
				//printf("-");
				status = 1;
			}
		}
		if (lastStatus == 1)								//�����һʱ�̵�״̬�ǲ����������������Pgb��Pgg���бȽ�
		{
			if (buff > Pgb)
			{
				fputs("-", fp);
				//printf("-");
				status = 1;
			}
			if (buff < Pgb)
			{
				fputs("|", fp);
				//printf("|");
				status = 0;
				lostPackageAmount--;
			}
		}

		lastStatus = status;								//ÿ��ѭ���������ñ�ʱ��״̬Ϊ��ʱ��״̬��ֵ����ʱ��״̬��Ϊ��һʱ�̵ġ���ʱ��״̬��

	}

	fclose(fp);

	printf("���߻���������������ɹ���\n");

	return 0;
}