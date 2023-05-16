#include <iostream> 
#include <cstring>

struct TElem {
    char Slovo[31];
    TElem* Next;
};

TElem* NList1 = NULL;
TElem* NList2 = NULL;
TElem* NList3 = NULL;

void perevod_Slovo_31 (char *a, TElem* &b, int len)
{
    for (int i = 0; i < len; i++)
    {
        b -> Slovo[i] = a[i];
    }
    b -> Slovo[len] = '\0';
}

void perevod_Slovo_31_r (TElem* &b, char *a)
{
    for (int i = 0; i < 31; i++)
    {
        if (b -> Slovo[i] != '\0')
            a[i] = b -> Slovo[i];
        else
        {
            a[i] = '\0';
            break;
        }
    }
}

void str_clean_31 (char *a)
{
    for (int i = 0; i < 31; i++)
        a[i] = '\0';
}

void str_cpy_31 (char* a, char* b)
{
    for (int i = 0; i < 31; i++)
        b[i] = a[i];
}

void CreateStack (TElem* &N, char *s)
{
    N = (TElem*)malloc(sizeof(TElem));
    perevod_Slovo_31(s, N, strlen(s));
    N -> Next = NULL;
}

void Push (TElem* &N, char *s)
{
    TElem* new_elem;
    new_elem = (TElem*)malloc(sizeof(TElem));
    new_elem -> Next = N;
    N = new_elem;
    perevod_Slovo_31(s, new_elem, strlen(s));
}

char* Pop (TElem* &N)
{
    TElem *D;
    char *w;
    w = (char*)malloc(sizeof(char));
    D = N -> Next;
    perevod_Slovo_31_r(N, w);
    delete N;
    N = D;
    return w;
}

bool Empty (TElem* N)
{
    if (N == NULL)
        return true;
    else
        return false;
}

void WriteInStack (TElem* &N, FILE* f)
{
    char Slovo[31];
    str_clean_31(Slovo);
    fflush(stdin);
    
    if (N == NULL)
    {
        if (getc(f) != EOF)
        {
            fseek(f, -1, SEEK_CUR);
            fscanf(f, "%31s", Slovo);
            printf("%s", Slovo);
            fflush(stdin);
            CreateStack (N, Slovo);
        }
    }
    
    while (getc(f) != EOF)
    {
        fseek(f, -1, SEEK_CUR);
        fscanf(f, "%31s", Slovo);
        fflush(stdin);
        Push(N, Slovo);
    }
    
    printf("\n----------------------------------------------------\n");
    printf("                   Стек создан.");
    printf("\n----------------------------------------------------\n \n");
}
/*
void WriteInStack_2 (TElem* &N)
{
    char Slovo[31];
    str_clean_31(Slovo);
    fflush(stdin);
    
    if (N == NULL)
    {
        scanf("%31s", Slovo);
        fflush(stdin);
        if (Slovo[0] != '*')
            CreateStack (N, Slovo);
        else
        {
            printf("\n----------------------------------------------------\n");
            printf("                   Стек создан.");
            printf("\n----------------------------------------------------\n \n");
            return;
        }
    }
    
    while (true)
    {
        str_clean_31(Slovo);
        scanf("%31s", Slovo);
        fflush(stdin);
        if (Slovo[0] != '*')
            Push(N, Slovo);
        else
        {
            printf("\n----------------------------------------------------\n");
            printf("                   Стек создан.");
            printf("\n----------------------------------------------------\n \n");
            return;
        }
    }
    
}*/

void vivod(TElem* &N)
{
    
    while (N!=NULL)
    {
        printf("%s\n", N->Slovo);
        printf("%ld\n",strlen(N->Slovo));
        N = N->Next;
    }
}

void Verbose (TElem* &N)
{
    TElem* El;
    El = N;
    char w[31];
    TElem* Pl = NULL;
    
    
    if (N == NULL)
    {
        printf("\n----------------------------------------------------\n");
        printf("                    Стек пустой.");
        printf("\n----------------------------------------------------\n \n");
        return;
    }
    
    //создаём вспомогательный стек
    printf("\n----------------------------------------------------\n");
    char* v = Pop(N);
    str_cpy_31(v, w);
    free(v);
    CreateStack(Pl, w);
    printf("%s\n", w);
    printf("%ld\n",strlen(w));

    while (!Empty(N))
    {
        //делаем то же самое, но теперь добавляем элемент в уже существующий вспомогательный стек
        v = Pop(N);
        str_cpy_31(v, w);
        free(v);
        Push(Pl, w);
        printf("%s\n", w);
        printf("%ld\n",strlen(w));
    }
    printf("----------------------------------------------------\n");
    
    //создаём стек заново, то есть делаем всё то же самое, но в обратном порядке
    v = Pop(Pl);
    str_cpy_31(v, w);
    free(v);
    CreateStack(N, w);
    
    while (!Empty(Pl))
    {
        v = Pop(Pl);
        str_cpy_31(v, w);
        free(v);
        Push(N, w);
    }
    
    printf("\n");
}

void ClearStack (TElem* &N)
{
    while (!Empty(N))
    {
        Pop(N);
    }
    
    printf("\n----------------------------------------------------\n");
    printf("                   Стек отчищен.");
    printf("\n----------------------------------------------------\n \n");
}

void ConnectStacks (TElem* &N1, TElem* &N2, TElem* &N3, int L)
{
    /*Так как тут 2 раза делается одно и то же действие, лучше, конечно, сделать еще одну функцию и тут её два раза вызвать.*/
    char Slovo[31];
    str_clean_31(Slovo);
    char* v;
    TElem* Pl = NULL;
    
    while (!Empty(N1))
    {
        v = Pop(N1);
        str_cpy_31(v, Slovo);
        free(v);
        Pl == NULL ? CreateStack(Pl, Slovo) : Push(Pl, Slovo);
        if (strlen(Slovo) == L)
            N3 == NULL ? CreateStack(N3, Slovo) : Push(N3, Slovo);
    }
    
    //Возвращаем исходный стек на место
    while (!Empty(Pl))
    {
        v = Pop(Pl);
        str_cpy_31(v, Slovo);
        free(v);
        N1 == NULL ? CreateStack(N1, Slovo) : Push(N1, Slovo);
    }
    
    while (!Empty(N2))
    {
        v = Pop(N2);
        str_cpy_31(v, Slovo);
        free(v);
        Pl == NULL ? CreateStack(Pl, Slovo) : Push(Pl, Slovo);
        if (strlen(Slovo) == L)
            N3 == NULL ? CreateStack(N3, Slovo) : Push(N3, Slovo);
    }
    
    //Возвращаем исходный стек на место
    while (!Empty(Pl))
    {
        v = Pop(Pl);
        str_cpy_31(v, Slovo);
        free(v);
        N2 == NULL ? CreateStack(N2, Slovo) : Push(N2, Slovo);
    }
    
    printf("\n----------------------------------------------------\n");
    printf("                   Стек создан.");
    printf("\n----------------------------------------------------\n \n");
}

int main(int argc, char* argv[])
{
    char ch;
    FILE *text1, *text2;
    int num;
    
    printf("----------------------|Lab 10|----------------------\n");
    do{
    printf("A - создать стек из стандартного текстового файла.\n"
           "C - соединить 1-й и 2-й стек в один.\n"
           "D - отчистить стек.\n"
           "V - вывести все элементы стека.\n"
           "E - конец.\n"
           "Ваш выбор: ");
    ch=getchar();   fflush(stdin);
    ch=toupper(ch);
//-----------Запись в стек из файла-----------------------
        if (ch == 'A')
        {
            printf("Введите номер файла (1 или 2): ");
            scanf("%d", &num);
            if (num == 1)
            {
                text1 = fopen("a.txt", "r");
                WriteInStack(NList1, text1);
                fclose(text1);
            }
            else if (num == 2)
            {
                text2 = fopen("b.txt", "r");
                WriteInStack(NList2, text2);
                fclose(text2);
            }
            else
                printf("Можно выбрать только 1-й или 2-й файл.\n");
            
            fflush(stdin);
            getchar();
        }

//-----------Создание нового стека------------------------
        else if (ch == 'C')
        {
            printf("Введите нужное количество букв: ");
            scanf("%d", &num);
            ConnectStacks (NList1, NList2, NList3, num);
            fflush(stdin);
            getchar();
        }
        else if (ch == 'D')
        {
            printf("Введите номер стека, который вы хотите отчистить: ");
            scanf("%d", &num);
            if (num == 1)
                ClearStack(NList1);
            else if (num == 2)
                ClearStack(NList2);
            else if (num == 3)
                ClearStack(NList3);
            else
                printf("Нет стека с таким номером.\n");
            
            fflush(stdin);
            getchar();
        }
        
//-----------Вывод содержимого стека----------------------
        else if (ch == 'V')
        {
            printf("Введите номер стека, информацию из которого хотите вывести: ");
            scanf("%d", &num);
            if (num == 1)
                Verbose(NList1);
            else if (num == 2)
                Verbose(NList2);
            else if (num == 3)
                Verbose(NList3);
            else
                printf("Стека с таким номером не существует.\n");
            
            fflush(stdin);
            getchar();
        }
//-----------выход----------------------------------------
        else if (ch == 'E')
            return 0;
//--------------------------------------------------------
        else
        {
            printf("Нет такой команды\nPress any key\n");
            getchar();
            fflush(stdin);
        }

        } while (ch!='E');

        return 0;
    }
