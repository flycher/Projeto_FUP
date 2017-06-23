#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

//funcao para cadastra produto
produto* cadastra_produto (produto *p, int *n)
{
	system("clear");

	int i;
	produto auxiliar;
    printf("\t--CADASTRO DO PRODUTO--\n\n");
    printf("Insira a ID: ");
	scanf(" %d", &auxiliar.id);

	for (i = 0; i < (*n); i++) {
		if (auxiliar.id == p[i].id) {
			printf("\n-----------------------\n");
			printf("Código ID já cadastrado!\n");
			printf("-----------------------\n");
			printf("\nPrecione ENTER para voltar\n");
			getchar();
			getchar();
			return p;
		}
	}

	printf("Insira o nome: ");
	scanf(" %50[^\n]", auxiliar.nome);
	printf("Insira o preco: ");
	scanf(" %f", &auxiliar.preco);

	if ((*n) == 0) {
		p = (produto *) malloc(sizeof(produto));
		(*n)++;
	}	else {
			p = (produto *) realloc(p, ((*n)+1) * sizeof(produto) );
			(*n)++;
			if(p == 0){
				printf("Erro no Realloc");
				return 0;
			}
		}

	p[(*n) - 1] = auxiliar;
	produto_para_arquivo(p, (*n));

	return p;
}

//funcao para atualizar produto
void atualiza_produto (produto *p, int *n)
{
	 system("clear");
	 system("clear");

	 if ((*n) == 0) {
		printf("--------------------------\n");
		printf("Nenhum Produto Registrado!");
		printf("\n--------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return ;
	 }

	int i, aux, cont = 0;
	system("clear");
	system("clear");
    printf("Insira o Código ID do Produto: ");
    scanf("%d", &aux);

	for(i = 0; i < (*n); i++){
		if (aux == p[i].id) {
            printf(" Nome: %s\n", p[i].nome );
    		printf(" Preco: RS %.2f\n", p[i].preco);
            printf("\nInsira o novo Nome do Produto: ");
            scanf("\n%50[^\n]", p[i].nome);
            printf("Insira o novo Preço do Produto: ");
    		scanf("%f", &p[i].preco);
    		cont++;
    	}
    }

    produto_para_arquivo(p, (*n));

    if (cont == 0) {
			printf("\n-----------------------\n");
			printf("Produto não Encontrado!\n");
	}	else {
		printf("\n-----------------------\n");
		printf("  Produto Atualizado!\n");
		}
    printf("-----------------------\n");
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

//funcao para remover produto
produto* remove_produto(produto *p, int *n)
 {
     system("clear");
	 system("clear");

	 if ((*n) == 0) {
		printf("--------------------------\n");
 		printf("Nenhum Produto Registrado!");
 		printf("\n--------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return (p);
	 }

     int i, aux, cont = 0;
     printf("Insira o Código ID do Produto: ");
     scanf("%d", &aux);
     for (i = 0; i < (*n); i++) {
         if (aux == p[i].id) {
             printf(" Nome: %s\n", p[i].nome );
     		 printf(" Preco: RS %.2f\n", p[i].preco);
             p[i] = p[(*n) - 1];
             p = (produto*) realloc(p, (*n-1) * sizeof(produto));
             cont++;
         }
    }

    if (cont == 0) {
			printf("\n-----------------------\n");
			printf("Produto não Encontrado!\n");
	}	else {
		printf("\n-----------------------\n");
		printf("  Produto Removido!\n");
		}
    printf("-----------------------\n");
 	printf("\nPrecione ENTER para voltar\n");
 	getchar();
 	getchar();
    (*n)--;

    produto_para_arquivo(p, (*n));

     return (p);
}

//funcao para consultar produto
void consulta_produto (produto *p, int *n)
{

	int i, aux, cont = 0;
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

    printf("Insira o Código ID do Produto: ");
    scanf("%d", &aux);

	for(i = 0; i < (*n); i++){
		if (aux == p[i].id) {
            printf(" Nome: %s\n", p[i].nome );
    		printf(" Preco: RS %.2f\n", p[i].preco);
    		cont++;
        }
    }

    if (cont == 0) {
			printf("\n-----------------------\n");
			printf("Produto não Encontrado!\n");
	}

    printf("-----------------------\n");
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

//funcao para imprimir todos os produtos cadastrados
void imprime_produtos (produto *p, int *n)
{
	int i, j;
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
	
	produto aux;
	for (i = 0; i < (*n); i++) {
		for (j = 1; j < (*n); j++) {
			if (p[j].id < p[j-1].id) {
				aux = p[j-1];
				p[j-1] = p[j];
				p[j] = aux;
			}
		}
	}
	
	printf("\t--LISTA DE PRODUTOS--\n\n--------------------------\n");
	for(i = 0; i < (*n); i++){
        		printf(" Id: %d\n", p[i].id);
        		printf(" Nome: %s\n", p[i].nome );
        		printf(" Preco: RS %.2f\n", p[i].preco);
        		printf("-----------------------\n");
    }

	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}
