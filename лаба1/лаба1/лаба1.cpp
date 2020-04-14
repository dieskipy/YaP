// лаба1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//i - строки j - столбцы

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <locale.h>

int main()
{
	int i, j, num1, num2, temp, temp1, col, line;
	int mas1[5][5], mas[5][5];

     setlocale(LC_ALL, "Rus");

	//генерация случайной матрицы
	i = 0;
	srand(time(NULL));
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			temp= rand() % 200 - 100;
			mas[i][j] = temp;
			mas1[i][j] = temp;
			++j;
		}
		++i;
	}

	//вывод исходной матрицы
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf(" ");
			printf("%4d", mas[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	printf("\n");



	//поиск наиб элемента на диагоналях и свайп с центральным

	i = 0;
	j = 0;
	temp = 0;
	while (i < 5)
	{
		if (mas[i][j]>temp) 
		{
			temp = mas[i][j];
			num1 = i;
			num2 = j;
		}
		++i;
		++j;
	}
	i = 0;
	j = 4;
	while (i < 5)
	{
		if (mas[i][j] > temp)
		{
			temp = mas[i][j];
			num1 = i;
			num2 = j;
		}
		++i;
		--j;
	}
	temp1 = mas[2][2];
	mas[2][2] = temp;
	mas[num1][num2] = temp1;

	//вывод новой матрицы
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf(" ");
			printf("%4d", mas[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	printf("\n");
	printf("элемент строки %d", num1+1);
	printf(" cтолбца %d", num2+1);
	printf(" поменялся с центральным \n\n");
	

	//часть с удалением
	// поиск строки с наиб колвом отриц элементов
	num1 = 0;
	i = 0;
	line = 0;
	while (i < 5)
	{
		j = 0;
		num2 = 0;
		while (j < 5)
		{
			if (mas1[i][j] < 0) 
				num2 = 1 + num2;
			++j;
		}
		if (num2 > num1)
		{
			num1 = num2;
			line = i;
		}
		++i;
	}
	// поиск столбца с наиб колвом положит элементов
	num1 = 0;
	j = 0;
	col = 0;
	while (j < 5)
	{
		i = 0;
		num2 = 0;
		while (i < 5)
		{
			if (mas1[i][j] > 0)
				num2 = 1 + num2;
			++i;
		}
		if (num2 > num1)
		{
			num1 = num2;
			col = j;
		}
		++j;
	}

	//вывод новой матрицы
	i = 0;
	while (i < 5)
	{
		if (i == line)
			++i;
		j = 0;
		while (j < 5)
		{
			if (j == col)
				++j;
			printf(" ");
			printf("%4d", mas1[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	printf("\n");
	printf("была удалена строка с номером %d", line+1);
	printf(" и столбец с номером %d", col+1);
	//
}
