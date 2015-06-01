#include <stdio.h>
#include <stdlib.h>

int rowCount()                                    //计算文件行号的函数
{
	FILE *fp;
	char ch;
	int i = 0;                                    //用来统计有多少行的变量
	fp = fopen("D:/rd", "rt");
	if (fp == NULL)
	{
		printf("无法打开文件");
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