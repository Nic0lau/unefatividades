#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "comum.h"

#define TAMANHO_BUF 8 

void
questao2(void)
{
	char buf[TAMANHO_BUF];
	long long res, n;
	size_t tentativas;

	puts("\nEste programa gera um número natural aleatório\nno intervalo [1, 100[ e pede que o usuário\no adivinhe. O programa dá dicas ao usuário caso\nerre e será encerrado caso acerte.\n\n");

	srand(time(NULL));
	res = rand() % 100;
	tentativas = 0;

	while (1) {
		memset(buf, 0, TAMANHO_BUF);
		errno = 0;

		printf("Digite um número:");
		
		n = le_num_lld(buf, TAMANHO_BUF);

		if (errno != 0)
			continue;

		tentativas++;

		if (n < res)
			puts("Quase! Mas a resposta é maior do que seu chute");
		else if (n > res)
			puts("Quase! Mas a resposta é menor do que seu chute");
		else
			break;
	}

	printf("Parabéns! Você acertou, a resposta realmente era %llu\nPara tal, você tentou %zu vezes!\n", res, tentativas);
}
