#include "funcoes.h"

//Puxa uma palavra aleatoria do arquivo txt
char* palavra_aleatoria()
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
    
    printf("%s\n\t", palavra);
    
    fclose(f);
    
    return palavra;
}

void letra_verde(char ch)
{
    printf("\033[0;32m");
    printf("%c", ch);

    //Voltar padrao
    printf("\033[0m");
}

void letra_amarela(char ch)
{
    printf("\033[0;33m");
    printf("%c", ch);

    //Volta ao padrao
    printf("\033[0m");
}

void print_palavra(char palavra[6], char palavra_usuario[6])
{
    printf("%s", palavra);

    for (int i = 0; i < 5; i++)
    {
        if (palavra[i] == palavra_usuario[i])
        {
            letra_verde(palavra[i]);
        }
        
        else
        {
            printf("%c", palavra[i]);
        }


    }
    
}

void tentativa_usuario()
{
    char tentativa[6];

    scanf("%s", tentativa);

    print_palavra(palavra_aleatoria(), tentativa);


}