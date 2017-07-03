#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"

//funcao para encerrar programa
void encerra_programa (produto *p)
{
	free(p);
	clear_screen();
    printf("Volte sempre!\n");
    exit(0);
}

//funcao para menu de produtos
void menu_produtos (produto *p, int *n)
{
	char opcao;

	while (opcao != '9') {
		interface_menu_produtos();
		scanf(" %c", &opcao);

		switch (opcao) { //opcoes do menu de produtos

			case '1' :
				p = cadastra_produto(p, n);
				break;

			case '2' :
				atualiza_produto(p, n);
				break;

			case '3' :
				p = remove_produto(p, n);
				break;

			case '4' :
				consulta_produto(p, n);
				break;

			case '5' :
				imprime_produtos(p, n);
				break;

			case '9' :
				menu_principal(p, n);
				//break;
				//return;
				//return main();
				//main();

			default:
				clear_screen();
				printf("Opção Inválida!\n");
				printf("\nPrecione ENTER para voltar\n");
				getchar();
				getchar();

		}
	}
}

//funcao para menu principal
void menu_principal (produto *p, int *n)
{
	char opcao;

	while (1) {
		interface_menu_principal();
		scanf(" %c", &opcao);

		switch (opcao) { //opcoes do menu principal
			case '1' :
				menu_produtos(p, n);
				break;

			case '2' :
				iniciar_compra(p, n);
				break;

			case '3' :
				clear_screen();
				em_construcao();
				break;

    		case '9' :
				encerra_programa(p);
    			break;

    		default:
	    		clear_screen();
	    		printf("Opção Inválida!\n");
	    		printf("\nPrecione ENTER para voltar\n");
	    		getchar();
	    		getchar();
		}
	}
}
