#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define TAMANHO_BUF 32 

void
questao1(void)
{
	char buf[TAMANHO_BUF];
	unsigned long long total;
	long long n;

	puts("\nEste programa lê números inteiros não negativos\ndigitados pelo usuário. A entrada de um número\ninteiro negativo fá-lo imprimir a soma de todos\nos números digitados e encerra o programa.\n\n");

	total = 0;

	while (1) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Digite um número:");
		
		n = le_num_lld(buf, TAMANHO_BUF);

		if (errno != 0)
			continue;

		if (n < 0)
			break;

		total += n;
	}

	printf("A soma total foi de %llu\n", total);
}
