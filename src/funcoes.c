#include "funcoes.h"

//Funcao 
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

//Funcao para a reposta do usuario
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

//Funcao Status
void add_node(st_status **head, int tentativas)
{
    st_status *novo = (st_status *)malloc(sizeof(st_status));

    novo -> tentativas = tentativas;
    novo -> next = NULL;

    if (*head == NULL)
    {
        *head = novo;
    }

    else
    {
        novo -> next = *head;
        *head = novo;
    }
}

//Funcao que printa o status
void print_status(st_status *head, int num, char texto[])
{
    int count = 0;
    printf("%s ", texto);

    while(head != NULL)
    {
        if (head -> tentativas == num)
        {
            printf("\033[44;37m  \033[0m");
            count++;
        }     
        head = head -> next;
    }

    printf(" %d\n\n", count);
}

//Funcao continuar ou parar
int opcao_player()
{
    int opcao;

    scanf("%d", &opcao);
    
    if (opcao != 0 && opcao != 1)
    {
        printf("Digite algum numero valido: ");
        opcao_player();
    }
    
    return opcao;
}

//Funcao limpar terminal
void limpar_terminal() 
{
    #ifdef _WIN32
        // Sistema Windows
        system("cls");
    #else
        // Sistema macOS ou Linux
        system("clear");
    #endif
}

//Funcao libera espaco de memoria da lista encadeada
void liberar_lista(st_status** head) 
{
    if (*head == NULL) 
    {
        return;
    }
    
    st_status *atual = *head;
    st_status *proximo;

    while (atual->next != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    if (atual != NULL) {
       free(atual); 
    }

    *head = NULL;
}