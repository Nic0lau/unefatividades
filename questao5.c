#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define MAIORIDADE 18
#define TAMANHO_BUF 32

void
questao5(void)
{
	char buf[TAMANHO_BUF];
	unsigned long long idd;

	printf("\nEste programa lê a idade do usuário e informa\nse ele é maior de idade ou não. A maioridade\né completada ao atingir %d anos.\n\n\n", MAIORIDADE);

	while (1) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Insira sua idade:");

		idd = le_num_llu(buf, TAMANHO_BUF);

		if (errno == 0)
			break;
	}

	if (idd >= MAIORIDADE)
		puts("Parabéns, você é maior de idade\ne já pode ser preso!");
	else
		puts("Saí daqui, moleque!");
}
