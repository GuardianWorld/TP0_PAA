#include "../header/arte.h"
//                   *       * *
//Utiliza    *,     *** ou    *  para fazer artes.
//                   *       * *

void inicializa(char vetor[18][78])
{
	int x, y;
	for (x = 0; x < 18; x++)
	{
		for (y = 0; y < 78; y++)
		{
			vetor[x][y] = ' ';
		}
	}

}

void selecionaFigura(char vetor[18][78], int y, int tipoFigura)
{
	int pivotX = 0, pivotY = 0;
	int h = 0; // Cuida do for
	//===Inicializa Y corretamente===//
	
	if (y >= 100)
	{
		y = 100;
	}
	else if (y <= 0)
	{
		y = rand() % 101;
	}

	//Coloca as figuras corretamente//
	if (tipoFigura == 1) //Faça uma imagem com asteriscos aleatorios. Figura 1
	{
		for (h = 0; h < y; h++)
		{
			pegarPivot(&pivotX, &pivotY, 0, 0); //Pega o centro da figura, como a figura e 1x1, ela fica no centro.
			h -= figura1(vetor, pivotX, pivotY);
		}
	}
	else if (tipoFigura == 2) //Faça uma imagem com a figura 2 aleatorios.
	{
		for (h = 0; h < y; h++)
		{
			pegarPivot(&pivotX, &pivotY, 2, 2); //Pega o centro da figura, como a figura e 1x1, ela fica no centro.
			h -= figura2(vetor, pivotX, pivotY);
		}
	}
	else if (tipoFigura == 3) //Faça uma imagem com a figura 3 aleatorios.
	{
		for (h = 0; h < y; h++)
		{
			pegarPivot(&pivotX, &pivotY, 2, 2); //Pega o centro da figura, como a figura e 1x1, ela fica no centro.
			h -= figura3(vetor, pivotX, pivotY);
		}
	}
	else if (tipoFigura == 4) //Faça uma imagem com uma mistura das figuras acima.
	{
		for (h = 0; h < y; h++)
		{
			h -= figuraAleatoria(vetor,pivotX,pivotY);
		}
	}
	else
	{
		artePropria(vetor);
	}
}

void imprime(char vetor[18][78])
{
	int h = 0, j = 0, k = 0;
	printf(" --------------------------------------------------------------------------------\n");
	for (h = 0; h < 18; h++)
	{
		k = 0;
		for (j = 0; j < 80; j++)
		{
			if (j == 0)
			{
				printf(" |");
			}
			else if (j == 79)
			{
				printf("|\n");
			}
			else
			{
				printf("%c", vetor[h][k]);
				k++;
			}
		}
	}
	printf(" --------------------------------------------------------------------------------\n");
}

void pegarPivot(int *pivotX, int *pivotY, int m, int k) // Pivox X, Y e um modificador, usado para todas as figuras.
{
	*pivotX = rand() % (18 - m);
	*pivotY = rand() % (78 - k);
}

int figura1(char vetor[18][78], int pivotX, int pivotY)
{
	if (vetor[pivotX][pivotY] != '*') // Verifica se o Pivot esta ocupado.
	{
		vetor[pivotX][pivotY] = '*';
		return 0;
	}
	else
	{		return 1;	}
}
int figura2(char vetor[18][78], int pivotX, int pivotY)
{
	pivotX += 1; // Evita a coordenada X de chegar no 0 nos casos normais, podendo assim causar bugs.
	pivotY += 1; // Evita a coordenada Y de chegar no 0 nos casos normais, podendo assim causar bugs.

	if (vetor[pivotX][pivotY] != '*' && vetor[pivotX - 1][pivotY] != '*' && vetor[pivotX + 1][pivotY] != '*' && vetor[pivotX][pivotY - 1] != '*' && vetor[pivotX][pivotY + 1] != '*')
	{
		vetor[pivotX][pivotY] = vetor[pivotX - 1][pivotY] = vetor[pivotX + 1][pivotY] = vetor[pivotX][pivotY - 1] = vetor[pivotX][pivotY + 1] = '*'; // Faz a figura 2.
		return 0;
	}
	else	{	return 1;	}
}
int figura3(char vetor[18][78], int pivotX, int pivotY)
{
	pivotX += 1; // Evita a coordenada X de chegar no 0 nos casos normais, podendo assim causar bugs.
	pivotY += 1; // Evita a coordenada Y de chegar no 0 nos casos normais, podendo assim causar bugs.

	if (vetor[pivotX][pivotY] != '*' && vetor[pivotX - 1][pivotY - 1] != '*' && vetor[pivotX + 1][pivotY - 1] != '*' && vetor[pivotX - 1][pivotY + 1] != '*' && vetor[pivotX + 1][pivotY + 1] != '*')
	{
		vetor[pivotX][pivotY] = vetor[pivotX - 1][pivotY - 1] = vetor[pivotX + 1][pivotY - 1] = vetor[pivotX - 1][pivotY + 1] = vetor[pivotX + 1][pivotY + 1] = '*'; // Faz a figura 3.
		return 0;
	}
	else	{	return 1;	}
}
int figuraAleatoria(char vetor[18][78], int pivotX, int pivotY)
{
	int o = 1 + rand() % 3; // Pega uma figura aleatoria das acimas;
	if (o == 1)
	{
		pegarPivot(&pivotX, &pivotY, 0, 0);
		return figura1(vetor,pivotX,pivotY);
	}
	else if (o == 2)
	{
		pegarPivot(&pivotX, &pivotY, 2, 2);
		return figura2(vetor, pivotX, pivotY);
	}
	else
	{
		pegarPivot(&pivotX, &pivotY, 2, 2);
		return figura3(vetor, pivotX, pivotY);
	}
}

void artePropria(char vetor[18][78])
{
	//Inicialização das Variaveis a serem usadas
	int h = 0, o = 0; // Uso nos For
	int m = rand() % 11; // Auxiliar de Altura
	int cont = 0; //Auxiliar
	int vazio = 0, vazio2 = 0; //Checa se nada foi colocado a muito tempo
	int pivotX = 0;
	short int cooldown = 0; //Verifica se arvores não estão sendo colocadas muito rapidamentes
	short int chao[78]; // Salva a altura do terreno.

	//Criação do chão com aleatoriedade
	for (h = 0; h < 78; h++)
	{
		if (cont <= 0) // Continuo, evita de ter picos de 1 bloco de tamanho;
		{
			if (m < 16 && rand() % 3 == 2)
			{
				m += rand() % 2;
				cont = 2;
			}
			else if (m > 0 && rand() % 3 == 0)
			{
				m -= rand() % 2;
				cont = 2;
			}
		}
		cont--;

		if (m >= 0)
		{
			vazio = figura1(vetor, (17 - m), h); // 0 a 17 de altura (18, M e a altura desejada.)
		}
		chao[h] = 17 - m;
	}

	//Criação dos props
	for (h = 0; h < 78; h++)
	{
		//Pedras internas
		if (rand() % 3 == 0 || vazio == 5)
		{
			pivotX = rand() % (18 - chao[h]);
			//printf("chao = %d pivotX: %d\n",chao[h], pivotX);
			cont = figura1(vetor, 17 - pivotX, h);
			if (rand() % 3 == 0)
			{
				pivotX = rand() % (18 - chao[h]);
				cont = figura1(vetor, 17 - pivotX, h);
			}
			vazio = 0;
		}
		else
		{
			vazio++;
		}
		//Arvores
		if (rand() % 2 == 0 && cooldown == 0 || vazio2 == 12)
		{
			if (h < 75 && h > 2)
			{
				if (chao[h + 1] == chao[h])
				{
					int arvore = (1 + rand() % 5) + 3; // Tronco com 1 a 5 de altura + 3 de altura para as folhas (4 a 8 de altura)
					if ((chao[h] - arvore) - 1 >= 0) //Checa se a altura vai ser capaz de suportar a arvore
					{
						//printf("chao = %d Arvore = %d X = %d\n", chao[h], arvore, h);
						for (o = 0; o < (arvore - 2); o++) //colocar tronco na direita
						{
							cont = figura1(vetor, chao[h] - o, h);
							cont = figura1(vetor, chao[h] - o, h + 1);
						}
						cont = figura3(vetor, chao[h] - arvore, h + 1);
						cont = figura3(vetor, chao[h] - arvore, h - 2);
					}
				}
			}
			cooldown = 5;
			vazio2 = 0;
		}
		else
		{
			cooldown--;
			vazio2++;
		}
	}
}