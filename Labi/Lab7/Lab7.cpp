//---------------------------------------------------------------------------
#include <conio.h>  // getch
#include <stdio.h>  // FILE, fgets, fscanf, fflush
#include <string.h>  // strchr, strlen
//---------------------------------------------------------------------------
int main()
{  // stdin – стандартный текстовый файл (клавиатура), иначе подставьте 
    // другое имя  переменной (дескриптор своего открытого файла), например, f, если FILE* f;

	char Fam[31];   // сюда введем одно слово не длиннее 30 символов
	printf("Fam =?");
	fscanf(stdin, "%30s", Fam); // stdin – стандартный текстовый файл (клавиатура) 

	fflush(stdin);  // если строка была длиннее, остаток удаляем из буфера, 
 					// если его не удалить – перейдет в следующий ввод
	printf("Vvedeno '%s'\n", Fam);

	char FamIO[61]; // сюда введем несколько  слов не длиннее 60 символов
	char *n;  // позиция спец.символа (конца строки) в введенной строке
	printf("FamIO =?");
	fgets(FamIO,60,stdin); // stdin – стандартный текстовый файл (клавиатура), иначе другое имя

	fflush(stdin);  // если строка была длиннее, остаток удаляем из буфера, а если короче:
	n = strchr(FamIO, '\n'); if (n) FamIO[n-FamIO]='\0';    // укорачиваем

	printf("Vvedeno '%s'\n", FamIO);

	//printf("Press any key");
 	getch();
	return 0;
} 