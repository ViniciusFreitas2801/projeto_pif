#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct st_status
{
    int tentativas;
    struct st_status *next;
}st_status;

//char* palavra_aleatoria();

//void letra_verde(char ch);

//void letra_amarela(char ch);

//void input();

//void layout();

void exibirPalavra(char *palavra, char *entrada);

char* pedir_entrada();

void add_node(st_status **head, int tentativas);

void print_status(st_status *head, int num, char texto[]);

int opcao_player();

void limpar_terminal();

void liberar_lista(st_status** head);

//void minusculas(char** entrada);