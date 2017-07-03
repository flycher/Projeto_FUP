//atalho para compilaçao separada
//gcc -c *c && gcc *o -o Programa_Mercado && ./Programa_Mercado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"

int main()
{
	int qtd = 0;

	produto *mercadoria = 0;

    carregando(); //nao estou utilizando devido ao tempo de espera que a funcao adiciona

	mercadoria = ler_lista_produtos_txt(mercadoria, &qtd);   //le os dados do arquivo
	menu_principal(mercadoria, &qtd); //chama menu principal

    return 0;
}
