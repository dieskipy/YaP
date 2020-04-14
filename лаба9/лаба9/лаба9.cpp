//структура дерево, вводится уровень дерева (при корне уровень =0) и нужно вывести сколько есть компонент на этом уровне
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void CreateTree(struct TTree*);
void OutTree(struct TTree*);
void GetMyNum(int);

struct TTree
{
	int num;
	struct TTree* right;
	struct TTree* left;
};

struct TTree head;
int nums[] = {34, 14, 17, 5, 6, 3, 56, 43, 13, 7, 9, 12};
int len, i;
int NumLev;
struct TTree* tempL, * tempR, * tempP;
struct TTree* massP[50];


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	len = (sizeof(nums) / sizeof(int));
	CreateTree(&head);
	OutTree(&head);
	printf("Введите номер уровня дерева\n");
	scanf("%d", &i);
	if (i > NumLev)
		printf("Такого уровня нет, максимальный уровень с номером %d \n", NumLev);
	else
		GetMyNum(i);
	return 0;
}

void CreateTree(struct TTree* root)
{
	int i,n;
	
	root->num = nums[0];
	
	tempP = root;
	tempP->num = nums[0];
	massP[0] = root;
	n = 0;
	i = 1;
	while (i<len)
	{
		tempP->left = (struct TTree*)malloc(sizeof(struct TTree));
		tempL = tempP->left;
		tempL->num = nums[i];
		massP[n * 2 + 1] = tempL;
		i++;
		if (i < len)
		{
			tempP->right=(struct TTree*)malloc(sizeof(struct TTree));
			tempR = tempP->right;
			tempR->num = nums[i];
			massP[n * 2 + 2] = tempR;
			i++;
		}
		n++;
		tempP = massP[n];
	}
	if (len % 2 == 0)
	{
		for (int j = len / 2; j < len; j++)
		{
			massP[j]->left = NULL;
			massP[j]->right = NULL;
		}
	}
	else
	{
		i = (len - 1) / 2;
		massP[i]->right = NULL;
		for (int j = (len+1) / 2; j < len; j++)
		{
			massP[j]->left = NULL;
			massP[j]->right = NULL;
		}
	}
}


void OutTree(struct TTree* root)
{
	int n, i, j, sum;
	i = 0;
	sum = 0;
	while (sum < len)
	{
		sum = sum + pow(2, i);
		i++;
	}
	NumLev = i - 1;
	i = 0;
	j = 0;
	while (i < len)
	{
		n = pow(2, j);
		for (int m = 0; m < n; m++)
		{
			if (i < len)
			{
				printf("%3d ", massP[i]->num);
				i++;
			}
			else
				break;
		}
		printf("\n");
		j++;
	}
}
void GetMyNum(int Num)
{
	int sum, othersum;
	sum = 0;
	for (int i = 0; i <= Num; i++)
	{
		sum = sum + pow(2, i);
	}
	if (sum <= len)
	{
		othersum = sum;
		sum = 0;
		for (int i = 0; i < Num; i++)
		{
			sum = sum + pow(2, i);
		}
		printf("Количество вершин на данном уровне %d равно %d", Num, (othersum - sum));
	}
	else
	{
		sum = 0;
		for (int i = 0; i < Num; i++)
		{
			sum = sum + pow(2, i);
		}
		printf("Количество вершин на данном уровне %d равно %d", Num, (len- sum));
	}
}