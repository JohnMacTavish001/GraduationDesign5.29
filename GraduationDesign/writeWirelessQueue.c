#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int writeWirelessQueue(rowCount)
{
	FILE *fp;

	char ch;

	fp = fopen("D:/writeQueue.txt", "w");

	int losePercentage = 0;

	printf("请输入丢包率（'%'）\n");

	scanf("%d", &losePercentage);

	int lostPackage = rowCount * losePercentage / 100;	//计算出一共丢失的数据包以方便以后的计算

	int buff = 0;										//用来暂时存放产生的随机数的变量

	int lostPackageAmount = 0;							//用来暂存每个丢包时刻丢掉数据包的变量

	srand((unsigned)time(NULL));						//用时间做种，每次产生随机数不一样

	for (int i = 0; i<rowCount; i++)
	{
		buff = rand() % 100 + 0;						//产生1-100的随机数



	}
	if (buff >= losePercentage)
	{
		fputs("-", fp);
	}
	else
	{
		srand((unsigned)time(NULL));			//每次丢包的数目也由时间做种

		lostPackageAmount = rand() % lostPackage + 0;//每次丢包的数目随机，但是丢包的数目在0到丢包总数（丢包率*由rowCount函数得出的总行数）之间

		while (lostPackage > 0)
		{
			for (int j = lostPackageAmount; j > 0; j--)
			{
				fputs("-", fp);

				lostPackage--;
			}
		}
	}

	fclose(fp);
	getchar();
	getchar();
	return 0;
}