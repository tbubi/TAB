#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR (-1)
#define MAX_ID_LENGTH (64)
#define MAX_NAME_LENGTH (64)
#define MAX_FILE_NAME (64)

struct _visit;
typedef struct _visit* VisitP;
typedef struct _visit {
	char userId[MAX_ID_LENGTH];
	int year;
	int month;
	int day;
	VisitP next;
}Visit;

struct _membership;
typedef struct _membership* MembershipP;
typedef struct _membership {
	char userId[MAX_ID_LENGTH];
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	int month;
	int year;
	int price;
	VisitP visits;
	MembershipP next;
}Membership;

int CitaDat1(MembershipP p);
int Unos(MembershipP p, char id[], char ime[], char prez[], int mis, int god, int cij);
int Ispis(MembershipP p);
int Brisi(MembershipP p);
int DateCmp(year1, year2, month1, month2);
int CitaDat2(VisitP p);
//int Unos2(VisitP p, char id[], int dan, int mis, int god);
//int Ispis2(MembershipP p);

int main() {
	Membership Head;
	Head.next = NULL;
	Visit head;
	head.next = NULL;
	CitaDat1(&Head);
	Ispis(Head.next);
	CitaDat2(&head);
	Brisi(&Head);
	return 0;
}

int CitaDat1(MembershipP p) {
	char datoteka[MAX_FILE_NAME] = { 0 };
	char id[MAX_ID_LENGTH] = { 0 };
	char ime[MAX_NAME_LENGTH] = { 0 };
	char prez[MAX_NAME_LENGTH] = { 0 };
	int god = 0;
	int mis = 0;
	int cij = 0;
	printf("Unesite ime datoteke:\n");
	scanf("%s", datoteka);
	printf("\n");
	FILE* fp = NULL;
	fp = fopen(datoteka, "r");
	if (fp == NULL) {
		printf("Datoteka se nije otvorila!\n");
		return ERROR;
	}
	while (fscanf(fp, "%s %s %s %d %d %d",id, ime, prez, &mis, &god, &cij) > 0) {
		Unos(p, id, ime, prez, mis, god, cij);
	}
	fclose(fp);
	return 0;
}

int Unos(MembershipP p, char id[], char ime[], char prez[], int mis, int god, int cij) {
	MembershipP q = NULL;
	q = (MembershipP)malloc(sizeof(Membership));
	if (q == NULL) {
		printf("Neuspjesna alokacija memorije!");
		return ERROR;
	}
	strcpy(q->userId, id);
	strcpy(q->firstName, ime);
	strcpy(q->lastName, prez);
	q->month = mis;
	q->year = god;
	q->price = cij;
	while (p->next != NULL && DateCmp(p->next->year, q->year, p->next->month, q->month) < 0) {
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	return 0;
}

int Ispis(MembershipP p) {
	if (p == NULL) {
		printf("Prazna datoteka!\n");
	}
	while (p != NULL) {
		printf("%s %s %s %d%d %d\n", p->userId, p->firstName, p->lastName, p->month, p->year, p->price);
		p = p->next;
	}
	printf("\n");
	return 0;
}

int Brisi(MembershipP p) {
	MembershipP temp;
	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	return 0;
}

int DateCmp(year1, year2, month1, month2) {
	int rez;
	rez = year1 - year2;
	if (rez == 0) {
		rez = month2 - month1;
	}
	return rez;
}

int CitaDat2(VisitP p) {
	char datoteka[MAX_FILE_NAME] = { 0 };
	char id[MAX_ID_LENGTH] = { 0 };
	int god = 0;
	int mis = 0;
	int dan = 0;
	printf("Unesite ime datoteke:\n");
	scanf("%s", datoteka);
	printf("\n");
	FILE* fp = NULL;
	fp = fopen(datoteka, "r");
	if (fp == NULL) {
		printf("Datoteka se nije otvorila!\n");
		return ERROR;
	}
	while (fscanf(fp, "%s %d %d %d", id, &dan, &mis, &god) > 0) {
		//Unos2(p, id, dan, mis, god);
	}
	fclose(fp);
	return 0;
}

/*int Unos2(VisitP p, char id[], int dan, int mis, int god) {
	VisitP q = NULL;
	q = (VisitP)malloc(sizeof(Visit));
	if (q == NULL) {
		printf("Neuspjesna alokacija memorije!");
		return ERROR;
	}
	MembershipP qq = NULL;
	qq = (MembershipP)malloc(sizeof(Membership));
	if (qq == NULL) {
		printf("Neuspjesna alokacija memorije!");
		return ERROR;
	}
	if (strcmp(q->userId, qq->userId) == 0 && q->month - qq->month == 0) {
		while (p->next != NULL && p->next->day < dan) {
			p = p->next;
		}
	}
	q->next = p->next;
	p->next = q;
	return 0;
}*/