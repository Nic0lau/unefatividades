#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define NOTAS_QTD 5
#define TAMANHO_BUF 32

void
questao9(void)
{
	char buf[TAMANHO_BUF];
	long double notas[NOTAS_QTD];
	size_t i;

	printf("\nEste programa lê uma sequência de %d números e informa\na média aritmética simples da distribuição.\n\n\n", NOTAS_QTD);

	for (i = 0; i < NOTAS_QTD;) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Insira o %zu° número:", i + 1);

		notas[i] = le_num_ld(buf, TAMANHO_BUF);

		if (errno == 0 && notas[i] >= 0)
			i++;
	}

	for (notas[0] /= NOTAS_QTD, i = 1; i < NOTAS_QTD; i++)
		notas[0] += notas[i]/NOTAS_QTD;

	printf("A média aritmética simples dos números é %Lf\n", notas[0]);
}
