//estrutura para funcao de compras
typedef struct{
	int id;
    char nome[31];
    float preco;
    float quantidade;
} carrinho;

//funcao para registrar compra
void iniciar_compra (produto *p, int *n);
