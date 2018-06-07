#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"
#include "relatorio.h"

//funcao para ler os dados do arquivo de produtos cadastrados e aloca na memoria
produto* ler_arquivo_produtos(produto *mercadorias, int *qtd)
{
    int i = 0;
    produto auxiliar;

    FILE *f = fopen("ProdutosCadastrados.txt", "r");
    if (f == 0) {
        FILE *f = fopen("ProdutosCadastrados.txt", "w");
        f = f;
        return mercadorias;
    }

    while(fscanf(f, "%d\n%[^\n]\n%f\n", &auxiliar.id, auxiliar.nome, &auxiliar.preco) == 3) {
        if ((*qtd) == 0) {
            mercadorias = (produto*) malloc(sizeof(produto));
            if(mercadorias == 0) printf("Erro no malloc");
        } else {
            mercadorias = (produto*) realloc(mercadorias, ((*qtd)+1) * sizeof(produto));
            if(mercadorias == 0) printf("Erro no realloc");
        }

        mercadorias[i] = auxiliar;
        i++;
        (*qtd)++;
    }

    fclose(f);
    return mercadorias;
}

//funcao para escrever os dados no arquivo
void produto_para_arquivo(produto mercadorias[], int qtd)
{
    FILE *f = fopen("ProdutosCadastrados.txt", "w");
    int i;

    if (f == 0) {
        printf("** ERRO, Arquivo Inacessível! **");
    }

    //grava o produto no arquivo
    for( i = 0; i < qtd; i++) {
        fprintf(f, "%d\n%s\n%f\n", mercadorias[i].id, mercadorias[i].nome, mercadorias[i].preco);
    }

    fclose(f);
}

//funcao para cadastrar produto
produto* cadastra_produto(produto *mercadorias, int *qtd)
{
    limpa_tela();

    int i;
    produto auxiliar;
    printf("--CADASTRO DE PRODUTO--\n");
    separacao_traco(23);
    printf("\nInsira a ID: ");
    scanf(" %d", &auxiliar.id);

    //verifica se algum produto esta cadastrado
    if (auxiliar.id == 0) {
        separacao_traco(31);
        printf("\nID '0' reservado pelo sistema.\n");
        separacao_traco(31);
        printf("\nPrecione ENTER para voltar\n");
        getchar();
        getchar();
        return mercadorias;
    }

    //verifica se o id ja esta cadastrado
    for (i = 0; i < (*qtd); i++) {
        if (auxiliar.id == mercadorias[i].id) {
            separacao_traco(24);
            printf("\nCódigo ID já cadastrado!\n");
            separacao_traco(24);
            printf("\nPrecione ENTER para voltar\n");
            getchar();
            getchar();
            return mercadorias;
        }
    }

    printf("Insira o nome: ");
    scanf(" %30[^\n]", auxiliar.nome);
    printf("Insira o preco: R$ ");
    scanf(" %f", &auxiliar.preco);

    //aloca memoria para o novo produto
    if ((*qtd) == 0) {
        mercadorias = (produto *) malloc(sizeof(produto));
        (*qtd)++;
    }	else {
        mercadorias = (produto *) realloc(mercadorias, ((*qtd)+1) * sizeof(produto) );
        (*qtd)++;
        if(mercadorias == 0) {
            printf("Erro no Realloc");
            return 0;
        }
    }

    mercadorias[(*qtd) - 1] = auxiliar;
    //chama produto_para_arquivo para gravar no arquivo o novo produto
    produto_para_arquivo(mercadorias, (*qtd));

    return mercadorias;
}

//funcao para atualizar produto
void atualiza_produto(produto *mercadorias, int *qtd)
{
    limpa_tela();
    limpa_tela();

    //verifica se algum produto esta cadastrado
    if ((*qtd) == 0) {
        separacao_traco(26);
        printf("\nNenhum Produto Registrado!\n");
        separacao_traco(26);
        printf("\nPrecione ENTER para voltar\n");
        getchar();
        getchar();
        return ;
    }

    int i, aux, teste;
    limpa_tela();
    limpa_tela();
    printf("-----ATUALIZAÇÃO DE PRODUTO------\n");
    separacao_traco(33);
    printf("\nInsira o Código ID do Produto: ");
    scanf("%d", &aux);

    //caso encotre o id procurado
    teste= 0;
    for(i = 0; i < (*qtd); i++) {
        if (aux == mercadorias[i].id) {
            separacao_traco(33);
            printf("\n Nome: %s\n", mercadorias[i].nome );
            printf(" Preco: RS %.2f\n", mercadorias[i].preco);
            separacao_traco(33);
            printf("\nInsira o novo Nome do Produto: ");
            scanf("\n%30[^\n]", mercadorias[i].nome);
            printf("Insira o novo Preço do Produto: R$ ");
            scanf("%f", &mercadorias[i].preco);
            teste = 1; //teste = 1 informa que um produto com o id produrado foi encontrado
        }
    }

    //chama produto_para_arquivo para gravar no arquivo as alteracoes
    produto_para_arquivo(mercadorias, (*qtd));

    if (!teste) {
        separacao_traco(23);
        printf("\nProduto não Encontrado!\n");
    }	else {
        separacao_traco(23);
        printf("\n  Produto Atualizado!\n");
    }

    separacao_traco(23);
    printf("\nPrecione ENTER para voltar\n");
    getchar();
    getchar();
}

//funcao para remover produto
produto* remove_produto(produto *mercadorias, int *qtd)
{
    limpa_tela();
    limpa_tela();

    //verifica se algum produto esta cadastrado
    if ((*qtd) == 0) {
        separacao_traco(26);
        printf("\nNenhum Produto Registrado!\n");
        separacao_traco(26);
        printf("\nPrecione ENTER para voltar\n");
        getchar();
        getchar();
        return (mercadorias);
    }

    int i, aux, teste;
    printf("--------REMOÇÃO DE PRODUTO-------\n");
    separacao_traco(33);
    printf("\nInsira o Código ID do Produto: ");
    scanf("%d", &aux);

    //caso encotre o id procurado
    teste = 0;
    for (i = 0; i < (*qtd); i++) {
        if (aux == mercadorias[i].id) {
            separacao_traco(33);
            printf("\n Nome: %s\n", mercadorias[i].nome );
            printf(" Preco: RS %.2f\n", mercadorias[i].preco);
            mercadorias[i] = mercadorias[(*qtd) - 1];
            mercadorias = (produto*) realloc(mercadorias, (*qtd-1) * sizeof(produto));
            teste = 1; //teste = 1 informa que um produto com o id produrado foi encontrado
        }
    }

    if (!teste) {
        separacao_traco(23);
        printf("\nProduto não Encontrado!\n");
    }	else {
        separacao_traco(23);
        printf("\n  Produto Removido!\n");
    }
    separacao_traco(23);
    printf("\nPrecione ENTER para voltar\n");
    getchar();
    getchar();
    (*qtd)--;

    //chama produto_para_arquivo para remover o produto do arquivo
    produto_para_arquivo(mercadorias, (*qtd));

    return (mercadorias);
}

//funcao para consultar produto
void consulta_produto(produto *mercadorias, int *qtd)
{

    int i, aux, teste;
    limpa_tela();
    limpa_tela();

    //verifica se algum produto esta cadastrado
    if ((*qtd) == 0) {
        separacao_traco(26);
        printf("\nNenhum Produto Registrado!\n");
        separacao_traco(26);
        printf("\nPrecione ENTER para voltar\n");
        getchar();
        getchar();
        return;
    }

    printf("-------CONSULTA DE PRODUTO-------\n");
    separacao_traco(33);
    printf("\nInsira o Código ID do Produto: ");
    scanf("%d", &aux);

    //caso encotre o id procurado
    teste = 0;
    for(i = 0; i < (*qtd); i++) {
        if (aux == mercadorias[i].id) {
            separacao_traco(33);
            printf("\n Nome: %s\n", mercadorias[i].nome );
            printf(" Preco: RS %.2f\n", mercadorias[i].preco);
            teste = 1; //teste = 1 informa que um produto com o id produrado foi encontrado
        }
    }

    if (!teste) {
        separacao_traco(23);
        printf("\nProduto não Encontrado!\n");
    }

    separacao_traco(26);
    printf("\nPrecione ENTER para voltar\n");
    getchar();
    getchar();
}

//funcao para imprimir todos os produtos cadastrados
void imprime_produtos (produto *mercadorias, int *qtd)
{
    int i, j;
    limpa_tela();
    limpa_tela();

    //caso o arquivo nao tenha nenhum produto cadastrado
    if ((*qtd) == 0) {
        separacao_traco(26);
        printf("\nNenhum Produto Registrado!\n");
        separacao_traco(26);
        printf("\nPrecione ENTER para voltar\n");
        getchar();
        getchar();
        return;
    }

    //organiza os produtos por ordem crescente de id
    produto aux;
    for(i = 0; i < (*qtd); i++) {
        for(j = 1; j < (*qtd); j++) {
            if (mercadorias[j].id < mercadorias[j-1].id) {
                aux = mercadorias[j-1];
                mercadorias[j-1] = mercadorias[j];
                mercadorias[j] = aux;
            }
        }
    }

    //imprime todos os produtos cadastrados
    printf("----LISTA DE PRODUTOS-----\n");
    separacao_traco(26);
    for(i = 0; i < (*qtd); i++) {
        printf("\n Id: %d\n", mercadorias[i].id);
        printf(" Nome: %s\n", mercadorias[i].nome );
        printf(" Preco: RS %.2f\n", mercadorias[i].preco);
        separacao_traco(26);
    }

    printf("\nPrecione ENTER para voltar\n");
    getchar();
    getchar();
}
