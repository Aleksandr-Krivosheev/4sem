#include "modul.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


using namespace std;
//Создание копии строки, но с символами в верхнем регистре
char *ANSIUpperCase(char *s, char *S)
{
	S = strcpy(S, s);
	char *ch = S;
	while (*ch)

	{
		//if (*ch >= 'a' && *ch <= 'z' || *ch >= 'а' && *ch <= 'я') *ch = *ch - 32;
		//if (*ch == 'ё') *ch = 'Ё';
		ch++;
	}
	return S;
}
//Первая часть: создание двоичного из текстового
void CreateBinaryFile(int argc, char *argv[])
{
	printf("%s\n",argv[1]);

	FILE *ft = fopen("1.txt", "rt");
	if (ft == NULL)
	{
		printf("Error: не удалось открыть файл с исходными данными %s\n", argv[2]);
		printf("Press any key ");
		getch();
		return;
	}
	FILE *fb = fopen("2", "wb");
	if (fb == NULL)
	{
		fclose(ft);
		printf("Error: не удалось создать двоичный файл %s\n", argv[1]);
		printf("Press any key");
		getch();
		return;
	}

	TStud Stud;
	int k = 0, nw = 1;
	char s[3], *n;
	while (nw)
	{
		/*fgets(Stud.Gender, 10, ft);
		n = strchr(Stud.Gender, '\n'); if (n) Stud.Gender[n - Stud.Gender] = '\0';
		*/

		fscanf(ft, "%29s", Stud.F);
				if (feof(ft))
			break;
		fscanf(ft, "%29s", Stud.I);
		fscanf(ft, "%29s", Stud.O);
		fscanf(ft, "%29s", Stud.NomerTell);

		nw = fwrite(&Stud, sizeof(Stud), 1, fb);
		k++;
	}
	if (nw != 1)
		printf("Error: Ошибка при записи");

	fclose(ft);
	fclose(fb);

	printf("Создан двоичный файл из %d записей по %ld байт\n", k, sizeof(TStud));
	printf("Press any key to continue\n");
	getch();
	return;
}
//Вторая часть: поиск в двоичном файле
void Find(int argc, char *argv[])
{
	FILE *fb = fopen("2", "rb");
	if (fb == NULL)
	{
		printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
		printf("Press ENTER");
		getch();
		return;
	}

	TStud Stud;
	char s[31];
	int k = 0, nr = 1;
	int i;
	while (nr)
	{
		nr = fread(&Stud, sizeof(Stud), 1, fb);
		if (nr > 0)
			if ((Stud.NomerTell[0] == '3') && (Stud.NomerTell[1] == '6') && (Stud.NomerTell[2] == '1') ||
				(Stud.NomerTell[0] == '3') && (Stud.NomerTell[1] == '6') && (Stud.NomerTell[2] == '2') ||
				(Stud.NomerTell[0] == '2') && (Stud.NomerTell[1] == '7') && (Stud.NomerTell[2] == '3'))

			{
				printf("%-15s\t| %-10s\t| %-10s\t| %-8s \n",
					   Stud.F, Stud.I, Stud.O, Stud.NomerTell);
				k++;
			}
	}
	if (k == 0)
		printf("Данные, соответствующие запросу, не найдены\n");
	else
		printf("Всего найдено: %d\n", k);
	fclose(fb);
	printf("Press any key to continue\n");
	getch();
	return;
}
//Третья часть: корректировка в двоичном файле
void CorrectFile(int argc, char *argv[])
{

	FILE *fb = fopen("2", "rb+");
	if (fb == NULL)
	{
		printf("Error: не удалось открыть двоичный файл %s\n", "2");
		printf("Press ENTER");
		getch();
		return;
	}
	TStud Stud;
	int k = 0, nr = 1, nw = 1, flag, flag1, i, z, d;
	char t[31];
	char s[31] = {'5', '\0'};
	nr = fread(&Stud, sizeof(Stud), 1, fb);
	while (nr == 1 && nw == 1)
	{
		printf("Считана запись:\n");
		printf("%-15s\t| %-10s\t| %-10s\t| %-8s \n",
			   Stud.F, Stud.I, Stud.O, Stud.NomerTell);

		d = 0;
		z = 0;
		flag = 1;
		
		while (d <= strlen(Stud.NomerTell) && Stud.NomerTell[d] != '\0')
		{
			if ((isdigit(Stud.NomerTell[d])))
			{
				z++;
				d++;
			}
			else
			{
				flag = 0;
				Stud.NomerTell[d]= '7';
				fseek(fb,0-sizeof(Stud),SEEK_CUR);
				nw=fwrite(&Stud, sizeof(Stud), 1, fb);
				fseek(fb,0,SEEK_CUR);

			}
			
		}
		if(flag == 0)
		{
			k++;
			printf("Сделана корректировка:\n");
			printf("%-15s\t| %-10s\t| %-10s\t| %-8s \n",
			Stud.F, Stud.I, Stud.O, Stud.NomerTell);	
		}

		flag1 = 1;
		while (5 >= strlen(Stud.NomerTell))
		{
			strcat(Stud.NomerTell, s);
			fseek(fb,0-sizeof(Stud),SEEK_CUR);
			nw=fwrite(&Stud, sizeof(Stud), 1, fb);
			fseek(fb,0,SEEK_CUR);
			flag1 = 0;
		}

		if(flag1 == 0)
		{
			k++;
			printf("Сделана корректировка:\n");
			printf("%-15s\t| %-10s\t| %-10s\t| %-8s \n",
			Stud.F, Stud.I, Stud.O, Stud.NomerTell);	
		}

		nr = fread(&Stud, sizeof(Stud), 1, fb);
	}

	if (k == 0)
		printf("Ни одной корректировки не произведено\n");
	else
		printf("Всего корректировок произведено: %d\n", k);
	fclose(fb);
	printf("Press any key to continue\n");
	getch();
	return;
}

// Просмотр двоичного файла
void ViewFile(int argc, char *argv[])
{
	FILE *fb = fopen("2", "rb");

	if (fb == NULL)
	{
		printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
		return;
	}
	TStud Stud;
	int kol = 0, nr = 1, nw = 1, flag;
	nr = fread(&Stud, sizeof(Stud), 1, fb);
	printf(" F              |       I       |        O      |   Tell \n");
	while (nr == 1 && nw == 1)
	{
		printf("%-15s\t| %-10s\t| %-10s\t| %-8s \n",
			   Stud.F, Stud.I, Stud.O, Stud.NomerTell);
		kol++;
		nr = fread(&Stud, sizeof(Stud), 1, fb);
	}
	if (kol == 0)
		printf("В файле нет ни одной записи\n");
	else
		printf("Показано %d записей\n", kol);
	fclose(fb);
	printf("Press any key to continue\n");
	getch();

	return;
}
