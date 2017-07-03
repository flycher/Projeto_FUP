#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"

//limpa o terminal no linux e windows
void clear_screen()
{
	#ifdef _WIN32
	system("cls");
	#endif

	#ifdef linux
	system("clear");
	#endif
}

//simular carregamento na abertura do programa(nao essencial ao programa)
void carregando()
{
	int x, carregado = 0;

	while ( carregado < 106) {
    	clear_screen();
    	printf("\tBEM VINDO!");
    	if (carregado <= 100) printf("\n\n\nCarregando: %d / 100.\n", carregado);
    	   else printf("\n\n\nCarregando: 100 / 100.\n");

        while (1) {
			if ( carregado < 90 ) x = rand() % 4000000;
			   else x = rand() % 12000000;
			if (x == 1){
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

//funcao para imprimir funcionalidades ainda nao implementadas
void em_construcao()
{
	clear_screen();
	clear_screen();
	printf("----------------------------\n");
	printf("--Área em Desenvolvimento--");
	printf("\n----------------------------\n");
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

//funcao para imprimir o menu principal
void interface_menu_principal ()
{
	clear_screen();
	clear_screen();
	printf("\t--MENU INICIAL--\t%s\n\n", __DATE__);
	printf(" [1] - Controle de Produtos.\n");
	printf(" [2] - Iniciar Compra.\n");
	printf(" [3] - Imprimir Relatorio de Vendas.\n");
	printf(" [9] - Encerrar Programa.\n");
	printf("\nO que deseja? ");
}

//funcao para imprimir o menu de produtos
void interface_menu_produtos ()
{
	clear_screen();
	clear_screen();
	printf("\t--CONTROLE DE PRODUTOS--\t%s\n\n", __DATE__);
	printf(" [1] - Cadastrar Produto.\n");
	printf(" [2] - Atualizar Produto.\n");
	printf(" [3] - Remover Produto.\n");
	printf(" [4] - Consultar Produto.\n");
	printf(" [5] - Verificar Produtos Cadastrados.\n");
	printf(" [9] - Retornar ao Menu Inicial.\n");
	printf("\nO que deseja? ");

}
