#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX (30)
typedef struct {
    char ime[MAX];
    char prezime[MAX];
    int godina;
    struct node* next;
}node;
node* createlinkedlist(int n);
void Ispis(node* head);
void UnosP(node*head,char ime,char prezime,int godina);
//void UnosK(node* head, char ime, char prezime, int godina);
//void Trazi(node* head, char ime, char prezime, int godina);
//void Brisi(node* head, char ime, char prezime, int godina);
int main() {
    int n = 0;
    int izbor1, izbor2;
    node* HEAD = NULL;
    printf("Koliko osoba zelite unijeti? ");
    scanf("%d", &n);
    if (n == 0)
        printf("\nLista je prazna.");
    printf("\n");
    HEAD = createlinkedlist(n);
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
                    scanf("%s", &(HEAD->ime));
                    printf("Unesite prezime osobe: ");
                    scanf("%s", &(HEAD->ime));
                    printf("Unesite godinu rodenja osobe: ");
                    scanf("%d", &(HEAD->ime));
                }
                if (izbor2 == 2) {
                    printf("Unesite ime osobe: ");
                    printf("Unesite prezime osobe: ");
                    printf("Unesite godinu rodenja osobe: ");
                }
                if (izbor2 == 3) {
                    printf("Unesite ime osobe: ");
                    printf("Unesite prezime osobe: ");
                    printf("Unesite godinu rodenja osobe: ");
                }
                if (izbor2 == 4) {
                    printf("Unesite ime osobe: ");
                    printf("Unesite prezime osobe: ");
                    printf("Unesite godinu rodenja osobe: ");
                }
                if (izbor2 == 5) {
                    Ispis(HEAD);
                }
            }
    } while (izbor1 == 1);
    return 0;
}
node* createlinkedlist(int n) {
    int i = 0;
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;
    for (i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node));
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
void Ispis(node* head) {
    node* p = head;
    while (p != NULL) {
        printf("%s %s %d\n", p->ime, p->prezime, p->godina);
        p = p->next;
    }
}
void UnosP(node** head, char name,char surname,int year) {
    node* head1 = (node*)malloc(sizeof(node));
    //head1->ime = name;
    //head1->prezime = surname;
    head1->godina = year;
    head1->next = head;
    *head = head1;
}