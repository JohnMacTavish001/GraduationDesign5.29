#include <stdio.h>
#include <stdlib.h>

int excicute()										//��ȡ�ļ��ĺ���,��rowCount��������������
{
	FILE *fp;									//������ȡwriteQueue�ļ���ָ��
	FILE *fp2;									//���������޸Ĺ���RD�ļ���ָ��
	FILE *fp3;									//�������޸�֮ǰ��RD�ļ���ָ��

	char ch = "";									//������ȡwriteQueue�ļ��Ļ������
	char ch2 = "";									//���������޸Ĺ���rd(newRD)�ļ��Ļ������
	char ch3 = "";									//�������޸�֮ǰ��rd�ļ��Ļ������

	fp = fopen("D:/writeQueue.txt", "rt");
	fp2 = fopen("D:/newRD.txt", "w+");
	fp3 = fopen("D:/sd", "rt");

	if (fp == NULL)								//�ж�writeQueue�ļ��Ƿ���ڣ����������׳��쳣
	{
		printf("writeQueue�ĵ������ڣ�");
		getchar();
		getchar();
		exit(1);
	}

	if (fp3 == NULL)							//�ж�rd�ļ��Ƿ���ڣ����������׳��쳣
	{
		printf("rd�ĵ������ڣ�");
		getchar();
		getchar();
		exit(1);
	}




	while (!feof(fp))							//���writeQueue�ļ��ж���һ����-������ԭrd�ļ���һ��д�뵽newRD�ļ��С�
	{
		ch = fgetc(fp);
		if (ch == '-')
		{
			while (!feof(fp3))
			{
				ch3 = fgetc(fp3);
				fputc(ch3, fp2);
				if (ch3 == '\n')
				{
					break;
				}

			}

		}

		if (ch == '|')							//���writeQueue�ļ��ж���һ����|�����򲻽���д�룬ָ����ơ�
		{
			while (!feof(fp3))
			{
				ch3 = fgetc(fp3);
				if (ch3 == '\n')
				{
					break;
				}

			}
		}
	}





	fclose(fp);
	fclose(fp2);
	fclose(fp3);


	return 0;
}