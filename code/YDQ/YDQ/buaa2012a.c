#include <stdio.h>

void main()
{
	int N = 0;
	scanf_s("%d",&N);

	int count = 0;
	if (N==3)
	{
		printf("1 2 \n");
		count++;
	}

	if (N == 5)
	{
		printf("2 3 \n");
		count++;
	}

	if (5< N <= 10000)
	{
		for (int i = 2; i < N/2; i++)
		{
			if (i % 2 == 0)
			{
				if (0.5 == (N/(i*1.0)-N/i))
				{
					if ((N / i + -i / 2+1) > 0)
					{
						for (int j = -i / 2 + 1; j <= i / 2; j++)
						{
							printf("%d ", N / i + j);
						}

						printf("\n");
						count++;
					}
				}
			}
			else
			{
				if (0 == N % i)
				{
					if ((N / i + -i / 2) > 0)
					{
						for (int j = -i / 2; j <= i / 2; j++)
						{
							printf("%d ", N / i + j);
						}

						printf("\n");
						count++;
					}
				}
			}
		}
	}

	if (0 == count||N==1||N==2||N==4)
	{
		printf("NONE");
	}

}