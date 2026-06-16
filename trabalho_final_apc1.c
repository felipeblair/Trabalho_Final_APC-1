#include <stdio.h>
#include <string.h>

int main() {
    
    struct Jogo {
        int id;
        char titulo[50];
        int ano_lancamento;
        float preco;
    };

    
    struct Jogo jogos[10]; 
    int quantidade_jogos = 0;
    int opcao_menu = 0;

    
    do {
        printf("\n===================================\n");
        printf("       SISTEMA DE JOGOS\n");
        printf("===================================\n");
        printf("1 - Cadastrar novo jogo\n");
        printf("2 - Listar jogos cadastrados\n");
        printf("3 - Buscar jogo por ID\n");
        printf("4 - Atualizar dados de um jogo\n");
        printf("5 - Remover jogo\n");
        printf("6 - Sair do programa\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao => ");
        
        scanf("%i", &opcao_menu);
        while(getchar() != '\n'); 

        switch(opcao_menu) {
            case 6: {
                
                printf("\nEncerrando o sistema. Ate logo!\n");
                break;
            }
        }

        if (opcao_menu != 6) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcao_menu != 6);

    return 0;
}