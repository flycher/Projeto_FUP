//para compilaçao separada
//gcc -c *c && gcc *o -o Programa_Mercado && ./Programa_Mercado
//ou
//gcc principal.c interface.c produtos.c opcoes.c caixa.c relatorio.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "opcoes.h"
#include "caixa.h"
#include "relatorio.h"

//funcao principal
int main()
{
    int qtd = 0;

    produto *prods = 0;

    carregando(); //simula um carregando do programa, proposito apenas visual

    prods = ler_arquivo_produtos(prods, &qtd); //le os dados do arquivo
    menu_principal(prods, &qtd); //chama menu principal

    return 0;
}
