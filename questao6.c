#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define TAMANHO_BUF 32

void
questao6(void)
{
	char buf[TAMANHO_BUF];
	long double n1, n2;

	puts("\nEste programa lê dois números e informa o maior.\n\n");

	while (1) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Insira o 1° número:");

		n1 = le_num_ld(buf, TAMANHO_BUF);

		if (errno != 0)
			continue;

		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Insira o 2° número:");

		n2 = le_num_ld(buf, TAMANHO_BUF);

		if (errno == 0)
			break;
	}

	if (n1 > n2)
		printf("O primeiro número, %Lf, é o maior\n", n1);
	else if (n2 > n1)
		printf("O segundo número, %Lf, é o maior\n", n2);
	else
		puts("Os dois números são iguais.");
}
