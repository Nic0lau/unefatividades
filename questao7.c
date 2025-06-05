#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define TAMANHO_BUF 32
#define PI 3.141592653589793238462643383279502884

void
questao7(void)
{
	char buf[TAMANHO_BUF];
	long double n, n2;
	int op;

	while (1) {
		memset(buf, '\0', TAMANHO_BUF);
		errno = 0;

		puts("Escolha a figura:\n1 - Circulo:\n2 - Retângulo\n3 - Quadrado\n4 - Triângulo\n5 - Limpar a tela\n6 - Sair");

		op = (int)le_num_llu(buf, TAMANHO_BUF);

		if (errno != 0)
			continue;

		memset(buf, '\0', TAMANHO_BUF);
		errno = 0;

		switch (op) {
		case 1:
			printf("Insira o raio:");
			n = le_num_ld(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("%Lf\n", n * n * PI);
			break;
		case 2:
			printf("Insira a base:");
			n = le_num_ld(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("Insira a altura:");
			n2 = le_num_ld(buf, TAMANHO_BUF);
			if (errno != 0 || n2 < 0)
				continue;
			printf("%Lf\n", n * n2);
			break;
		case 3:
			printf("Insira o lado:");
			n = le_num_ld(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("%Lf\n", n * n);
			break;
		case 4:
			printf("Insira a base:");
			n = le_num_ld(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("Insira a altura:");
			n2 = le_num_ld(buf, TAMANHO_BUF);
			if (errno != 0 || n2 < 0)
				continue;
			printf("%Lf\n", n * n2 / 2);
			break;
		case 5:
			clrscr();
			break;
		case 6:
			return;
			break;
		}
	}
}

