#include <stdio.h>
#include <stdlib.h>

int excicute()										//读取文件的函数,将rowCount数出的行数传入
{
	FILE *fp;									//用来读取writeQueue文件的指针
	FILE *fp2;									//用来操作修改过后RD文件的指针
	FILE *fp3;									//用来打开修改之前的RD文件的指针

	char ch = "";									//用来读取writeQueue文件的缓存变量
	char ch2 = "";									//用来操作修改过后rd(newRD)文件的缓存变量
	char ch3 = "";									//用来打开修改之前的rd文件的缓存变量

	fp = fopen("D:/writeQueue.txt", "rt");
	fp2 = fopen("D:/newRD.txt", "w+");
	fp3 = fopen("D:/sd", "rt");

	if (fp == NULL)								//判断writeQueue文件是否存在，不存在则抛出异常
	{
		printf("writeQueue文档不存在！");
		getchar();
		getchar();
		exit(1);
	}

	if (fp3 == NULL)							//判断rd文件是否存在，不存在则抛出异常
	{
		printf("rd文档不存在！");
		getchar();
		getchar();
		exit(1);
	}




	while (!feof(fp))							//如果writeQueue文件中读到一个“-”，则将原rd文件中一行写入到newRD文件中。
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

		if (ch == '|')							//如果writeQueue文件中读到一个“|”，则不进行写入，指针后移。
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