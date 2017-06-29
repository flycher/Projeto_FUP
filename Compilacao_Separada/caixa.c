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
	int i, c = 1, aux, qtd_produtos;
	float total_compra = 0;
	carrinho *compra = (carrinho*) malloc(sizeof(carrinho) );
	system("clear");
	system("clear");

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
		system("clear");
		printf("\t\tCARRINHO\n");
		printf("----------------------------------------\n");
		printf("Insira ID '0' para encerrar compra\n");
		printf("Total parcial R$ %.2f\n", total_compra);
		printf("----------------------------------------\n");
		printf("Insira ID do produto.\n");
		scanf(" %d", &aux);


		if (aux == 0) {
			system("clear");
			system("clear");
			printf("Produto\t\t\t| Quantidade\t| Valor\n");
			printf("--------------------------------------------------\n");
			for(i = 0; i < (c-1); i++) {
				printf("%s\t\t\t %d\t R$ %.2f\n", compra[i].nome, compra[i].quantidade, compra[i].preco);
			}
			printf("--------------------------------------------------\n");
			printf("Total a pagar = R$ %.2f\n", total_compra);
			float troco = 0;
			printf("Valor recebido = R$ ");
			scanf(" %f", &troco);
			troco -= total_compra;
			printf("Troco = R$ %.2f", troco);
			printf("\nObrigado pela preferencia, volte sempre!\n");
			//aqui coloca a funcao para mandar os dados da compra para o arquivo
			//que vai guardas os negocio pro relatorio
			free(compra);
			printf("--------------------------------------------------\n");
			printf("\nPrecione ENTER para voltar ao menu principal\n");
			getchar();
			getchar();
			break;
		}

		for(i = 0; i < (*n); i++){
			if (aux == p[i].id) {
				printf(" Nome: %s\n", p[i].nome );
				printf(" Preco: RS %.2f\n", p[i].preco);
				int qtd_produtos = 1;
				printf("Insira a quantidade: ");
				scanf("%d", &qtd_produtos);
				total_compra += p[i].preco * qtd_produtos;
				compra[c-1].id = p[i].id;
				strcpy(compra[c-1].nome,p[i].nome);
				compra[c-1].preco = p[i].preco;
				compra[c-1].quantidade = qtd_produtos;
				c++;
				compra = (carrinho*) realloc(compra, (c+1) * sizeof(carrinho) );
				}
		}
	}
}
