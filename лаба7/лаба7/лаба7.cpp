#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int outlist(int, struct Tstudent[20]);
int editlist(int, struct Tstudent[20]);
int delist(int, struct Tstudent[20]);
int addlist(int, struct Tstudent[20]);

struct Tstudent
{
	int numgr;
	float attnum;
	char surname[20];
}student[20];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i,k, flag, tempint, numstrf, numstr, newnumstr;
	double tempfl;
	FILE* f;
	char str[36], tempstr[20];
	
	f = fopen("e:\\яп\\лаба7\\myfile.txt", "r");
	//загрузка списка из файла
	numstrf=0;
	newnumstr = 0;
	fgets(str, 36, f);
	numstrf = atoi(str);
	numstr = 0;
	while (numstr<numstrf)
	{
		fgets(str, 36, f);
		flag = 1;
		i = 1;
		while (i < 36 and str[i] != '\n' and str[i] != '\0')
		{
			k = 0;
			if (str[i] != ' ')
			{
				switch (flag)
				{
								
					case 1:
					while (str[i] != ' ')
					{
						tempstr[k] = str[i];
						i++;
						k++;
					}
					tempstr[k] = '\0';
					tempint = atoi(tempstr);
					student[numstr].numgr = tempint;
					flag = 2;
					break;

					case 2:
					while (str[i] != ' ')
					{
						tempstr[k] = str[i];
						i++;
						k++;
					}
					
					tempstr[k] = '\0';
					tempfl = atof(tempstr);
					student[numstr].attnum = tempfl;
					flag = 3;
					break;

					case 3:
					while (str[i] != ' ' and str[i] != '\n')
					{
						tempstr[k] = str[i];
						i++;
						k++;
					}
					
					tempstr[k] = '\0';
					k = 0;
					while (tempstr[k] != '\0')
					{
						student[numstr].surname[k] = tempstr[k];
						k++;
					}
					flag = 1;
					student[numstr].surname[k] = '\0';
					numstr++;
					break;
				}
			}
			i++;
		}
	}
	fclose(f);

	//вывод списка на экран
	outlist(numstrf, student);

	//список операций
	k = 0;
	newnumstr = numstrf;
	//addlist(numstr, student);
	while (k != 5)
	{
		printf("Выберите операцию: \n 1)Вывод списка данных \n 2)Редактировать список \n 3)Добавить новый элемент в список\n 4)Удалить элемент списка\n 5)Сохранить и выйти\n");
		scanf("%d", &k);
		switch (k)
		{
		case 1: newnumstr=outlist(numstrf, student);
			break;
		case 2: newnumstr=editlist(numstrf, student);
			break;
		case 3: newnumstr=addlist(numstrf, student);
			break;
		case 4:	newnumstr=delist(numstrf, student);
			break;
		case 5: break;
		default:
			printf("Операция отсутсвует \n");	
		}
		numstrf = newnumstr;
	}
	//сохранение списка в файл и закрытие работы
	f = fopen("e:\\яп\\лаба7\\myfile.txt", "w");
	i = 0;
	fprintf(f, "%d\n", numstrf);
	while (i < numstrf)
	{
		fprintf(f," %6d %2.2f %s\n", student[i].numgr, student[i].attnum, student[i].surname);
		i++;
	}
	fclose(f);
}
	
	
	
	//вывод списка на экран
	int outlist(int numstr, struct Tstudent student[20])
	{
		int i;
		i = 0;
		while (i < numstr)
		{
			printf("%2d %6d %2.2f %s\n", (i+1), student[i].numgr, student[i].attnum, student[i].surname);
			i++;
		}
		if (i == 0)
			printf("Список пуст\n");
		return numstr;
	}

	//редактирование списка
	int editlist(int numstr, struct Tstudent student[20])
	{
		int k = 0, tempnum = 0;
		float i = 0;
		char tempstr[20];
		printf("Введите номер редактируемой записи \n");
		scanf("%d", &tempnum);
		tempnum--;
		printf("Введите номер группы \n");
		scanf("%d", &k);
		student[tempnum].numgr = k;
		printf("Введите среднее значение за сессию \n");
		scanf("%f", &i);
		student[tempnum].attnum = i;
		printf("Введите фамилию \n");
		scanf("%s", tempstr);
		k = 0;
		while (tempstr[k] != '\0')
		{
			student[tempnum].surname[k] = tempstr[k];
			k++;
		}
		student[numstr].surname[k] = '\0';
		return numstr;
	}


	//добавление
	int addlist(int numstr, struct Tstudent student[20])
	{
		int k = 0;
		float i = 0;
		char tempstr[20];
		printf("Введите номер группы \n");
		scanf("%d", &k);
		student[numstr].numgr = k;
		printf("Введите среднее значение за сессию \n");
		scanf("%f", &i);
		student[numstr].attnum = i;
		printf("Введите фамилию \n");
		scanf("%s", tempstr);
		k = 0;
		while (tempstr[k] != '\0')
		{
			student[numstr].surname[k] = tempstr[k];
			k++;
		}
		student[numstr].surname[k] = '\0';
		numstr++;
		return numstr;
	}

	//удаление 
	int delist(int numstr, struct Tstudent student[20])
	{
		int i = 0, k = 0;
		printf("Введите номер удаляемой записи \n");
		scanf("%d", &k);
		i = k;
		while (i < numstr)
		{
			student[i - 1] = student[i];
			i++;
		}
		numstr--;
		return numstr;
	}
