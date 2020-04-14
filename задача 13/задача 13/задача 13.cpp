#include <stdio.h>
#include <math.h>
int main()
{
	double num, ans, prom;
	ans = 1;
	num = 0.1;
	while (num <= 10)
	{
		prom = 1 + sin(num);
		ans = prom * ans;
		num = 0.1 + num;

	}
	printf("%e", ans);
	return 0;
}