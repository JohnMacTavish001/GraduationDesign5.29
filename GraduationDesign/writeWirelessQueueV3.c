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
	BOOL	statusR = 1;

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
	
	float Pbb = 0.88888889;										//GEģ���е�Pbb����
	float Pbg = 1 - Pbb;									//GEģ���е�Pbg����
	
	float Pgb = Paverage * Pbg / (1 - Paverage);			//GEģ���е�Pgb����
	float Pgg = 1 - Pgb;									//GEģ���е�Pgg����
	float intBuff = 0;										//�ݴ�ÿ�����ʱ���������ֵ�ı���
	float buff = intBuff / 100;								//�����ݴ�ÿ�������������ֵ�ı���
	
	srand((unsigned)time(NULL));							//��ʱ������������������ӣ�ע��һ������ѭ������

	for (int i = 0; i < 100; i++)
	{
		intBuff = rand() % 100 + 0;							//���������
		buff = intBuff / 100;

		if (statusR == 0)
		{
			if (buff > Pbg)
			{
				printf("|");
				status = 0;
			}
			if (buff < Pbg)
			{
				printf("-");
				status = 1;
			}
		}
		if (statusR == 1)
		{
			if (buff > Pgb)
			{
				printf("-");
				status = 1;
			}
			if (buff < Pgb)
			{
				printf("|");
				status = 0;
			}
		}
		statusR = status;

	}
}