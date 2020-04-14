// 1.c
// Все символы строки А заменяются с М-ного на N первых символов строки B

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>

int main()
{
	int M, N, lenA, lenB;
	char A[100];
	char B[100];
	char C[100];
	char D[100];
	int i, j;
	printf("Write string A: \n");
	gets_s(A);
	

	printf("Write string B: \n");
	gets_s(B);

	printf("Write index M: \n");
	scanf_s("%d", &M);

	printf("Write number of symbols N: \n");
	scanf_s("%d", &N);

	lenA = strlen(A);
	lenB = strlen(B);
	strncpy_s(C, A, (M - 1));
	strncpy_s(D, B, N);
	strcat_s(C, D);
	i = 0;
	for (int j = M + N-1; j <= lenA; j++)
	{
		A[i] = A[j];
		i++;
	}
	i--;
	strcat_s(C, A);
	puts(C);
	return 0;
}