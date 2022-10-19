#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region Strukture
typedef struct {
	char ime[20];
	char prezime[20];
	int bodoviKolokvij;
}Student;
#pragma endregion

#pragma region Funkcije
int PrebrojiRedove(char* fileName) {
	int cnt = 0;
	char* buffer = malloc(1024);
	FILE* f;
	f = fopen(fileName, "r");
	if (!f)
		printf("Datoteka nije valjana");
	while (1) {
		if (fgets(buffer, 50, f) == '\0')
			break;
		cnt++;
	}
	fclose(f);
	return cnt;
}
void Unos_Ispis(char* fileName, int cnt) {
	int i;
	int bodoviMax;
	FILE* f;
	f = fopen(fileName, "r");
	if (!f)
		printf("Datoteka nije valjana");
	Student* StudentLista;
	StudentLista = (Student*)malloc(cnt * sizeof(Student));
	printf("Unesi maksimalne bodove na kolokviju: ");
	scanf("%d", &bodoviMax);
	for (i = 0; i < cnt; i++)
		fscanf(f, "%s %s %d", StudentLista[i].ime, StudentLista[i].prezime, &StudentLista[i].bodoviKolokvij);
	for (i = 0; i < cnt; i++)
		printf("%-20s\t%-20s\t%-10d\t%0.2f posto\n", StudentLista[i].ime, StudentLista[i].prezime, StudentLista[i].bodoviKolokvij, ((float)(StudentLista[i].bodoviKolokvij) / bodoviMax) * 100);
	fclose(f);
}
#pragma endregion

int main() {
	char fname[20];
	int nmbr;
	printf("Unesi ime datoteke: ");
	scanf("%s", fname);
	nmbr = PrebrojiRedove(fname);
	Unos_Ispis(fname, nmbr);
	return 0;
}