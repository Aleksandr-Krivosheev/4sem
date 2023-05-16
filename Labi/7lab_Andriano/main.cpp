#include "modul.h"

int main(int argc, char* argv[])
{
	char ch;
	do {
		printf("Ваш выбор?\n"
			"N - создать новый тип.файл;\n" 
			"F - сразу поиск;\n"
			"V - просмотр\n"
			"C - коррекция; \n"
			"E - конец.\n");
		ch = getchar(); fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------первая часть: создание двоичного из текстового---------
		case 'N': CreateBinaryFile(argc, argv); break;
			//---------------вторая часть: поиск в двоичном файле--------------
		case 'F': Find(argc, argv); break;
			//-------третья часть: корректировка в двоичном файле--------------
		case 'V': ViewFile(argc, argv); break;
			//-------четвертая часть: просмотр двоичного файла-----------------
		case 'C': CorrectFile(argc, argv); break;
			//-----------выход-------------------------------------------------
		case 'E': return 0;
			//-----------------------------------------------------------------
		default:
			printf("Нет такой команды\nPress any key");	
		}
	ch = getchar();
	} while (ch != 'E');
	return 0;
}
