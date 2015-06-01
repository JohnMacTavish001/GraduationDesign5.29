#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

int writeWirelessQueueV2(rowCount)
{
	FILE *fp;
	char ch;

	int lostPercentage = 0;											//用来保存丢包率的变量
	int buff = 0;													//用来暂存每次产生的随机数的变量
	int lostPackageAmount = 0;										//用来保存总共丢掉的包的数量
	int continueLosingBuff = 0;										//在发生丢包时暂存用来判断是否继续丢包的随机数
	int continueLosingPercentage = 0;								//在一个数据包丢失后下一个包继续丢失的概率
	BOOL status = TRUE;												//表示本时刻状态的信号量。TRUE表示不丢包，FALSE表示丢包
	BOOL lastStatus = FALSE;										//表示上一个时刻状态的信号量。TRUE表示不丢包，FALSE表示丢包

	fp = fopen("D:/writeQueue.txt", "w");

	printf("请输入丢包率""(""%%"")""\n");
	scanf("%d", &lostPercentage);

	if (lostPercentage > 100 || lostPercentage < 0)
	{
		printf("输入有误，请重新输入");
		fclose(fp);
		return 1;
	}

	lostPackageAmount = lostPercentage * rowCount / 100;			//首先算出一共要丢弃多少行
	//printf("%d", lostPackageAmount);

	srand((unsigned)time(NULL));

	for (int i = 0; i <= rowCount; i++)								//依据rowCount数出的行数进行循环，以写出正确数量的“-”和“|”
	{
		buff = rand() % 100 + 0;

		if (lostPackageAmount <= 0)									//如果该变量非正数则说明已经丢弃了相应数量的行，跳出循环
		{
			break;
		}

		if (lastStatus == TRUE)
		{
			if (buff >= lostPercentage)
			{
				fputs("-", fp);

				status = TRUE;

			}
			else
			{
				fputs("|", fp);

				status = FALSE;

				lostPackageAmount--;
			}
		}
		else
		{
			srand((unsigned)time(NULL));

			continueLosingBuff = rand() % 100 + 0;

			//continueLosingPercentage = 100 - (100 - lostPercentage) * 0.1;
			continueLosingPercentage = 90;

			if (continueLosingBuff >= continueLosingPercentage)
			{
				fputs("|", fp);

				status = FALSE;

				lostPackageAmount--;
			}
			else
			{
				fputs("-", fp);

				status = TRUE;
			}
		}

		lastStatus = status;
	}
	fclose(fp);
	return 0;
}
