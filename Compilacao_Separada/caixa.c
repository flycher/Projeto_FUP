#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"

//funcao para registrar compra
void iniciar_compra (produto *p, int *n)
{
	int i, c = 0, aux, teste1, teste2;
	float total_compra = 0, troco, qtd_compra = 0, qtd_produtos = 0;
	carrinho *compra;

	clear_screen();
	clear_screen();

	if ((*n) == 0) {
		printf("--------------------------\n");
		printf("Nenhum Produto Registrado!");
		printf("\n--------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return;
	}

	while(1) {
		clear_screen();
		printf("\t\tCARRINHO\n");
		printf("----------------------------------------\n");
		printf("Insira ID '0' para encerrar compra\n");
		printf("Total parcial R$ %.2f\n", total_compra);
		printf("----------------------------------------\n");
		printf("Insira ID do produto.\n");
		scanf(" %d", &aux);

		if (aux == 0) {
			if ( qtd_compra == 0) return;
			clear_screen();
			clear_screen();
			printf("Produto\t\t\t| Quantidade\t|  Valor Und.\t|  Valor Total\n");
			printf("-----------------------------------------------------------------------\n");
			for(i = 0; i < (c); i++) {
				printf("%s", compra[i].nome);
				espacamento_tabela(compra[i].nome, 30);
				printf("%.2f\t", compra[i].quantidade);
				printf("    R$ %.2f\t   R$ %.2lf\n",compra[i].preco, compra[i].preco * compra[i].quantidade);
			}

			printf("-----------------------------------------------------------------------\n");
			printf("Total\t\t\t|\t%.0f\t|\t\t| R$ %.2f\n", qtd_compra, total_compra);
			printf("-----------------------------------------------------------------------\n");
			printf("Valor recebido = R$ ");
			scanf(" %f", &troco);
			if ((troco == 0) || (troco - total_compra) < 0 ) {
				printf("\nCompra cancelada.\n");
				free(compra);
				printf("\nPrecione ENTER para voltar ao menu principal\n");
				getchar();
				getchar();
				break;
			}

			troco -= total_compra;
			printf("Troco = R$ %.2f", troco);
			printf("\nObrigado pela preferencia, volte sempre!\n");
			//aqui coloca a funcao para mandar os dados da compra para o arquivo
			free(compra);
			printf("------------------------------------------------------\n");
			printf("\nPrecione ENTER para voltar ao menu principal\n");
			getchar();
			getchar();
			break;
		}

		//funcao para adicionar quantidade aos produtos que ja estao no carrinho
		teste2 = 0;
		for(i = 0; i < qtd_compra; i++){
			if ( aux == compra[i].id){
				printf(" Nome: %s\n", compra[i].nome );
				printf(" Preco: RS %.2f\n", compra[i].preco);
				printf("Insira a quantidade: ");
				scanf(" %f", &qtd_produtos);
				compra[i].quantidade += qtd_produtos;
				qtd_compra += qtd_produtos;
				total_compra += compra[i].preco * qtd_produtos;
				teste2 = 1;
			}
		}

		//funcao para adicionar novo produto ao carrinho
		teste1 = 0;
		for(i = 0; ( i < (*n) ) && (!teste2); i++){
			if (aux == p[i].id) {
				teste1 = 1;
				printf(" Nome: %s\n", p[i].nome );
				printf(" Preco: RS %.2f\n", p[i].preco);
				qtd_produtos = 1;
				printf("Insira a quantidade: ");
				scanf("%f", &qtd_produtos);
				if (qtd_produtos == 0) continue;
				qtd_compra += qtd_produtos;
				total_compra += p[i].preco * qtd_produtos;
				if (c == 0) {
					compra = (carrinho*) malloc(sizeof(carrinho) );
					(c)++;
				}	else {
						compra = (carrinho*) realloc(compra, (c+1) * sizeof(carrinho) );
						(c)++;
						if(compra == 0){
							printf("Erro no Realloc");
							return ;
						}
					}
				compra[c-1].id = p[i].id;
				strcpy(compra[c-1].nome,p[i].nome);
				compra[c-1].preco = p[i].preco;
				compra[c-1].quantidade = qtd_produtos;
			}
		}

		if (!teste1 && !teste2) {
			printf("\nID não encontrado.\n");
			printf("Precione ENTER para continuar");
			getchar();
			getchar();
		}

	}
}
