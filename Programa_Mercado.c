#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura para dados dos produtos
typedef struct{
    int id;
    char nome[31];
    float preco;
} produto;

//estrutura para funcao de compras
typedef struct{
	int id;
    char nome[31];
    float preco;
    float quantidade;
} carrinho;

//limpa o terminal no linux e windows
void clear_screen()
{
	#ifdef _WIN32
	system("cls");
	#endif

	#ifdef linux
	system("clear");
	#endif	
}

//simular carregamento na abertura do programa(nao essencial ao programa)
void carregando()
{
	int x, carregado = 0;

	while ( carregado < 106) {
    	clear_screen();
    	printf("\tBEM VINDO!");
    	if (carregado <= 100) printf("\n\n\nCarregando: %d / 100.\n", carregado);
    	   else printf("\n\n\nCarregando: 100 / 100.\n");

        while (1) {
			if ( carregado < 90 ) x = rand() % 4000000;
			   else x = rand() % 12000000;
			if (x == 1){
				carregado++;
				break;
			}
        }
    }

}

//funcao para calcular os espacos ao imprimir o nome dos produtos na finalizaçao da compra
void espacamento_tabela(char* nome, int espaco)
{
	int i, n;
	n = strlen(nome);
	for( i = 0; i < (espaco - n); i++)	printf(" ");
 }

//funcao para imprimir funcionalidades ainda nao implementadas
void em_construcao()
{
	clear_screen();
	clear_screen();
	printf("----------------------------\n");
	printf("--Área em Desenvolvimento--");
	printf("\n----------------------------\n");
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

//funcao para imprimir o menu principal
void interface_menu_principal ()
{
	clear_screen();
	clear_screen();
	printf("\t--MENU INICIAL--\t%s\n\n", __DATE__);
	printf(" [1] - Controle de Produtos.\n");
	printf(" [2] - Iniciar Compra.\n");
	printf(" [3] - Imprimir Relatorio de Vendas.\n");
	printf(" [9] - Encerrar Programa.\n");
	printf("\nO que deseja? ");
}

//funcao para imprimir o menu de produtos
void interface_menu_produtos ()
{
	clear_screen();
	clear_screen();
	printf("\t--CONTROLE DE PRODUTOS--\t%s\n\n", __DATE__);
	printf(" [1] - Cadastrar Produto.\n");
	printf(" [2] - Atualizar Produto.\n");
	printf(" [3] - Remover Produto.\n");
	printf(" [4] - Consultar Produto.\n");
	printf(" [5] - Verificar Produtos Cadastrados.\n");
	printf(" [9] - Retornar ao Menu Inicial.\n");
	printf("\nO que deseja? ");

}

//funcao para ler os dados do arquivo
produto* ler_arquivo_produtos (produto *p, int *n)
{
    int i = 0;
	produto auxiliar;

	FILE *f = fopen("ProdutosCadastrados.txt", "r");
	if (f == 0) {
		FILE *f = fopen("ProdutosCadastrados.txt", "w");
        f = f;
		return p;
	}

	while(fscanf(f, "%d\n%[^\n]\n%f\n", &auxiliar.id, auxiliar.nome, &auxiliar.preco) == 3) {

    	if ((*n) == 0) {
    		p = (produto*) malloc(sizeof(produto));
            if(p == 0) printf("Erro no malloc");
    	}	else {
    			p = (produto*) realloc(p, ((*n)+1) * sizeof(produto));
    			if(p == 0) printf("Erro no realloc");
    		}

		p[i] = auxiliar;
    	i++;
    	(*n)++;
    }

	return p;
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
	clear_screen();

	int i;
	produto auxiliar;
    printf("--CADASTRO DE PRODUTO--\n");
	printf("-----------------------\n");
    printf("Insira a ID: ");
	scanf(" %d", &auxiliar.id);

	if (auxiliar.id == 0) {
		printf("\n-------------------------------\n");
		printf("ID '0' reservado pelo sistema.");
		printf("\n-------------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return p;
	}

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
	scanf(" %30[^\n]", auxiliar.nome);
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
	 clear_screen();
	 clear_screen();

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
	clear_screen();
	clear_screen();
	printf("--ATUALIZAÇÃO DE PRODUTO--\n");
	printf("---------------------------------\n");
    printf("Insira o Código ID do Produto: ");
	scanf("%d", &aux);

	for(i = 0; i < (*n); i++){
		if (aux == p[i].id) {
			printf("---------------------------------\n");
            printf(" Nome: %s\n", p[i].nome );
    		printf(" Preco: RS %.2f\n", p[i].preco);
			printf("---------------------------------\n");
            printf("\nInsira o novo Nome do Produto: ");
            scanf("\n%30[^\n]", p[i].nome);
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
     clear_screen();
	 clear_screen();

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
	 printf("--REMOÇÃO DE PRODUTO--\n");
 	printf("---------------------------------\n");
     printf("Insira o Código ID do Produto: ");
     scanf("%d", &aux);
     for (i = 0; i < (*n); i++) {
         if (aux == p[i].id) {
			 printf("---------------------------------\n");
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
	clear_screen();
	clear_screen();

	if ((*n) == 0) {
		printf("--------------------------\n");
		printf("Nenhum Produto Registrado!");
		printf("\n--------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return;
	}

	printf("--CONSULTA DE PRODUTO--\n");
	printf("---------------------------------\n");
    printf("Insira o Código ID do Produto: ");
    scanf("%d", &aux);

	for(i = 0; i < (*n); i++){
		if (aux == p[i].id) {
			printf("---------------------------------\n");
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
	clear_screen();
	clear_screen();

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

//funcao para registrar compra
void iniciar_compra (produto *p, int *n)
{
	int i, c = 0, aux, teste1, teste2;
	float total_compra = 0, troco, qtd_compra = 0, qtd_produtos = 0;
	carrinho *compra;

	clear_screen();
	clear_screen();

	if ((*n) == 0) {
		printf("--------------------------\n");
		printf("Nenhum Produto Registrado!");
		printf("\n--------------------------\n");
		printf("\nPrecione ENTER para voltar\n");
		getchar();
		getchar();
		return;
	}

	while(1) {
		clear_screen();
		printf("\t\tCARRINHO\n");
		printf("----------------------------------------\n");
		printf("Insira ID '0' para encerrar compra\n");
		printf("Total parcial R$ %.2f\n", total_compra);
		printf("----------------------------------------\n");
		printf("Insira ID do produto.\n");
		scanf(" %d", &aux);

		if (aux == 0) {
			if ( qtd_compra == 0) return;
			clear_screen();
			clear_screen();
			printf("Produto\t\t\t| Quantidade\t|  Valor Und.\t|  Valor Total\n");
			printf("-----------------------------------------------------------------------\n");
			for(i = 0; i < (c); i++) {
				printf("%s", compra[i].nome);
				espacamento_tabela(compra[i].nome, 30);
				printf("%.2f\t", compra[i].quantidade);
				printf("    R$ %.2f\t   R$ %.2lf\n",compra[i].preco, compra[i].preco * compra[i].quantidade);
			}

			printf("-----------------------------------------------------------------------\n");
			printf("Total\t\t\t|\t%.0f\t|\t\t|  R$ %.2f\n", qtd_compra, total_compra);
			printf("-----------------------------------------------------------------------\n");
			printf("Valor recebido = R$ ");
			scanf(" %f", &troco);
			if ((troco == 0) || (troco - total_compra) < 0 ) {
				printf("\nCompra cancelada.\n");
				free(compra);
				printf("\nPrecione ENTER para voltar ao menu principal\n");
				getchar();
				getchar();
				break;
			}

			troco -= total_compra;
			printf("Troco = R$ %.2f", troco);
			printf("\nObrigado pela preferencia, volte sempre!\n");
			//aqui coloca a funcao para mandar os dados da compra para o arquivo
			free(compra);
			printf("------------------------------------------------------\n");
			printf("\nPrecione ENTER para voltar ao menu principal\n");
			getchar();
			getchar();
			break;
		}

		//funcao para adicionar quantidade aos produtos que ja estao no carrinho
		teste2 = 0;
		for(i = 0; i < qtd_compra; i++){
			if ( aux == compra[i].id){
				printf(" Nome: %s\n", compra[i].nome );
				printf(" Preco: RS %.2f\n", compra[i].preco);
				printf("Insira a quantidade: ");
				scanf(" %f", &qtd_produtos);
				compra[i].quantidade += qtd_produtos;
				qtd_compra += qtd_produtos;
				total_compra += compra[i].preco * qtd_produtos;
				teste2 = 1;
			}
		}

		//funcao para adicionar novo produto ao carrinho
		teste1 = 0;
		for(i = 0; ( i < (*n) ) && (!teste2); i++){
			if (aux == p[i].id) {
				teste1 = 1;
				printf(" Nome: %s\n", p[i].nome );
				printf(" Preco: RS %.2f\n", p[i].preco);
				qtd_produtos = 1;
				printf("Insira a quantidade: ");
				scanf("%f", &qtd_produtos);
				if (qtd_produtos == 0) continue;
				qtd_compra += qtd_produtos;
				total_compra += p[i].preco * qtd_produtos;
				if (c == 0) {
					compra = (carrinho*) malloc(sizeof(carrinho) );
					(c)++;
				}	else {
						compra = (carrinho*) realloc(compra, (c+1) * sizeof(carrinho) );
						(c)++;
						if(compra == 0){
							printf("Erro no Realloc");
							return ;
						}
					}
				compra[c-1].id = p[i].id;
				strcpy(compra[c-1].nome,p[i].nome);
				compra[c-1].preco = p[i].preco;
				compra[c-1].quantidade = qtd_produtos;
			}
		}

		if (!teste1 && !teste2) {
			printf("\nID não encontrado.\n");
			printf("Precione ENTER para continuar");
			getchar();
			getchar();
		}

	}
}

//funcao para encerrar programa
void encerra_programa (produto *p)
{
	free(p);
	clear_screen();
    printf("Volte sempre!\n");
    exit(0);
}

//funcao para menu de produtos
void menu_produtos (produto *p, int *n)
{
	char opcao;

	while (opcao != '9') {
		interface_menu_produtos();
		scanf(" %c", &opcao);

		switch (opcao) { //opcoes do menu de produtos

			case '1' :
				p = cadastra_produto(p, n);
				break;

			case '2' :
				atualiza_produto(p, n);
				break;

			case '3' :
				p = remove_produto(p, n);
				break;

			case '4' :
				consulta_produto(p, n);
				break;

			case '5' :
				imprime_produtos(p, n);
				break;

			case '9' :
				menu_principal(p, n);
				break;
				
			default:
				clear_screen();
				printf("Opção Inválida!\n");
				printf("\nPrecione ENTER para voltar\n");
				getchar();
				getchar();

		}
	}
}

//funcao para menu principal
void menu_principal (produto *p, int *n)
{
	char opcao;

	while (1) {
		interface_menu_principal();
		scanf(" %c", &opcao);

		switch (opcao) { //opcoes do menu principal
			case '1' :
				menu_produtos(p, n);
				break;

			case '2' :
				iniciar_compra(p, n);
				break;

			case '3' :
				clear_screen();
				em_construcao();
				break;

    		case '9' :
				encerra_programa(p);
    			break;

    		default:
	    		clear_screen();
	    		printf("Opção Inválida!\n");
	    		printf("\nPrecione ENTER para voltar\n");
	    		getchar();
	    		getchar();
		}
	}
}

int main()
{
	int qtd = 0;

	produto *mercadoria = 0;

    carregando(); //nao estou utilizando devido ao tempo de espera que a funcao adiciona

	mercadoria = ler_arquivo_produtos(mercadoria, &qtd);   //le os dados do arquivo
	menu_principal(mercadoria, &qtd); //chama menu principal

    return 0;
}
