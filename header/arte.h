#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa(char vetor[18][78]);
void selecionaFigura(char vetor[18][78], int y, int tipoFigura);
void pegarPivot(int *pivotX, int *pivotY, int m, int k);
void imprime(char vetor[18][78]);
int figura1(char vetor[18][78], int pivotX, int pivotY);
int figura2(char vetor[18][78], int pivotX, int pivotY);
int figura3(char vetor[18][78], int pivotX, int pivotY);
int figuraAleatoria(char vetor[18][78], int pivotX, int pivotY);
void artePropria(char vetor[18][78]);