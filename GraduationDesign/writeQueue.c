#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
int writeQueue(rowCount)                            //用来根据输入的丢包率创建丢包序列的函数
{
	FILE *fp;
	char ch;
	fp = fopen("D:/writeQueue.txt", "w");
	int losePercentage = 0;
	printf("请输入丢包率""%%""\n");
	scanf("%d", &losePercentage);
	int buff = 0;                                    //用来暂时存放产生的随机数的变量

	srand((unsigned)time(NULL));                     //用时间做种，每次产生随机数不一样

	for (int i = 0; i<rowCount; i++)
	{
		buff = rand() % 100 + 0;                     //产生1-100的随机数
		if (buff >= losePercentage)
		{
			fputs("-", fp);
			//printf("-");                           //屏显输出验证
		}
		else{
			fputs("|", fp);
			//printf("|");                            //屏显输出验证
		}
	}
	fclose(fp);
	getchar();
	getchar();
	return 0;


}