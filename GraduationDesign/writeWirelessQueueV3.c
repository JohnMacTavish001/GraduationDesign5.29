/*该函数基于GE模型，前提是默认在“好”的状态下丢包率为0，在“坏”的情况下丢包率为100%。*/
/*在此情况下，通过计算可得平均封包丢失率Paverage=Pgb/(Pgb+Pbg)*/

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

	float lostPercentageBuff = 0;							//输入1-100之间的整数当作
	float Paverage = 0;										//丢包率

	printf("请输入丢包率""%%""\n");
	scanf("%f", &lostPercentageBuff);

	if (lostPercentageBuff > 100 || lostPercentageBuff < 0)
	{
		printf("请输入正确的丢包率！");
		return 1;
	}

	Paverage = lostPercentageBuff / 100;					//平均封包遗失率

	float Pbb = 0.88888889;									//GE模型中的Pbb参数
	float Pbg = 1 - Pbb;									//GE模型中的Pbg参数

	float Pgb = Paverage * Pbg / (1 - Paverage);			//GE模型中的Pgb参数
	float Pgg = 1 - Pgb;									//GE模型中的Pgg参数
	float intBuff = 0;										//暂存每次随机时候随机整数值的变量
	float buff = intBuff / 100;								//用来暂存每次随机产生的数值的变量

	int lostPackageAmount = rowCount * Paverage;			//用于计算总共丢失的数据包，确保丢包数量的准确性

	FILE *fp;
	fp = fopen("D:/writeQueue.txt", "w");					//打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件

	srand((unsigned)time(NULL));							//用时间做产生随机数的种子，注意一定放在循环体外

	for (int i = 0; i < rowCount; i++)
	{
		intBuff = rand() % 100 + 0;							//产生随机数
		buff = intBuff / 100;

		if (lostPackageAmount < 1)							//如果该参数不大于零，说明已经丢够了规定数量的数据包
		{
			break;											//跳出循环(这样可以保证总丢包数的准确性，但是当输入丢包率为零时会跳出以至于不能写出序列)
		}

		if (lastStatus == 0)								//如果上一时刻的状态是丢包，则随机数与Pbg或Pbb进行比较
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
		if (lastStatus == 1)								//如果上一时刻的状态是不丢包，则随机数与Pgb或Pgg进行比较
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

		lastStatus = status;								//每次循环结束，用本时刻状态为上时刻状态赋值，本时刻状态成为下一时刻的“上时刻状态”

	}

	fclose(fp);

	printf("无线环境丢包序列输出成功！\n");

	return 0;
}