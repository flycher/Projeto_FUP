#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nao estou utilizando devido ao tempo de espera que a funcao adiciona
/*
//simular carregamento na abertura do programa
void inicializa ()
{
	int x, carregado = 0;

	while ( carregado != 106) {
    	system("clear");
    	printf("\tBEM VINDO!");
    	if (carregado <= 100) printf("\n\n\nCarregando: %d / 100.\n", carregado);
    	   else printf("\n\n\nCarregando: 100 / 100.\n");

        while (1) {
			if ( carregado < 90 ) x = rand() % 5000000;
			   else x = rand() % 18000000;
			if (x == 1){
				carregado++;
				break;
			}
        }
    }

}
*/
//estrutura para dados dos produtos
typedef struct{
    int id;
    char nome[51];
    float preco;
} produto;

//funcoes para usar arquivo apresenta segmentation fault
/*
//funcao para ler os produtos ja cadastrados do arquivo
produto* ler_lista_produtos_txt (produto *vetor, int *n)
{
    int i = 0;
	produto auxiliar;
	FILE *f = fopen("ProdutosCadastrados.txt", "r");
	if (f == 0) {
        printf("** ERRO, Arquivo Inacessível! **");
	}

	while(fscanf(f, "%d\n%[^\n]\n%f\n", &auxiliar.id, auxiliar.nome, &auxiliar.preco) == 3) {

    	if ((*n) == 0) {
    		vetor = (produto*) malloc(sizeof(produto));
            if(vetor == 0) {
            printf("Erro no malloc");
    	}	else {
    			vetor = (produto*) realloc(vetor, ((*n)+1) * sizeof(produto));
    			if(vetor == 0) {
    			printf("Erro no realloc");
    			}
    		}

    	vetor[i].id = auxiliar.id;
    	strcpy(vetor[i].nome, auxiliar.nome);
    	vetor[i].preco = auxiliar.preco;
    	i++;
    	(*n)++;
    	}
    }

	return vetor;
}

//funcao para passar os produtos no arquivo
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
*/
//funcao para cadastrar os produtos
produto* cadastra_produto (produto *p, int *n)
{
	system("clear");

	produto auxiliar;
    printf("\t--CADASTRO DO PRODUTO--\n\n");
    printf("Insira a ID: ");
	scanf(" %d", &auxiliar.id);
	printf("Insira o nome: ");
	scanf(" %50[^\n]", auxiliar.nome);
	printf("Insira o preco: ");
	scanf(" %f", &auxiliar.preco);

	//produto_para_arquivo(p, (*n));

	if ((*n) == 0) {
		p = (produto *) malloc(sizeof(produto));
		(*n)++;
	}	else {
			p = (produto *) realloc(p, ((*n)+1) * sizeof(produto) );
			(*n)++;
			if(p == 0){
				printf("Erro no Relloc");
				return 0;
			}
		}

	p[(*n) - 1] = auxiliar;
	return p;
}

void atualiza_produto (produto *p, int *n)
{
	int i, aux;
	system("clear");
	system("clear");
    printf("Insira o Código ID do Produto: ");
    scanf("%d", &aux);

	for(i = 0; i < (*n); i++){
		if (aux == p[i].id) {
            printf(" Nome: %s\n", p[i].nome );
    		printf(" Preco: RS %.2f\n", p[i].preco);
            printf("\nInsira o novo Nome do Produto: ");
            scanf("\n%50[^\n]", p[i].nome);
            printf("Insira o novo Preço do Produto: ");
    		scanf("%f", &p[i].preco);
        }
    }
    printf("\n-----------------------\n");
    printf("  Produto Atualizado!\n");
    printf("-----------------------\n");
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

produto* remove_produto(produto *p, int *n)
 {
     system("clear");

     int i, aux;
     printf("Insira o Código ID do Produto: ");
     scanf("%d", &aux);
     for (i = 0; i < (*n); i++) {
         if (aux == p[i].id) {
             printf(" Nome: %s\n", p[i].nome );
     		 printf(" Preco: RS %.2f\n", p[i].preco);
             p[i] = p[(*n) - 1];
             p = (produto*) realloc(p, (*n-1) * sizeof(produto));
         }
    }
    printf("\n-----------------------\n");
    printf("  Produto Removido!\n");
    printf("-----------------------\n");
 	printf("\nPrecione ENTER para voltar\n");
 	getchar();
 	getchar();
     (*n)--;
     return (p);
}

void consulta_produto (produto *p, int *n)
{
	int i, aux;
	system("clear");
	system("clear");
    printf("Insira o Código ID do Produto: ");
    scanf("%d", &aux);

	for(i = 0; i < (*n); i++){
		if (aux == p[i].id) {
            printf(" Nome: %s\n", p[i].nome );
    		printf(" Preco: RS %.2f\n", p[i].preco);
        }
    }
    printf("-----------------------\n");
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

//funcao para imprimir todos os produtos cadastrados
void imprime_produtos (produto *p, int *n)
{
	int i;
	system("clear");
	system("clear");
	printf("\t--LISTA DE PRODUTOS--\n\n--------------------------\n");
	if ((*n) == 0) printf("Nenhum Produto Registrado!\n--------------------------\n");
    	else{
        	for(i = 0; i < (*n); i++){
        		printf(" Id: %d\n", p[i].id);
        		printf(" Nome: %s\n", p[i].nome );
        		printf(" Preco: RS %.2f\n", p[i].preco);
        		printf("-----------------------\n");
        	}
        }
	printf("\nPrecione ENTER para voltar\n");
	getchar();
	getchar();
}

//funcao para imprimir o menu de opcoes
void print_menu_principal ()
{
	printf("\t--MENU INICIAL--\t%s\n\n", __DATE__);
	printf(" [1] - Cadastrar Produto.\n");
	printf(" [2] - Atualizar Produto.\n");
	printf(" [3] - Remover Produto.\n");
	printf(" [4] - Consultar Produto.\n");
	printf(" [5] - Verificar Produtos Cadastrados.\n");
	//printf(" [6] - Abrir Caixa.\n");
	//printf(" [7] - Imprimir Relatorio de Vendas.\n");
	printf(" [9] - Encerrar Programa.\n");
	printf("\nO que deseja? ");
}

//funcao principal
int main()
{
	int opcao, qtd = 0;
	produto *mercadoria = 0;

    //inicializa();

	//mercadoria = ler_lista_produtos_txt(mercadoria, &qtd);

	while (1) {
    	system("clear");
    	print_menu_principal();
    	scanf("%d", &opcao);

    	switch (opcao) {
    		case 1 :
    			mercadoria = cadastra_produto(mercadoria, &qtd);
    			break;

            case 2 :
        		atualiza_produto(mercadoria, &qtd);
        		break;

            case 3 :
            	mercadoria = remove_produto(mercadoria, &qtd);
            	break;

            case 4 :
        		consulta_produto(mercadoria, &qtd);
        		break;

    		case 5 :
    			imprime_produtos(mercadoria, &qtd);
    			break;

    		case 9 :
    			system("clear");
    			printf("Volte sempre!\n");
    			return 0;
    			break;

    		default:
    		system("clear");
    		printf("\nOpção Inválida!\n");
    		printf("\nPrecione ENTER para voltar\n");
    		getchar();
    		getchar();

    	}
    }

    return 0;
}
