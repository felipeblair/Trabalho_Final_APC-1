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
            case 1: {
                printf("\n--- CADASTRAR JOGO ---\n");
                if (quantidade_jogos >= 10) {
                    printf("Limite de 10 jogos atingido!\n");
                } else {
                    int novo_id;
                    printf("Informe o ID unico do jogo: ");
                    scanf("%i", &novo_id);
                    while(getchar() != '\n');

                    int id_duplicado = 0;
                    for (int i = 0; i < quantidade_jogos; i++) {
                        if (jogos[i].id == novo_id) {
                            id_duplicado = 1;
                            break;
                        }
                    }

                    if (id_duplicado == 1) {
                        printf("Erro: Este ID ja esta cadastrado no sistema!\n");
                    } else {
                        jogos[quantidade_jogos].id = novo_id;
                        printf("Informe o titulo do jogo: ");
                        scanf("%[^\n]s", jogos[quantidade_jogos].titulo); 
                        while(getchar() != '\n');
                        printf("Informe o ano de lancamento: ");
                        scanf("%i", &jogos[quantidade_jogos].ano_lancamento);
                        while(getchar() != '\n');
                        printf("Informe o preco do jogo: ");
                        scanf("%f", &jogos[quantidade_jogos].preco);
                        while(getchar() != '\n');
                        quantidade_jogos++;
                        printf("Jogo cadastrado com sucesso!\n");
                    }
                }
                break;
            }
            
            case 2: {
                printf("\n--- LISTA DE JOGOS ---\n");
                if (quantidade_jogos == 0) {
                    printf("Nenhum jogo cadastrado no momento.\n");
                } else {
                    for (int i = 0; i < quantidade_jogos; i++) {
                        printf("ID: %i | Titulo: %s | Ano: %i | Preco: R$ %.2f\n", 
                               jogos[i].id, jogos[i].titulo, jogos[i].ano_lancamento, jogos[i].preco);
                    }
                }
                break;
            }

            case 3: {
                printf("\n--- BUSCAR JOGO ---\n");
                if (quantidade_jogos == 0) {
                    printf("Nenhum jogo cadastrado no momento.\n");
                } else {
                    int id_busca;
                    printf("Informe o ID que deseja buscar: ");
                    scanf("%i", &id_busca);
                    while(getchar() != '\n');

                    int encontrou = 0;
                    for (int i = 0; i < quantidade_jogos; i++) {
                        if (jogos[i].id == id_busca) {
                            printf("Jogo encontrado!\n");
                            printf("Titulo: %s\nAno: %i\nPreco: R$ %.2f\n", 
                                   jogos[i].titulo, jogos[i].ano_lancamento, jogos[i].preco);
                            encontrou = 1;
                            break;
                        }
                    }

                    if (encontrou == 0) {
                        printf("Jogo com ID %i nao foi encontrado.\n", id_busca);
                    }
                }
                break;
            }
            
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