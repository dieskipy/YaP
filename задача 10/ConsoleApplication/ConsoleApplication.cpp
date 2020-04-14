
#include <stdio.h>
#include <math.h>
int main()
{
	float num, ans;
	printf("Enter number \n");
	scanf_s("%f", &num);
	ans = pow(2, num);
	printf("%f", ans);
	return 0;
}