#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int dificuldade;
}st_nivel;

char* palavra_aleatoria();

void letra_verde(char ch);

void letra_amarela(char ch);

void tentativa_usuario();