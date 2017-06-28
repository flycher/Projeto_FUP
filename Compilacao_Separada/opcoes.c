#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"


//funcao para encerrar programa
void encerra_programa ()

{
	system("clear");
    printf("Volte sempre!\n");
    exit(0);
}


//funcao para menu de produtos
void menu_produtos (produto *mercadoria, int *qtd)
{
	char opcao;
	
	while (opcao != '9') {
		interface_menu_produtos();
		scanf(" %c", &opcao);
							
		switch (opcao) { //opcoes do menu de produtos

			case '1' :
				mercadoria = cadastra_produto(mercadoria, qtd);
				break;

			case '2' :
				atualiza_produto(mercadoria, qtd);
				break;

			case '3' :
				mercadoria = remove_produto(mercadoria, qtd);
				break;

			case '4' :
				consulta_produto(mercadoria, qtd);
				break;

			case '5' :
				imprime_produtos(mercadoria, qtd);
				break;

			case '9' :
				system("clear");
				break;

			default:
				system("clear");
				printf("Opção Inválida!\n");
				printf("\nPrecione ENTER para voltar\n");
				getchar();
				getchar();

		}
	}
}
	
//funcao para menu principal
void menu_principal (produto *mercadoria, int *qtd)
{
	char opcao;
	
	while (1) {
		interface_menu_principal();
		scanf(" %c", &opcao);
		
		switch (opcao) { //opcoes do menu principal
			case '1' :
				menu_produtos(mercadoria, qtd);
				break;

			case '2' :
				system("clear");
				em_construcao();
				break;

			case '3' :
				system("clear");
				em_construcao();
				break;

    		case '9' :
				encerra_programa();
    			break;

    		default:
	    		system("clear");
	    		printf("Opção Inválida!\n");
	    		printf("\nPrecione ENTER para voltar\n");
	    		getchar();
	    		getchar();
		}
	}
}
