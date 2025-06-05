#include <stdio.h>
#include <string.h>

#include "comum.h"

#define TAMANHO_BUF 8192 

void
questao4(void)
{
	char buf[TAMANHO_BUF];
	size_t i, espacos;

	puts("\nEste programa lê frases e imprime o número de espaços\nem branco nelas contidos. Para encerrá-lo, escreva\numa frase vazia ou o caractere EOF.\n\n");

	while (1) {
		espacos = 0;
		memset(buf, 0, TAMANHO_BUF);

		puts("Insira a frase:");

		if (!fgets(buf, TAMANHO_BUF, stdin)) {
			if (!feof(stdin))
				perror("fgets");
			break;
		}

		if (buf[0] == '\n')
			break;

		for (i = 0; buf[i]; i++)
			if (buf[i] == ' ' || buf[i] == '\t')
				espacos++;

		printf("%zu\n", espacos);
	}
}
