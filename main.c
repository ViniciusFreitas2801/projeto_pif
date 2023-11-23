//TERMO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/time.h>
#include "funcoes.h"

//Main
int main(){

    st_status *head = NULL;

    int play = 1;

    do
    {
        limpar_terminal();

        //Abrir o arquivo contendo palavras aleatórias
        FILE *arquivo = fopen("palavras.txt", "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        //Ler uma palavra aleatória do arquivo
        char palavra[6]; // Supondo que as palavras tenham 5 letras + '\0'
        fscanf(arquivo, "%s", palavra);

        //Fechar o arquivo
        fclose(arquivo);

        //Status
        int tentativas = 0;

        //Loop principal do jogo
        while (true) {
            

            //Obter entrada do usuário
            char* entrada = pedir_entrada();

            //Converter a entrada para minúsculas
            for (int i = 0; i < 5; i++)
            {
                char letra;

                letra = entrada[i];

                entrada[i] = tolower(letra);
            }

            //Exibir o estado atual da palavra
            exibirPalavra(palavra, entrada);

            //Verificar se a palavra foi adivinhada
            bool palavraAdivinhada = true;
            for (int i = 0; i < strlen(palavra); i++) {
                if (entrada[i] != palavra[i]) {
                    palavraAdivinhada = false;
                    break;
                }
            }

            tentativas++;

            if (palavraAdivinhada) 
            {
                printf("Parabéns! Você adivinhou a palavra\n");
                break;
            }

            if (tentativas > 6)
            {
                printf("Voce perdeu :(\n");
                printf("A palavra certa era %s\n", palavra);
                break;
            }
        }

        add_node(&head, tentativas);

        print_status(head, 1, "     1");
        print_status(head, 2, "     2");
        print_status(head, 3, "     3");
        print_status(head, 4, "     4");
        print_status(head, 5, "     5");
        print_status(head, 6, "     6");
        print_status(head, 7, "morreu");

        printf("Digite 1 para countinuar jogando ou 0 para parar o jogo: ");
        
        play = opcao_player();

    } while (play);

    liberar_lista(&head);

    return 0;
}