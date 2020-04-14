//ввод посл из единиц и нулей, между подряд стоящими единицами вставить ноль
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>

int main()
{
	int  k;
	char A[100];

	printf("Write massive with 1s ang Os \n");
	gets_s(A);

	k = strlen(A);
	for (int i = 0; i < k - 1; i++)
	{
		if (A[i] == '1')
		{
			if (A[i] == A[i + 1])
			{
				k++;
				for (int j = k - 1; j > i + 1; j--)
					A[j] = A[j - 1];
				A[i + 1] = '0';
			}
		}
	};

	A[k] = '\0';
	puts(A);

	return 0;
}