//para compilaçao separada
//gcc -c *c && gcc *o -o Programa_Mercado && ./Programa_Mercado
//ou
//gcc principal.c interface.c produtos.c opcoes.c caixa.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"

//funcao principal
int main()
{
	int qtd = 0;

	produto *mercadoria = 0;

    //carregando();

	mercadoria = ler_arquivo_produtos(mercadoria, &qtd);   //le os dados do arquivo
	menu_principal(mercadoria, &qtd); //chama menu principal

    return 0;
}
