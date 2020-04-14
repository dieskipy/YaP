// лаба2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//матрица 5 строк и 10 столбцов. Упорядочить элементы в каждой строке по убыванию, а строки по возрастанию суммы

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <locale.h>

int main()
{
	int i, j, k, temp, col, line;
	int mas[5][10], summas[5];

	setlocale(LC_ALL, "Rus");

	//генерация случайной матрицы
	i = 0;
	srand(time(NULL));
	while (i < 5)
	{
		j = 0;
		while (j < 10)
		{
			temp = rand() % 200 - 100;
			mas[i][j] = temp;
			++j;
		}
		++i;
	}

	// сумма элементов в каждой из строк
	i = 0;
	while (i < 5)
	{
		temp = 0;
		for (j = 0; j < 10; ++j)
			temp = mas[i][j] + temp;
		summas[i] = temp;
		++i;
	}
	
	//вывод исходной матрицы и матрицы с суммами
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 10)
		{
			printf(" ");
			printf("%4d", mas[i][j]);
			++j;
		}
		printf("      %4d", summas[i]);
		printf("\n");
		++i;
	}
	printf("\n");

	//сортировка в строках
	i = 0;
	while (i < 5)
	{
		k = 0;
		while (k < 9)
		{	
			temp = mas[i][k];
			col = k;
			j = k+1;
			while (j<10)
			{	
				if (mas[i][j] > temp)
				{
					col = j;
					temp = mas[i][j];
				}
					
				++j;
			}	
			temp = mas[i][k];
			mas[i][k] = mas[i][col];
			mas[i][col] = temp;
			++k;
		}
		++i;	
	}


	//сортировка строк
	k = 0;
	while (k < 4)
	{
		temp = summas[k];
		i = k + 1;
		line = k;
		while (i < 5)
		{
			if (summas[i] < temp)
			{
				line = i;
				temp = summas[i];
			}
				
			++i;
		}
		temp = summas[line];
		summas[line] = summas[k];
		summas[k] = temp;

		i = k + 1;
		for (j = 0; j < 10; ++j)
		{
			temp = mas[i][j];
			mas[i][j] = mas[line][j];
			mas[line][j] = temp;
		}
		++k;
	}

	//вывод новой матрицы и матрицы с суммами
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 10)
		{
			printf(" ");
			printf("%4d", mas[i][j]);
			++j;
		}
		printf("      %4d", summas[i]);
		printf("\n");
		++i;
	}
	printf("\n");

	return 0;
}
