#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"
#include "relatorio.h"

//funcao para registrar compra
void iniciar_compra(produto *p, int *n)
{
	int i, c = 0, aux, teste1, teste2;
	float total_compra = 0, troco, qtd_compra = 0, qtd_produtos = 0;
	carrinho *compra;

	limpa_tela();
	limpa_tela();

	//verifica se algum produto esta cadastrado
	if ((*n) == 0) {
		separacao_traco(26);
		printf("\nNenhum Produto Registrado!\n");
		separacao_traco(26);
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return;
	}

	while(1) {
		limpa_tela();
		printf("\t\tCARRINHO\n");
		separacao_traco(40);
		printf("\nInsira ID '0' para encerrar compra\n");
		printf("Total parcial R$ %.2f\n", total_compra);
		separacao_traco(40);
		printf("\nInsira ID do produto.\n");
		scanf(" %d", &aux);

		//ao inserir id '0'
		if (aux == 0) {
			if ( qtd_compra == 0) return; //caso nenhum produto tenha sido adicionado sai da funcao
			limpa_tela();
			limpa_tela();
			printf("Produto\t\t\t| Quantidade\t|  Valor Und.\t|  Valor Total\n");
			separacao_traco(70);
			printf("\n");
			//imprime todos os produtos inseridos na compra
			for(i = 0; i < (c); i++) {
				printf("%s", compra[i].nome);
				espacamento_tabela(compra[i].nome, 30);
				printf("%.2f\t", compra[i].quantidade);
				printf("    R$ %.2f\t   R$ %.2lf\n",compra[i].preco, compra[i].preco * compra[i].quantidade);
			}

			separacao_traco(70);
			//imprime o total de produtos comprados e o total da compra
			printf("\nTotal\t\t\t|\t%.0f\t|\t\t|  R$ %.2f\n", qtd_compra, total_compra);
			separacao_traco(70);
			printf("\nValor recebido = R$ ");
			 //recebe o dinheiro paga pelo cliente
			scanf(" %f", &troco);
			//caso valor seja '0' ou abaixo do total da compra, a compra e cancelada e nao enviada ao relatorio
			if ((troco == 0) || (troco - total_compra) < 0 ) {
				printf("\nCompra cancelada.\n");
				free(compra);
				printf("\nPrecione ENTER para voltar ao menu principal\n");
				getchar();
				getchar();
				return;
			}

			//calcula a diferenca entre o toral da compra e o valor pago pelo cliente
			troco -= total_compra;
			printf("Troco = R$ %.2f\n", troco); //imprime a diference entre o valor pago e o total
			separacao_traco(70);
			printf("\n%s\t%s\n", __DATE__, __TIME__); //imprime na tela o dia e hora da compra
			printf("\nObrigado pela preferencia, volte sempre!\n");
			//funcao para mandar os dados da compra para o arquivo de relatorio
			carrinho_para_relatorio_arquivo(compra, c, qtd_compra, total_compra);
			//limpa a memoria alocada para os dados da compra
			free(compra);
			separacao_traco(70);
			printf("\n\nPrecione ENTER para voltar ao menu principal\n");
			getchar();
			getchar();
			return;
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
				teste2 = 1; //produto foi encontrado no carrinho
			}
		}

		//funcao para adicionar novo produto ao carrinho
		teste1 = 0;
		for(i = 0; ( i < (*n) ) && (!teste2); i++){
			if (aux == p[i].id) {
				teste1 = 1; //produto foi encontrado nos produtos cadastrados
				printf(" Nome: %s\n", p[i].nome );
				printf(" Preco: RS %.2f\n", p[i].preco);
				printf("Insira a quantidade: ");
				scanf("%f", &qtd_produtos);
				//caso a quantidade inserida seja '0',ignora o produto e nao aloca memoria para ele
				if (qtd_produtos == 0) continue;
				qtd_compra += qtd_produtos; //aumenta quantidade de produtos comprados
				total_compra += p[i].preco * qtd_produtos; //aumenta o total da compra
				//aloca memoria para guardar os dados do produto comprado
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
				 //copia para o produto comprado os dados do produto e a quantidade
				compra[c-1].id = p[i].id;
				strcpy(compra[c-1].nome,p[i].nome);
				compra[c-1].preco = p[i].preco;
				compra[c-1].quantidade = qtd_produtos;
			}
		}

		//caso o produto nao seja encontrado no carrinho ou nos produtoos cadastrados
		if (!teste1 && !teste2) {
			separacao_traco(18);
			printf("\nID não encontrado\n");
			separacao_traco(18);
			printf("\nPrecione ENTER para continuar");
			getchar();
			getchar();
		}

	}
}
