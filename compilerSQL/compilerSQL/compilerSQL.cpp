#include <regex>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <Windows.h>

//необходимо задать файл E:/code.txt который используется для проверки!
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int fAlter = 0, fAdd = 0, f=1, k=0, fErr=1;
	
	std::regex regularDATABASE("([ ]*(CREATE|DROP)[ ]+DATABASE[ ]+[\\w]+;)");
	std::regex regularUSE("([ ]*USE[ ]+[\\w]+)");
	std::regex regularEXPLAIN("([ ]*EXPLAIN[ ]+[\\w]+)");
	std::regex regularCREATE("([ ]*CREATE[ ]+TABLE[ ]+[\\w]+[ ]+[(]([ ]*[\\w]+[ ]+[\\w]+[,]?)+[)][;])");
	std::regex regularDROP("([ ]*DROP[ ]+TABLE[ ]+[\\w]+;)");
	std::regex regularALTER("([ ]*ALTER[ ]+TABLE[ ]+[\\w]+)");
	std::regex regularADD("([ ]*ALTER[ ]+[\\w]+[ ]+[\\w]+)");
	std::regex regularAFTER("([ ]*AFTER[ ]+[\\w]+;)");
	std::regex regularALTERDROP("([ ]*DROP[ ]+[\\w]+;)");
	std::regex regularSHOW("([ ]*SHOW[ ]+(TABLES|DATABASES);)");


	string str;
	std::fstream code("E:\\code.txt");
	while (code)
	{
		getline(code, str);
		k++;
		f = 0;
		if (fAlter == 0)
		{
			if (fAdd == 0)
			{
				if (regex_match(str.c_str(), regularDATABASE))
					f = 1;
				if (regex_match(str.c_str(), regularUSE))
					f = 1;
				if (regex_match(str.c_str(), regularEXPLAIN))
					f = 1;
				if (regex_match(str.c_str(), regularCREATE))
					f = 1;
				if (regex_match(str.c_str(), regularDROP))
					f = 1;
				if (regex_match(str.c_str(), regularSHOW))
					f = 1;
				if (regex_match(str.c_str(), regularALTER))
				{
					f = 1;
					fAlter = 1;
				}
			}
			else
			{
				if (regex_match(str.c_str(), regularAFTER))
				{
					f = 1;
					fAdd = 0;
				}
			}
		}
		else
		{
			if (regex_match(str.c_str(), regularADD))
				f = 1;
			if (regex_match(str.c_str(), regularALTERDROP))
				f = 1;
			if (f == 1)
				fAlter = 0;
		}
		if (f == 0)
		{
			printf("Ошибка в строке %d \n", k);
			fErr = 0;
		}
	}
	printf("Анализ окончен. ");
	if (fErr == 1)
	{
		printf("Ошибок не обнаружено!");
	}
	//берем строку и ищем на регулярки кроме alter add afterdrop after
	//если соотв изначальным то все ок и идем дальше берем новую строку
	//если нет то чекаем была ли предыдущая строка alter или add
	// усли была alter чекаем на add drop
	// если была add чекаем на after;
	// если не было ни alter ни add то кидаем на проверку на alter;
	// если не подошло то выдаем ошибку в строке и завершаем работу

}
