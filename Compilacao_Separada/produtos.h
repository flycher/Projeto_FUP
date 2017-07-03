//estrutura para dados dos produtos
typedef struct{
    int id;
    char nome[33];
    float preco;
} produto;

//funcao para ler os dados do arquivo
produto* ler_lista_produtos_txt (produto *vetor, int *n);

//funcao para escrever os dados no arquivo
void produto_para_arquivo(produto vetor[], int n);

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
