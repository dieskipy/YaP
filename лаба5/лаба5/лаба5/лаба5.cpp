// лаба5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
		char city[20];
		float att;
	};

	struct dved ved[5] = { {"Котик","Минск", 9.8}, {"Мурзик","Брест", 7.6}, {"Пушок","Минск",8.8},{"Булка","Минск",6.3},{"Дружок","Гродно",9.5} };
	struct dved tempv;
	int k;

	//ved[0].name = "Котик";
	//ved[0].city = "Минск";
	//ved[0].att = 9.8;

	//ved[1].name = "Мурзик";
	//ved[1].city = "Брест";
	//ved[1].att = 7.6;

	//ved[2].name = "Пушок";
	//ved[2].city = "Минск";
	//ved[2].att = 8.8;

	//ved[3].name = "Булка";
	//ved[3].city = "Витебск";
	//ved[3].att = 6.3;

	//ved[4].name = "Дружок";
	//ved[4].city = "Гродно";
	//ved[4].att = 9.5;

	k = 0;
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(ved[i].city, "Минск")==0)
		{
			tempv = ved[k];
			ved[k] = ved[i];
			ved[i] = tempv;
			k++;
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (strcmp(ved[i].name, ved[j].name) > 0)
			{
				tempv = ved[i];
				ved[i] = ved[j];
				ved[j] = tempv;
			}
		}	
	}

	for (int i = 0; i < k; i++)
	{
		puts(ved[i].name);
		printf("   ");
		puts(ved[i].city);
		printf("   ");
		printf("%1.1f\n", ved[i].att);
	}

	printf("В Минске проживает %d студента(ов)", k);
	return 0;
}