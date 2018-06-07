//estrutura para dados dos produtos
typedef struct{
    int id;
    char nome[31];
    float preco;
} produto;

//funcao para ler os dados do arquivo de produtos cadastrados e aloca na memoria
produto* ler_arquivo_produtos(produto *prods, int *qtd);

//funcao para escrever os dados no arquivo
void produto_para_arquivo(produto prods[], int qtd);

//funcao para cadastrar produto
produto* cadastra_produto(produto *prods, int *qtd);

//funcao para atualizar produto
void atualiza_produto(produto *prods, int *qtd);

//funcao para remover produto
produto* remove_produto(produto *prods, int *qtd);

//funcao para consultar produto
void consulta_produto(produto *prods, int *qtd);

//funcao para imprimir todos os produtos cadastrados
void imprime_produtos(produto *prods, int *qtd);
