#include "produtos.h"

////estrutura para dados dos produtos do carrinho
typedef struct{
	int id;
    char nome[31];
    float preco;
    float quantidade;
} carrinho;

//funcao para registrar compra
void iniciar_compra(produto *prods, int *qtd);
