//Termo
//1 - Gerar palavra OK
//2 - Input do usuario
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/time.h> //? Verificar se foi da biblioteca que pamela passou
#include "funcoes.h"
#include "timer.h"

//Main
int main(){

     // Abrir o arquivo contendo palavras aleatórias
    FILE *arquivo = fopen("palavras.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler uma palavra aleatória do arquivo
    char palavra[6]; // Supondo que as palavras tenham 5 letras + '\0'
    fscanf(arquivo, "%s", palavra);

    // Fechar o arquivo
    fclose(arquivo);


    // Loop principal do jogo
    while (true) {
        

        // Obter entrada do usuário
        char* entrada = pedir_entrada();

        // Converter a entrada para minúsculas
        for (int i = 0; i < 5; i++)
        {
            char letra;

            letra = entrada[i];

            entrada[i] = tolower(letra);
        }

        // Exibir o estado atual da palavra
        exibirPalavra(palavra, entrada);

        // Verificar se a palavra foi adivinhada
        bool palavraAdivinhada = true;
        for (int i = 0; i < strlen(palavra); i++) {
            if (entrada[i] != palavra[i]) {
                palavraAdivinhada = false;
                break;
            }
        }

        if (palavraAdivinhada) {
            printf("Parabéns! Você adivinhou a palavra\n");
            break;
        }
    }

    return 0;
}

    //timerPrint();

    //palavra_aleatoria();

    //layout();

    //input();