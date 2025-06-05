#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define TAMANHO_BUF 32

void
questao3(void)
{
	char buf[TAMANHO_BUF];
	unsigned long long n, i;

	puts("\nEste programa imprime os n primeiros números\npares, sendo n um número natural qualquer\ndigitado pelo usuário.\n\n");

	while (1) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Digite um número:");

		n = le_num_llu(buf, TAMANHO_BUF);

		if (errno == 0)
			break;
	}

	for (i = 1; i <= n; i++)
		printf("%llu\n", i * 2);
}
