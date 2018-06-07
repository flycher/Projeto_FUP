#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"
#include "relatorio.h"

//funcao para liberar a memoria e encerrar programa
void encerra_programa(produto *prods)
{
    free(prods);
    limpa_tela();
    printf("Caixa Encerrado!\n");
    exit(0);
}

//funcao para menu de produtos
void menu_produtos(produto *prods, int *qtd)
{
    char opcao;

    while (1) {
        interface_menu_produtos();
        scanf(" %c", &opcao);

        switch (opcao) {

        case '1' :
            prods = cadastra_produto(prods, qtd);
            break;

        case '2' :
            atualiza_produto(prods, qtd);
            break;

        case '3' :
            prods = remove_produto(prods, qtd);
            break;

        case '4' :
            consulta_produto(prods, qtd);
            break;

        case '5' :
            imprime_produtos(prods, qtd);
            break;

        case '9' :
            menu_principal(prods, qtd);
            break;

        default:
            limpa_tela();
            printf("Opção Inválida!\n");
            printf("\nPrecione ENTER para voltar\n");
            getchar();
            getchar();

        }
    }
}

//funcao para menu principal
void menu_principal(produto *prods, int *qtd)
{
    char opcao;

    while (1) {
        interface_menu_principal();
        scanf(" %c", &opcao);

        switch (opcao) {
        case '1' :
            menu_produtos(prods, qtd);
            break;

        case '2' :
            iniciar_compra(prods, qtd);
            break;

        case '3' :
            ler_arquivo_relatorio();
            break;

        case '9' :
            encerra_programa(prods);
            break;

        default:
            limpa_tela();
            printf("Opção Inválida!\n");
            printf("\nPrecione ENTER para voltar\n");
            getchar();
            getchar();
        }
    }
}
