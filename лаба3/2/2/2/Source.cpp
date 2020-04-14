//ввод с клавиатуры строки, все прописные в строчные, выбрать от A до I, отсортировать по алфавиту
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cstring>
#include <iostream>

int main()
{
	char A[100] = {};
	char B[100] = {};
	char D[] = "ABCDEFGHI";
	char temp;
	char *p;
	int n, k, i, j;


	printf("Write string: \n");
	gets_s(A);
	n = strlen(A);
	for (i = 0; i <= n-1; i++)
		A[i] = toupper(A[i]);
	k = 0;
	for (i = 0; i <= n-1; i++)
	{
		p = strchr(D, A[i]);
		if (p != NULL)
		{
			temp = A[i];
			B[k] = A[i];
			k++;
		};
	};

	for (i = 0; i <= k - 2; i++)
	{
		for (j = (i + 1); j <= k-1; j++)
		{
			if ((int)(B[i]) > (int)(B[j]))
			{
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			};
		};
	};
	puts(B);
	return 0;
}