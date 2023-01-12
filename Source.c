#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX (100)
#define ERROR (-1)

struct grad;
typedef struct grad* pozg;
typedef struct grad {
	char imeg[MAX];
	int brstan;
}grad;

struct drzava;
typedef struct drzava* pozd;
typedef struct drzava {
	char imed[MAX];
	pozd next;
	pozg root;
}drzava;

int Citadat(pozd);
int UnosSort(pozd p, char ime);

int main()
{
	drzava head;
	head.next = NULL;
	Citadat(&head);


	return 0;
}

int Citadat(pozd p) 
{
	char n[MAX];
	FILE* fp = NULL;
	fp = fopen("drzava.txt", "r");
	if (fp == NULL)
	{
		printf("Datoteka se nije otvorila!\n");
		return ERROR;
	}
	
	while (fscanf(fp, "%s",n ) > 0) {
		UnosSort(p, n);
	}
	fclose(fp);
	return 0;
} 

int UnosSort(pozd p, char name) {
	pozd q = NULL;
	q = malloc(sizeof(drzava));
	if (q == NULL) {
		printf("Neuspjesna alokacija memorije!");
		return ERROR;
	}
	q->imed = name;
	while (p->next != NULL && p->next->imed > name) {
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	return 0;
}