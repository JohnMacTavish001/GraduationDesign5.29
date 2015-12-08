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

	if (losePercentage<0 || losePercentage>100)
	{
		printf("请输入正确的丢包率！");
		return 1;
	}

	int buff = 0;                                    //用来暂时存放产生的随机数的变量

	srand((unsigned)time(NULL));                     //用时间做种，每次产生随机数不一样

	for (int i = 0; i < rowCount; i++)
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

	printf("有线环境丢包序列输出成功！\n");

	return 0;


}