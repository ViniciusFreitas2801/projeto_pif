//Termo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Struct para definir nivel do jogo
//typedef struct
//{
    //int dificuldade;
//}st_nivel;

//Funcao que armazena palavras + e escolhe uma palavra aleatoria
void palavra_aleatoria();

//Main
int main(){

    palavra_aleatoria();

    return 0;
}

//Funcao que puxa uma palavra aleatoria do arquivo palavras.txt
void palavra_aleatoria()
{
    FILE* f;

    //Declaracao de variaveis
    int contador = 0;
    char palavra[6];

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



/* 
//Codigo que gera palavras aleatorias sem nexo, por exemplo, "dsadfa",
//ao inves de palavras coerente tipo "cadeira"...
//Pode ser reutilizado algumas trechos de codigo para o jogo final.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Funcao para criar uma letra aleatoria
char letra_aleatoria()
{
    char letras[] = "abcdefghijklmnopqrstuvwxyz"; //Letras alfabeto
    int index_aleatorio = rand() %26; //Gera um index entre 0 e 25 (A a Z)
    return letras[index_aleatorio];
}

//Funcao para gerar palavra aleatoria
void palavra_aleatoria(char *palavra, int num_letras)
{
    for (int i = 0; i < num_letras; i++)
    {
        palavra[i] = letra_aleatoria();
    }
    palavra[num_letras] = '\0'; //Add caracter nulo para finalizar a String
}

int main(){

    //Declaracao de variaveis
    int num_letras;

    //Inicia gerador de num aleatorios
    srand(time(0));

    //Pede ao usuario numero de letras que a palavra vai conter
    printf("Quantas letras voce quer que a palavra tenha?\n");
    scanf("%d", &num_letras);

    //Cria uma string para armazenar a palavra
    char palavra[num_letras + 1]; //+1 para caracter nulo

    //Gera e imprime a palavra aleatoria
    palavra_aleatoria(palavra, num_letras);
    printf("%s\n", palavra);

    return 0;
}
*/