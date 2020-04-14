#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct TTree* CreateTree(struct TTree*, char*);
struct TTree* OutPol(struct TTree*);


struct TTree
{
	char smth;
	struct TTree* right;
	struct TTree* left;
};

struct TTree* start, *myP;
char str[] = "p*(d+g+h/c+t*j)";
char tempstr[16];
struct TTree* tempL, * tempR, * tempP;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	strcpy(tempstr, str);
	start = (struct TTree*)malloc(sizeof(struct TTree));
	myP=CreateTree(start, tempstr);
	OutPol(myP);

}

struct TTree* CreateTree(struct TTree* head, char* tempstr)
{
	struct TTree* tempP, * newTemp, *p;
	char otherstr[16];
	int j, minN, n, len;
	len = strlen(tempstr);
	tempP = head;
	n = 0;
	minN = 0;
	for (int i = 0; i < len; i++)
	{
		if (tempstr[i] > 'a' and tempstr[i] < 'z')
		{
			tempP->smth = tempstr[i];
			newTemp = (struct TTree*)malloc(sizeof(struct TTree));
			n--;
			if (n < minN)
			{
				minN = n;
				head = newTemp;
			}
			tempP->left = NULL;
			tempP->right = NULL;
			newTemp->left = tempP;
			tempP = newTemp;
		}
		if (tempstr[i] == '+' or tempstr[i] == '-')
		{
			tempP->smth = tempstr[i];
			if (i + 2 < len)
			{
				if (tempstr[i + 2] == '+' or tempstr[i + 2] == '-')
				{
					tempP->right = (struct TTree*)malloc(sizeof(struct TTree));
					i++;
					n++;


					tempP->right->smth = tempstr[i];
					n--;


					newTemp = (struct TTree*)malloc(sizeof(struct TTree));
					newTemp->left = tempP;
					head = newTemp;

					if (n < minN)
					{
						minN = n;
						head = newTemp;
					}
					tempP->right->left = NULL;
					tempP->right->right = NULL;


					tempP = newTemp;
				}
				else
				{
					i++;
					n++;
					newTemp = (struct TTree*)malloc(sizeof(struct TTree));
					tempP->right = newTemp;
					newTemp->left = NULL;
					tempP = newTemp;
				}
			}
		}
		if (tempstr[i] == '*' or tempstr[i] == '/')
		{
			tempP->smth = tempstr[i];
			if (tempstr[i + 1] == '(')
			{
				j = 0;
				i++;
				i++;
				while (tempstr[i] != ')')
				{
					otherstr[j] = tempstr[i];
					i++;
					j++;
				}
				otherstr[j] = '\0';
				n++;
				newTemp = (struct TTree*)malloc(sizeof(struct TTree));
				p=CreateTree(newTemp, otherstr);
				newTemp = p;
				tempP->right = newTemp;
			}
			else
			{
				if (tempP->left == NULL)
				{
					tempP->left = (struct TTree*)malloc(sizeof(struct TTree));
					tempP->left->smth = tempstr[i - 1];
					tempP->left->left = NULL;
					tempP->left->right = NULL;
				}
				tempP->right = (struct TTree*)malloc(sizeof(struct TTree));
				i++;
				tempP->right->smth = tempstr[i];
				tempP->right->right = NULL;
				tempP->right->left = NULL;

				if (head->right == tempP && (i + 1) < len)
				{
					newTemp = (struct TTree*)malloc(sizeof(struct TTree));
					newTemp->left = head;
					head = newTemp;
					tempP = newTemp;
				}
			}
		}
	}
	return head;
}

struct TTree* OutPol(struct TTree* head)
{
	struct TTree* newP, *p;
	printf("%c", head->smth);
	while (head->left != NULL || head->right != NULL)
	{
		if (head->left != NULL)
		{
			newP = head->left;
			p = OutPol(newP);
			newP = p;
			head->left = newP;
		}
		else
		{
			newP = head->right;
			p= OutPol(newP);
			newP = p;
			head->right = newP;
		}
	}
	if (head->left == NULL || head->right == NULL)
	{
		free(head);
		head = NULL;
	}
	return head;
}