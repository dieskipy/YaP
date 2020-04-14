
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	
	char A[100];
	char B[100];
	int tempi, tempj, i, j, k;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введите стоку прописными русскими буквами: \n");
	gets_s(A);

	

	tempi = 0;
	tempj = strlen(A);
	tempj--;
	k = 0;
	while (tempi <= tempj)
	{
		i = tempi;
		while ((A[i] != A[i + 1]) and (tempi<=tempj))
		{
			B[k] = A[i];
			i++;
			tempi = i;
			k++;
		}

		if ((A[i] = A[i + 1]) and (tempi <= tempj))
		{
			B[k] = '_';
			k++;
			tempi = tempi + 2;
		}		

		j = tempj;
		while ((A[j] != A[j - 1]) and (tempi <= tempj))
		{
			B[k] = A[j];
			j--;
			tempj = j;
			k++;
		}

		if ((A[j] = A[j - 1]) and (tempi <= tempj))
		{
			B[k] = '_';
			k++;
			tempj = tempj - 2;
		}
	}
	B[k]='\0';
	printf("Протокол чтения: \n");
	puts(B);
}
