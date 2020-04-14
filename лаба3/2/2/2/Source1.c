
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char A[100], B[100];
	char D[] = "abcdefghi";
	char temp;
	int n, k, i, j;

	printf("Write string: \n");
	gets_s(A);
	n = strlen(A);
	for (i = 1; i <= n; i++)
		A[i] = toupper(A[i]);
	k = 0;
	for (i = 1; i <= n; i++)
	{
		if strchr(D, A[i]) < > NULL
		{ 
			B = B + A[i];
			k++;
		}
	}

	for (i = 1; i <= k-1; i++)
	{
		for (j = (i + 1); j <= k; j++)
		{
			if (int)(B[i]) > (int)(B[j])
			{
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
	B[k + 1] = "\0";
	puts(B);
	return 0;
}