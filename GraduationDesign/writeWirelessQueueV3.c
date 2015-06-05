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
	BOOL	statusR = 1;

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
	
	float Pbb = 0.88888889;										//GE模型中的Pbb参数
	float Pbg = 1 - Pbb;									//GE模型中的Pbg参数
	
	float Pgb = Paverage * Pbg / (1 - Paverage);			//GE模型中的Pgb参数
	float Pgg = 1 - Pgb;									//GE模型中的Pgg参数
	float intBuff = 0;										//暂存每次随机时候随机整数值的变量
	float buff = intBuff / 100;								//用来暂存每次随机产生的数值的变量
	
	srand((unsigned)time(NULL));							//用时间做产生随机数的种子，注意一定放在循环体外

	for (int i = 0; i < 100; i++)
	{
		intBuff = rand() % 100 + 0;							//产生随机数
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