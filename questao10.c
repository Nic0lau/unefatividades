#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define QTD 5
#define TAMANHO_BUF 32

void
questao10(void)
{
	char buf[TAMANHO_BUF];
	long long numeros[QTD];
	long long busca;
	size_t i;

	printf("\nEste programa lê uma lista de %d números e depois\nbusca um número informado pelo usuário\nna lista, imprimindo seu índice, se a\nlista o contiver.\n\n\n", QTD);

	for (i = 0; i < QTD;) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Insira o %zu° número:", i + 1);

		numeros[i] = le_num_lld(buf, TAMANHO_BUF);

		if (errno == 0)
			i++;
	}
	
	while (1) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Insira o número que deseja buscar na lista:");

		busca = le_num_lld(buf, TAMANHO_BUF);

		if (errno == 0)
			break;
	}
	
	for (i = 0; i < QTD; i++) {
		if (numeros[i] == busca) {
			printf("O número %lld está na %zuª posição.\n", busca, i + 1);
			break;
		}
	}

	if (i == QTD)
		printf("O número %lld não está presente nesta lista.\n", busca);
}
