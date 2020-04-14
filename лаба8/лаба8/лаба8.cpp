#define _CRT_SECURE_NO_WARNINGS
//слияние двух стеков в один сортированный по возрастанию/убыванию
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void CreateList(struct TList*);

struct TList
{
	int num;
	struct TList* next;
};

struct TList head1,  head2,  head;
struct TList *temp1, *temp2;
struct TList tempEL;
struct TList *tempP;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// создаем первый список с числами 1 3 5 7 9
	tempP = (struct TList *)malloc(sizeof(struct TList));
	head1.next = tempP;
	tempP->num = 1;
	tempP->next=(struct TList*)malloc(sizeof(struct TList));
	tempP=tempP->next;
	tempP->num = 3;
	tempP->next = (struct TList*)malloc(sizeof(struct TList));
	tempP = tempP->next;
	tempP->num = 5;
	tempP->next = (struct TList*)malloc(sizeof(struct TList));
	tempP = tempP->next;
	tempP->num = 7;
	tempP->next = (struct TList*)malloc(sizeof(struct TList));
	tempP = tempP->next;
	tempP->num = 9;
	tempP->next = NULL;

	// создаем второй список с числами 2 4 6 8
	tempP = (struct TList*)malloc(sizeof(struct TList));
	head2.next = tempP;
	tempP->num = 2;
	tempP->next = (struct TList*)malloc(sizeof(struct TList));
	tempP = tempP->next;
	tempP->num = 4;
	tempP->next = (struct TList*)malloc(sizeof(struct TList));
	tempP = tempP->next;
	tempP->num = 6;
	tempP->next = (struct TList*)malloc(sizeof(struct TList));
	tempP = tempP->next;
	tempP->num = 8;
	tempP->next = NULL;

	// создаем третий список
	temp1 = head1.next;
	temp2 = head2.next;
	head.next = NULL;
	CreateList(&head);

	//печать списка
	tempP = head.next;
	while (tempP != NULL)
	{
		printf("%d ", tempP->num);
		tempP = tempP->next;
	}
}

void CreateList(struct TList* exEl)
{
	while (temp1 != NULL or temp2 != NULL)
	{ 
		tempP = (struct TList*)malloc(sizeof(struct TList));
		if (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->num < temp2->num)
			{
				tempP->num = temp1->num;
				temp1 = temp1->next;
			}
			else
			{
				tempP->num = temp2->num;
				temp2 = temp2->next;
			}
		}
		else
		{ 
			if (temp1 != NULL)
			{
				tempP->num = temp1->num;
				temp1 = temp1->next;
			}
			if (temp2 != NULL)
			{
				tempP->num = temp2->num;
				temp2 = temp2->next;
			}
		}
		if (exEl->next==NULL)
		{
	
			exEl->next = tempP;
			tempP->next = NULL;
		}
		else
		{
			tempP->next = exEl->next;
			exEl->next = tempP;
		}
    }
}



