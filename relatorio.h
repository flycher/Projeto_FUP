//retorna data atual em um inteiro para possibilitar busca no arquivo
int data_atual();

//recebe data desejada e retorna um inteiro possibilitar busca no arquivo
int recebe_data();

//funcao para escrever os dados das compras realizadas no arquivo
void carrinho_para_relatorio_arquivo(carrinho vetor[], int nTipoItens, float nProdutos, float tCompra);

//funcao para imprimir o relatorio de vendas a partir da data procurada
void imprime_relatorio (carrinho *p, int n, int dataCompra);

//le o arquivo de relatorio de vendas e aloca na memoria
void ler_arquivo_relatorio();
