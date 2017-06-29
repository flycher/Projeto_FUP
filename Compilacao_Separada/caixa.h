//estrutura para funcao de compras
typedef struct{
	int id;
    char nome[51];
    float preco;
    int quantidade;
} carrinho;

//funcao para registrar compra
void iniciar_compra (produto *p, int *n);
