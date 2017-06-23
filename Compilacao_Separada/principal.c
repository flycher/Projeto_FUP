//atalho para compilaçao separada
//gcc principal.c interface.c produtos.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
//#include "opcoes.h"
//#include "caixa.h"
//#include "arquivos.h"

//simular carregamento na abertura do programa(nao essencial ao programa)
void carregando()
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

//funcao para ler os produtos ja cadastrados do arquivo
produto* ler_lista_produtos_txt (produto *vetor, int *n)
{
    int i = 0;
	produto auxiliar;

	FILE *f = fopen("ProdutosCadastrados.txt", "r");
	if (f == 0) {
		FILE *f = fopen("ProdutosCadastrados.txt", "w");
        f = f;
		return vetor;
	}

	while(fscanf(f, "%d\n%[^\n]\n%f\n", &auxiliar.id, auxiliar.nome, &auxiliar.preco) == 3) {

    	if ((*n) == 0) {
    		vetor = (produto*) malloc(sizeof(produto));
            if(vetor == 0) printf("Erro no malloc");
    	}	else {
    			vetor = (produto*) realloc(vetor, ((*n)+1) * sizeof(produto));
    			if(vetor == 0) printf("Erro no realloc");
    		}

		vetor[i] = auxiliar;
    	i++;
    	(*n)++;
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

//funcao principal
int main()
{
	int opcao, qtd = 0;
	produto *mercadoria = 0;

    //carregando(); //nao estou utilizando devido ao tempo de espera que a funcao adiciona

	mercadoria = ler_lista_produtos_txt(mercadoria, &qtd);

	while (1) {
		system("clear");
    	menu_principal();
    	scanf("%d", &opcao);

    	switch (opcao) { //opcoes menu principal
			case 1 :
				while (1) {
					system("clear");
					menu_produtos();
					scanf("%d", &opcao);

					switch (opcao) { //opcoes menu produtos

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
							//vai fazer o programa carregar novamente, nao acho q seja uma boa opçao
							//pensar em uma alternativa
							return main();
				    		break;

						default:
					    	system("clear");
					    	printf("\nOpção Inválida!\n");
					    	printf("\nPrecione ENTER para voltar\n");
					    	getchar();
					    	getchar();

					}
				}

			case 2 :
				system("clear");
				em_construcao();
				break;

			case 3 :
				system("clear");
				em_construcao();
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
