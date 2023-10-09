#include <stdio.h>

int main()
{
	int i, n, o, p, sum, amount;
	scanf("%d", &n);

	for (i = (n - 2 - 1) / 5; i > 0; i--)
	{
		for (o = (n - 5 - 1) / 2; o > 0; o--)
		{
			p = n - (i * 5 + o * 2);
			sum = i * 5 + o * 2 + p;
			if (sum == n && p > 0)
			{
				amount++;
			}
		}
	}
	printf("%d\n", amount);

	return 0;
}

