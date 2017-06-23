//estrutura para dados dos produtos
typedef struct{
    int id;
    char nome[51];
    float preco;
} produto;

//funcao para cadastra produto
produto* cadastra_produto (produto *p, int *n);

//funcao para atualizar produto
void atualiza_produto (produto *p, int *n);

//funcao para remover produto
produto* remove_produto(produto *p, int *n);

//funcao para consultar produto
void consulta_produto (produto *p, int *n);

//funcao para imprimir todos os produtos cadastrados
void imprime_produtos (produto *p, int *n);
