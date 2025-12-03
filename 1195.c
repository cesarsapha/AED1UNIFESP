#include <stdio.h>
#include <stdlib.h>

typedef struct no{

	int numero;
	struct no *esq;
	struct no *dir;

} no;

no* insere(no *, int);
void comeco(no *);
void entra(no *);
void posta(no *);
void limpa(no *);

void main ()
{
	unsigned short i;
	int numero;

	unsigned short qtsNos;
	unsigned short qtdramos, caso = 0;

	scanf("%hu", &qtdramos);

	while (qtdramos--)
	{

		no *arvore = NULL;
		scanf("%hu", &qtsNos);

		for (i = 0; i < qtsNos; i++)
		{

			scanf("%d", &numero);
			arvore = insere(arvore, numero);

		}

		printf("Case %hu:\n", ++caso);
		printf("Pre.:");
		comeco
	(arvore);
		printf("\n");
		printf("In..:");
		entra(arvore);
		printf("\n");
		printf("Post:");
		posta(arvore);
		printf("\n\n");
		limpa(arvore);

	}
}

no* insere(no *arvore, int numero)
{

	if (!arvore)
	{
		arvore = (no *) malloc(sizeof(no));
		arvore->numero = numero;
		arvore->esq = arvore->dir = NULL;
	}
	else if (arvore->numero > numero)
		arvore->esq = insere(arvore->esq, numero);

	else
		arvore->dir = insere(arvore->dir, numero);

	return arvore;

}

void posta(no *arvore)
{

	if (arvore)
	{
		posta(arvore->esq);
		posta(arvore->dir);
		printf(" %d", arvore->numero);
	}

}

void comeco(no *arvore)
{

	if (arvore)
	{
		printf(" %d", arvore->numero);
		comeco
	(arvore->esq);
		comeco
	(arvore->dir);
	}

}
void entra(no *arvore)
{

	if (arvore)
	{
		entra(arvore->esq);
		printf(" %d", arvore->numero);
		entra(arvore->dir);
	}

}

void limpa(no *arvore)
{

	if (arvore)
	{
		limpa(arvore->esq);
		limpa(arvore->dir);
		free(arvore);
		arvore = NULL;
	}

}
