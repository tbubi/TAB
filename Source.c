#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX (30)
typedef struct osoba* head;
typedef struct {
    char ime[MAX];
    char prezime[MAX];
    int godina;
    struct osoba* next;
}osoba;
osoba* Lista(int n);
void Ispis(osoba* head);
void UnosP(osoba* head, char [], char [], int);
void UnosK(osoba* head, char [], char [], int);
head Trazi(osoba* head, char [], char [], int);
void Brisi(osoba* head, char [], char [], int);
int main() {
    int n = 0;
    int izbor1 = 0, izbor2 = 0;
    char ime[MAX], prezime[MAX];
    int godina = 0;
    osoba* HEAD = NULL;
    printf("Koliko osoba zelite unijeti? ");
    scanf("%d", &n);
    if (n == 0)
        printf("\nLista je prazna.");
    printf("\n");
    HEAD = Lista(n);
    Ispis(HEAD);
    do {
            printf("\nZelte li raditi nesto sa listom?");
            printf("\nUnesite broj 1 za odgovor DA");
            printf("\nUnesite broj 2 za odgovor NE\n");
            printf("\nUnesite broj: ");
            scanf("%d", &izbor1);
            if (izbor1 == 1) {
                printf("\nIzaberite sto zelite napraviti:\n");
                printf("Unesite broj 1 za dodavanje osobe na pocetak liste\n");
                printf("Unesite broj 2 za dodavanje osobe na kraj liste\n");
                printf("Unesite broj 3 za trazenje osobe u listi(po prezimenu)\n");
                printf("Unesite broj 4 za brisanje osobe iz liste\n");
                printf("Unesite broj 5 za ispis liste\n");
                printf("\nUnesite broj: ");
                scanf("%d", &izbor2);
                printf("\n");
                if (izbor2 == 1) {
                    printf("Unesite ime osobe: ");
                    scanf("%s", &ime);
                    printf("Unesite prezime osobe: ");
                    scanf("%s", &prezime);
                    printf("Unesite godinu rodenja osobe: ");
                    scanf("%d", &godina);
                    UnosP(&HEAD, ime, prezime, godina);
                }
                if (izbor2 == 2) {
                    printf("Unesite ime osobe: ");
                    scanf("%s", &ime);
                    printf("Unesite prezime osobe: ");
                    scanf("%s", &prezime);
                    printf("Unesite godinu rodenja osobe: ");
                    scanf("%d", &godina);
                    UnosK(&HEAD, ime, prezime, godina);
                }
                if (izbor2 == 3) {
                    printf("Unesite prezime osobe: ");
                    scanf("%s", &prezime);
                    printf("Osoba se nalazi na poziciji: ", Trazi(&HEAD, ime, prezime, godina));
                }
                if (izbor2 == 4) {
                    printf("Unesite ime osobe: ");
                    scanf("%s", &ime);
                    printf("Unesite prezime osobe: ");
                    scanf("%s", &prezime);
                    printf("Unesite godinu rodenja osobe: ");
                    scanf("%d", &godina);
                    Brisi(&HEAD, ime, prezime, godina);
                }
                if (izbor2 == 5) {
                    Ispis(HEAD);
                }
            }
    } while (izbor1 == 1);
    return 0;
}
osoba* Lista(int n) {
    int i = 0;
    osoba* head = NULL;
    osoba* temp = NULL;
    osoba* p = NULL;
    for (i = 0; i < n; i++) {
        temp = (osoba*)malloc(sizeof(osoba));
        printf("Ime %d. osobe: ", i + 1);
        scanf("%s", &(temp->ime));
        printf("Prezime %d. osobe: ", i + 1);
        scanf("%s", &(temp->prezime));
        printf("Godina rodenja %d. osobe: ", i + 1);
        scanf("%d", &(temp->godina));
        printf("\n");
        temp->next = NULL;
        if (head == NULL)
            head = temp;
        else {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return head;
}
void Ispis(osoba* head) {
    osoba* p = head;
    while (p != NULL) {
        printf("%s %s %d\n", p->ime, p->prezime, p->godina);
        p = p->next;
    }
}
void UnosP(osoba* head, char name[], char surname[], int year) {
    osoba* head1 = (osoba*)malloc(sizeof(osoba));
    strcpy(head1->ime, name);
    strcpy(head1->prezime, surname);
    head1->godina = year;
    head1->next = head->next;
    head->next = head1;
}
void UnosK(osoba* head, char name[], char surname[], int year) {
    while (head->next != NULL)
        head = head->next;
    osoba* head1 = (osoba*)malloc(sizeof(osoba));
    strcpy(head1->ime, name);
    strcpy(head1->prezime, surname);
    head1->godina = year;
    head->next = head1;
    head1->next = NULL;
}
head Trazi(osoba* head, char name[], char surname[], int year) {
    while (head != NULL && head->prezime != surname)
        head = head->next;
    return head;
}
void Brisi(osoba* head, char name[], char surname[], int year) {
    
}
