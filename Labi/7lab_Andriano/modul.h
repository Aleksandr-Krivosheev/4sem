#ifndef Header_h
#define Header_h
#include <iostream>

struct TStud 
{
public:
	char F[30], I[30], O[30],NomerTell[16];
};
char* ANSIUpperCase(char* s, char* S);
void CreateBinaryFile(int argc, char* argv[]);
void Find(int argc, char* argv[]);
void ViewFile(int argc, char* argv[]);
void CorrectFile(int argc, char* argv[]);
#endif 
