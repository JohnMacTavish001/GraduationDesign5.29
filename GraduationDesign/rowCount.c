#include <stdio.h>
#include <stdlib.h>

int rowCount()                                    //�����ļ��кŵĺ���
{
	FILE *fp;
	char ch;
	int i = 0;                                    //����ͳ���ж����еı���
	fp = fopen("D:/sd", "rt");
	if (fp == NULL)
	{
		printf("�޷����ļ�");
		getchar();
		exit(1);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		ch = fgetc(fp);
		while (!feof(fp))
		{
			if ((ch = fgetc(fp)) == '\n')
			{
				i++;
			}
		}
	}
	fclose(fp);


	return i;

}