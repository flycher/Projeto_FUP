#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"
#include "relatorio.h"

//retorna data atual em um inteiro para possibilitar busca no arquivo
int data_atual()
{
	time_t ini = time(0);

	struct tm *t = gmtime(&ini);
	return(t->tm_mday + (t->tm_mon + 1)*100+ (t->tm_year + 1900)*10000);
}

//recebe data desejada e retorna um inteiro possibilitar busca no arquivo
int recebe_data()
{
	int x, dataP;
	printf("Insira a data desejada (dd/mm/aaaa) = ");
	scanf("%d/", &x);
	dataP = x;
	scanf("%d/", &x);
	dataP += x*100;
	scanf("%d", &x);
	dataP += x*10000;
	return dataP;
}

//funcao para escrever os dados das compras realizadas no arquivo
void carrinho_para_relatorio_arquivo(carrinho vetor[], int nTipoItens, float nProdutos, float tCompra)
{
	FILE *f = fopen("RelatorioDeVendas.txt", "a");
	int i;

	if (f == 0) {
      printf("** ERRO, Arquivo Inacessível! **");
	}

	//grava no arquivo todos os produtos comprados e a data da compra
    for( i = 0; i < nTipoItens; i++) {
		fprintf(f, "%d\n%s\n%f\n%f\n", vetor[i].id, vetor[i].nome, vetor[i].quantidade, vetor[i].preco);
		fprintf(f, "%d\n",data_atual());
	}

	fclose(f);
}

//funcao para imprimir o relatorio de vendas a partir da data procurada
void imprime_relatorio (carrinho *p, int n, int dataCompra)
{
	int i, j;
	float total = 0, quantidade = 0;
	limpa_tela();
	limpa_tela();

	//caso o arquivo nao tenha nenhuma venda cadastrado na data procurada
	if (n == 0) {
		separacao_traco(26);
		printf("\nNenhuma Venda Registrada!\n");
		separacao_traco(26);
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return;
	}

	//organiza os produtos por ordem crescente de id
	carrinho aux;
	for(i = 0; i < n; i++) {
		for(j = 1; j < n; j++) {
			if (p[j].id < p[j-1].id) {
				aux = p[j-1];
				p[j-1] = p[j];
				p[j] = aux;
			}
		}
	}


	separacao_traco(30);
	printf("RELATORIO DE VENDAS");
	separacao_traco(31);
	printf("\n          \t\t\tData = %02d/%02d/%d\n", dataCompra % 100, (dataCompra % 10000)/100, dataCompra/10000 );
	separacao_traco(80);
	printf("\nId |\tProduto\t\t\t| Quantidade\t|  Valor Und.\t|  Valor Total\n");
	separacao_traco(80);
	printf("\n");

	//imprime todos os produtos vendidos da data buscada
	for(i = 0; i < n; i++) {
		printf("\n%d   ", p[i].id);
		printf("%s", p[i].nome);
		espacamento_tabela(p[i].nome, 33);
		printf("%.2f\t", p[i].quantidade);
		printf("    R$ %.2f\t   R$ %.2lf\n",p[i].preco, p[i].preco * p[i].quantidade);
		quantidade += p[i].quantidade;
		total += (p[i].preco * p[i].quantidade);
	}

    printf("\n");
    separacao_traco(80);
    //imprime quantidade de produtos e valor arrecadado da data buscada
    printf("\nTotal de produtos vendidos = %.0f", quantidade);
    printf("\nQuantidade arrecadada = R$ %.2f\n", total);
    separacao_traco(80);

	//libera a memoria que foi alocada para guardar os vetores para imprimir o relatorio
    free(p);

	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();

}

//le o arquivo de relatorio de vendas e aloca na memoria
void ler_arquivo_relatorio()
{
	limpa_tela();
	carrinho *p = 0;
    int i = 0, n = 0, dataProcurada, dataAuxiliar, teste;
	carrinho auxiliar;
	dataProcurada = recebe_data();
	FILE *f = fopen("RelatorioDeVendas.txt", "r");
	if (f == 0) {
		FILE *f = fopen("RelatorioDeVendas.txt", "w");
        f = f;
		return;
	}

	while(fscanf(f, "%d\n%[^\n]\n%f\n%f\n%d\n", &auxiliar.id, auxiliar.nome, &auxiliar.quantidade, &auxiliar.preco, &dataAuxiliar) == 5) {
		if(dataAuxiliar == dataProcurada) {
			if (n == 0) {
				//aloca memoria para o 1 produto encotrado da data procurada
				p = (carrinho*) malloc(sizeof(carrinho));
				if(p == 0) printf("Erro no malloc");
				n++;
				p[n-1] = auxiliar; //guarda o vetor na memoria alocada
			}	else {
					teste = 0;
					//verifica se um novo produto realizado em uma compra difrente ja teve a memoria
					//alocada, caso sim aumenta apenas a quantidade no produto
					for(i = 0; i < n; i++){
						if (auxiliar.id == p[i].id){
							teste = 1; // se teste for igual 1, então a id do produto já foi alocado em memória
							p[i].quantidade += auxiliar.quantidade;
						}
					}
					//caso um novo produto seja encotrado, aloca memoria para o mesmo
					if(!teste){
						p = (carrinho*) realloc(p, (n+1) * sizeof(carrinho));
						if(p == 0) printf("Erro no realloc");
						n++;
						p[n-1] = auxiliar; //guarda o vetor na memoria alocada
					}
				}
		}
	}

	fclose(f);
	//aponta os locais de memoria em que vetores foram guardados para a funcao imprime_relatorio
	imprime_relatorio(p, n, dataAuxiliar);
}
