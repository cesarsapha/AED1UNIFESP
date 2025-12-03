#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	unsigned short numero;
	unsigned short posicao;

} pessoa;


void main ()
{
	unsigned short numerodepessoas, pessoasquesairam;
	unsigned short i, idPessoa;
	pessoa fila[51000];

	scanf("%hu", &numerodepessoas);

	memset(fila, 0, sizeof(fila));

	for (i = 0; i < numerodepessoas; i++)
	{
		scanf("%hu", &idPessoa);
		fila[i].numero = idPessoa;
		fila[idPessoa].posicao = i;

	}

	scanf("%hu", &pessoasquesairam);

	for (i = 0; i < pessoasquesairam; i++)
	{
		scanf("%hd", &idPessoa);
		fila[fila[idPessoa].posicao].numero = 0;
    }

	bool comeco = false;
	for (i = 0; i < numerodepessoas; i++)
		if (fila[i].numero)
		{
			if (comeco == true && i != numerodepessoas)
				printf(" ");

			comeco = true;
			printf("%hu", fila[i].numero);
		}

	printf("\n");
}
