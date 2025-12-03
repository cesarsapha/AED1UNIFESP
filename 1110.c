#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct Cartas 
	{	char carta;		
        struct Cartas *prox;	
    };
typedef struct Cartas Cartas;

struct desempilha 
	{ 	Cartas *topo, *final;				
        int qtd;			
    };
typedef struct desempilha PILHA;

int main()
{
	int descarta[55], Cqtd, c=0, k=0;
	PILHA	baralho;
	Cartas *aux;

	while (scanf("%d", &Cqtd) && Cqtd != 0)
	{
		for(c=0; c < 55; c++)
			descarta[c] = 0;

		k = 0;

		baralho.topo = NULL;
		baralho.qtd = 0;

		for(c=Cqtd; c > 0; c--)
		{
			aux = (Cartas *) malloc(sizeof(Cartas));

			if(aux == NULL)
				break;

			aux->carta = c;
			aux->prox = baralho.topo;

			baralho.topo = aux;
			baralho.qtd++;

			if(c == Cqtd)
				baralho.final = aux;
		}

		while (baralho.qtd >= 2)
		{
			aux = baralho.topo;
			baralho.topo = aux->prox;
			descarta[k] = aux->carta;
			free(aux);
			baralho.qtd--;
			k++;
			aux = baralho.topo->prox;
			baralho.final->prox = baralho.topo;
			baralho.final = baralho.topo;
			baralho.topo = aux;
		}

		printf("Descartadas");
		for(c=0; c < k; c++)
		{
			printf(" %d", descarta[c]);
			if(c != k-1)
				printf(",");
		}
		printf("\nCartas que sobraram %d\n", baralho.final->carta);
	}

	return 0;
}
