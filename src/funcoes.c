#include "funcoes.h"

//Puxa uma palavra aleatoria do arquivo txt
/*
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
    
    fclose(f);
    
    return palavra;
}
*/

int verificar_letra_duplicada(char* palavra, char* entrada, char letra)
{
    int count_palavras = 0;
    int count_entradas = 0;

    for (int i = 0; i < 5; i++)
    {
        if (palavra[i] == letra)
        {
            count_palavras++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (entrada[i] == letra)
        {
            count_entradas++;
        }
    }

    if (count_palavras < count_entradas || count_palavras == 0)
    {
        return 0;
    }

    return 1;
    
    
}

// Função para exibir o estado atual da palavra
void exibirPalavra(char *palavra, char *entrada) {
    for (int i = 0; i < strlen(entrada); i++) {
        
        if (palavra[i] == entrada[i])
        {
            printf("\033[32m%c \033[0m", entrada[i]);
        }
        else if (verificar_letra_duplicada(palavra, entrada, entrada[i])) 
        {
            printf("\033[33m%c \033[0m", entrada[i]);
        } 
        else 
        {
            printf("_ ");
        }
    }
    printf("\n\n");
}


//Funcao pra mudar de cor as letras
/*
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
*/

//Funcao input (nao mais necessaria)
/*
void input()
{
    char palavra_termo[6];
    char resposta[6];
    char array[6] = {'_', '_', '_', '_', '_'};

    printf("\tTERMO\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\t%c", array[i]);
    }

    printf("\n\n");

    strcpy(palavra_termo, palavra_aleatoria());

    while (strcmp(resposta, palavra_termo) != 0)
    {
        printf("\tDigite seu palpite: ");
        scanf("\t%s", resposta);

        if ()
        {
            
        }
        

        if (strcmp(resposta, palavra_termo) == 0)
        {
            printf("\tParabens, voce acertou!\n");
        }
        
    }
}
*/

//Funcao layout
/*
void layout()
{
    int vidas = 5;
    
    while ()
    {
        vidas--;
    }

    if (vidas = 0)
    {
        exit(1);
    }

    printf("\n\tTERMO                %d\n\n ", vidas);

}
*/

char* pedir_entrada()
{
    char* entrada;

    entrada = (char*)malloc(6 * sizeof(char));

    printf("Digite uma palavra: ");
    scanf(" %s", entrada);

    int tam = 0;

    while (entrada[tam] != '\0')
    {
        tam++;
    }

    if (tam != 5)
    {
        printf("A palavra precisa ter 5 letras! \n");
        pedir_entrada();
    }

    else
    {
        return entrada;
    }
    
    

}

//Funcao minuscula
/*
void minusculas(char** entrada)
{
    for (int i = 0; i < 5; i++)
    {
        char letra;

        letra = *entrada[i];

        *entrada[i] = tolower(letra);
    }
}
*/