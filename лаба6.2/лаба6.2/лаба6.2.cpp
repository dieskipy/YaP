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

	char basicstr[] = " 3 4 -5 -6 20 -9 -10 3";
	int j, k,myattint;
	FILE* f,  * l;
	char str[30];
	char myatt[5] = "0000";

	f = fopen("e:\\яп\\лаба6.2\\myfile.txt", "w");
	fprintf(f, "%s", basicstr);
	fclose(f);
	f = fopen("e:\\яп\\лаба6.2\\myfile.txt", "r");
	l = fopen("e:\\яп\\лаба6.2\\newfile.txt", "w");

	j = 0;
	fgets(str, 30, f);
	while (str[j] != '\0')
	{
		if (str[j] != ' ')
		{
			k = 0;
			for (int m = 0; m < 5; m++)
					myatt[m] = { 0 };
			while (str[j] != '\0' and str[j] != ' ' and k<5)
			{
				myatt[k] = str[j];
				k++;
				j++;
			}
		}
		myattint = atoi(myatt);
		if (myattint > 0)
			fprintf(l, "%d ", myattint);
		j++;
	}
	fclose(l);
	fclose(f);
	return 0;
}
