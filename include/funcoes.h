#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct
{
    int tentativas1;
    int tentativas2;
    int tentativas3;
    int tentativas4;
    int tentativas5;
    int tentativas6;
    int morreu;
}st_status;

//char* palavra_aleatoria();

//void letra_verde(char ch);

//void letra_amarela(char ch);

//void input();

//void layout();

void exibirPalavra(char *palavra, char *entrada);

char* pedir_entrada();

//void minusculas(char** entrada);