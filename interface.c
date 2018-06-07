#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"
#include "relatorio.h"

//limpa o terminal no linux ou windows
void limpa_tela()
{
#ifdef _WIN32
    system("cls");
#endif

#ifdef linux
    system("clear");
#endif
}

//simula um carregando do programa
void carregando()
{
    int x, carregado = 0;

    while ( carregado < 106) {
        limpa_tela();
        printf("\tBEM VINDO!\n");

        if (carregado <= 100) printf("\n\n\nAbrindo Caixa... %d / 100.\n", carregado);
        else printf("\n\n\nConcluido.\n");

        while (1) {
            if ( carregado < 90 ) x = rand() % 4000000;
            else x = rand() % 18000000;
            if (x == 1) {
                carregado++;
                carregado++;
                break;
            }
        }
    }
}

//funcao para calcular os espacos ao imprimir o nome dos produtos na finalizaçao da compra
void espacamento_tabela(char* nome, int espaco)
{
    int i, n;
    n = strlen(nome);
    for( i = 0; i < (espaco - n); i++)	printf(" ");
}

//funcao para imprimir os tracos na interface
void separacao_traco(int traco)
{
    int i;
    for(i = 0; i < traco; i++) printf("-");
}

//funcao para imprimir funcionalidades ainda nao implementadas
void em_construcao()
{
    limpa_tela();
    limpa_tela();
    separacao_traco(27);
    printf("\n--Área em Desenvolvimento--\n");
    separacao_traco(27);
    printf("\nPrecione ENTER para voltar\n");
    getchar();
    getchar();
}

//funcao para imprimir o menu principal
void interface_menu_principal()
{
    limpa_tela();
    limpa_tela();
    printf("\t--MENU INICIAL--\t%s\n\n", __DATE__);
    printf(" [1] - Controle de Produtos.\n");
    printf(" [2] - Iniciar Venda.\n");
    printf(" [3] - Imprimir Relatorio de Vendas.\n");
    printf(" [9] - Encerrar Programa.\n");
    printf("\nO que deseja? ");
}

//funcao para imprimir o menu de produtos
void interface_menu_produtos()
{
    limpa_tela();
    limpa_tela();
    printf("\t--CONTROLE DE PRODUTOS--\t%s\n\n", __DATE__);
    printf(" [1] - Cadastrar Produto.\n");
    printf(" [2] - Atualizar Produto.\n");
    printf(" [3] - Remover Produto.\n");
    printf(" [4] - Consultar Produto.\n");
    printf(" [5] - Verificar Produtos Cadastrados.\n");
    printf(" [9] - Retornar ao Menu Inicial.\n");
    printf("\nO que deseja? ");

}
