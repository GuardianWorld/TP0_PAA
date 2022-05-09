#include <stdio.h>
#include <stdlib.h>
#include "header/arte.h"
#include "header/menu.h"
#include <time.h>


int main()
{
	int x = 0, y = 0; //Inicializa x e y para serem usados abaixo
	char tela[18][78]; // Compoe a matriz 20x80, so é inicializados a parte interna.
	srand(time(NULL)); // Randomiza a seed
	while (1) //Entra dentro da função
	{
		inicializa(tela); //Limpa a tela.
		menu(); //Chama o menu e imprime na tela.
		scanf("%d", &x);
		if (x == 0) //caso x == 0, sai do programa.
		{
			break;
		}
		else if (x > 0 && x < 6) // caso a opção seja valida entre 1 e 5.
		{
			if (x != 5)
			{
				printf(" Digite a quantidade figuras (Menor ou igual a zero para aleatorio): ");
				scanf("%d", &y);
			}
			selecionaFigura(tela, y, x);
			imprime(tela);
		}
	}
	return 0;
}
