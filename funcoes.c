#include "funcoes.h"

//Puxa uma palavra aleatoria do arquivo txt
void palavra_aleatoria()
{
    FILE* f;

    //Declaracao de variaveis
    int contador = 0;
    char *palavra;

    //Criando malloc
    palavra = (char*)malloc(6 * sizeof(char));

    //Abre arquivo
    f = fopen("palavras.txt", "r");

    //Verifica se foi possivel abrir o arquivo
    if (f == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    //Conta o numero de palavras do arquivo
    while (fscanf(f, "%s", palavra) == 1)
    {
        contador++;
    }

    fseek(f, 0, SEEK_SET); //Reinicia o ponteiro do arquivo para o inicio

    srand(time(NULL));

    int linha = rand() % contador;
    int atual = 0;

    while (atual < linha && fscanf(f, "%s", palavra) == 1)
    {
        atual++;
    }
    
    printf("%s\n", palavra);
    
    fclose(f);
    
}