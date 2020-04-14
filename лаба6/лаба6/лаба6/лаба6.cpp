
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct dved
	{
		char name[20];
		char att[5];
	};

	struct dved ved[5] = { {"Котик ", "3.8"}, {"Мурзик ", "3.6"}, {"Пушок ","7.8"},{"Булка ","3.3"},{"Дружок","9.5"} };
	struct dved tempv;
	int j, k, m;
	double myattint;
	FILE *f, *q, *l;
	char str[25], myatt[5];

	boolean flag;


	f=fopen("e:\\яп\\лаба6\\лаба6\\myfile.txt", "w");
	for (int i = 0; i < 5; i++)
	{
		fprintf(f, "%s %s\n", ved[i].name, ved[i].att);
	}
	fclose(f);
	f = fopen("e:\\яп\\лаба6\\лаба6\\myfile.txt", "r");
	q = fopen("e:\\яп\\лаба6\\лаба6\\newfile.txt", "w");
	l = fopen("e:\\яп\\лаба6\\лаба6\\BASICfile.txt", "w");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 25; j++)
			str[j] = { 0 };
		for (int j = 0; j < 5; j++)
			myatt[j] = { 0 };
		flag = false;
		fgets(str, 25, f);
		j = 0;
		while (not flag and j < 25)
		{
			if (str[j+1] != ' ' and str[j] == ' ')
			{
				flag = true;
				k = 0;
				m = j + 1;
				while (str[m]!='\n' and j < 25)
				{ 
					myatt[k] = str[m];
					k++;
					m++;
				}
			}
			j++;
		}
		myattint = atof(myatt);
		if (myattint < 4)
			fprintf(q, "%s\n", str);
		else
			fprintf(l, "%s\n", str);	
	}
	fclose(f);
	f = fopen("e:\\яп\\лаба6\\лаба6\\myfile.txt", "w");
	fclose(l);
	l = fopen("e:\\яп\\лаба6\\лаба6\\BASICfile.txt", "r");
	while (not feof(l))
	{
		for (int j = 0; j < 25; j++)
			str[j] = { 0 };
		fgets(str, 25, l);
		fprintf(f, "%s\n", str);
	}
	fclose(l);
	fclose(q);
	fclose(f);
	remove("e:\\яп\\лаба6\\лаба6\\BASICfile.txt");
	return 0;
}