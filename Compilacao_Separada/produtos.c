#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"

//funcao para ler os dados do arquivo
produto* ler_lista_produtos_txt (produto *vetor, int *n)
{
    int i = 0;
	produto auxiliar;

	FILE *f = fopen("ProdutosCadastrados.txt", "r");
	if (f == 0) {
		FILE *f = fopen("ProdutosCadastrados.txt", "w");
        f = f;
		return vetor;
	}

	while(fscanf(f, "%d\n%[^\n]\n%f\n", &auxiliar.id, auxiliar.nome, &auxiliar.preco) == 3) {

    	if ((*n) == 0) {
    		vetor = (produto*) malloc(sizeof(produto));
            if(vetor == 0) printf("Erro no malloc");
    	}	else {
    			vetor = (produto*) realloc(vetor, ((*n)+1) * sizeof(produto));
    			if(vetor == 0) printf("Erro no realloc");
    		}

		vetor[i] = auxiliar;
    	i++;
    	(*n)++;
    }

	return vetor;
}

//funcao para escrever os dados no arquivo
void produto_para_arquivo(produto vetor[], int n)
{
	FILE *f = fopen("ProdutosCadastrados.txt", "w");
	int i;

	if (f == 0) {
      printf("** ERRO, Arquivo Inacessível! **");
	}

    for( i = 0; i < n; i++) {
		fprintf(f, "%d\n%s\n%f\n", vetor[i].id, vetor[i].nome, vetor[i].preco);
	}

	fclose(f);
}

//funcao para cadastrar produto
produto* cadastra_produto (produto *p, int *n)
{
	system("clear");

	int i;
	produto auxiliar;
    printf("\t--CADASTRO DO PRODUTO--\n");
	printf("-----------------------\n");
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
	scanf(" %32[^\n]", auxiliar.nome);
	printf("Insira o preco: R$ ");
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
			printf("-----------------------\n");
            printf(" Nome: %s\n", p[i].nome );
    		printf(" Preco: RS %.2f\n", p[i].preco);
            printf("\nInsira o novo Nome do Produto: ");
            scanf("\n%32[^\n]", p[i].nome);
            printf("Insira o novo Preço do Produto: R$ ");
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
			 printf("-----------------------\n");
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
			printf("-----------------------\n");
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

	//caso o arquivo nao tenha nenhum produto cadastrado
	if ((*n) == 0) {
		printf("--------------------------\n");
		printf("Nenhum Produto Registrado!");
		printf("\n--------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return;
	}

	//organiza os produtos por ordem crescente de id
	produto aux;
	for(i = 0; i < (*n); i++) {
		for(j = 1; j < (*n); j++) {
			if (p[j].id < p[j-1].id) {
				aux = p[j-1];
				p[j-1] = p[j];
				p[j] = aux;
			}
		}
	}

	//imprime todos os produtos cadastrados
	printf("\t--LISTA DE PRODUTOS --\n\n--------------------------\n");
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
