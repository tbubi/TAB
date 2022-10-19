#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_DIDNT_OPEN_ERROR (-1)
#define MAX_LINE (1024)
#define MAX_FILE_NAME (256)

int prebroji(char* datoteka);
int main()
{
	char datoteka[MAX_FILE_NAME] = {0};
	printf("Unesi ime datoteke: ");
	scanf(" %s", datoteka);

	printf("Broj studenata u datoteci %s je %d",datoteka,prebroji(datoteka));

	return 0;
}

int prebroji(char* datoteka)
{
	FILE* fp = NULL;
	int broji = 0;
	char buffer[MAX_LINE] = {0};

	fp = fopen(datoteka, "r");
	if (fp == NULL)
	{
		printf("Datoteka %s se nije otvorila!\n",datoteka);
		return FILE_DIDNT_OPEN_ERROR;
	}
	while (!feof(fp))
	{
		if (strcmp("\n", buffer) != 0)
		{
			broji++;
		}
	}
	fclose(fp);
	return broji;
}


