// задача 17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int i;
	float temp, sum;

	i = 1;
	sum = 0;
	while (i <= 50)
	{
		temp = pow(i, 3);
		sum = sum + (1 / temp);
		++i;
	}
	printf("конечная сумма равна %f", sum);
	return 0;
}
