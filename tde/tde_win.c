/* Código para Windows */
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_BUF 32
#define PI 3.141592653589793238462643383279502884

unsigned long long
le_num_llu(char *buf, size_t tamanho_buf)
{
	unsigned long long res;
	size_t i;
	char c, *fimptr;

	if (!fgets(buf, tamanho_buf, stdin)) {
		if (feof(stdin))
			putchar('\n');
		else
			perror("fgets");
		clearerr(stdin);
		errno = EINVAL;
		return 0;
	}

	for (i = 0; i < tamanho_buf && buf[i] != '\n'; i++)
		if (buf[i] == '-')
			buf[i] = ' ';

	if (i == tamanho_buf) {
		fprintf(stderr, "le_num_llu: Número muito longo, o limite é de %zu caracteres\n", tamanho_buf - 2);
		while ((c = getchar()) != EOF && c != '\n');
	}

	res = strtoull(buf, &fimptr, 0);

	if (errno == ERANGE || errno == EINVAL) {
		perror("strtoull");
		if (errno == ERANGE)
			fprintf(stderr, "le_num_llu: O número deve pertencer ao intervalo [0, %lld]\n", ULLONG_MAX);
		return 0;
	}

	if ((*fimptr != '\n' && *fimptr != '\0' && *fimptr != '\r') || buf == fimptr) {
		errno = EINVAL;
		perror("le_num_llu");
	}

	return res;
}

double
le_num_lf(char *buf, size_t tamanho_buf)
{
	double res;
	size_t i;
	char c, *fimptr;

	if (!fgets(buf, tamanho_buf, stdin)) {
		if (feof(stdin))
			putchar('\n');
		else
			perror("fgets");
		clearerr(stdin);
		errno = EINVAL;
		return 0;
	}

	for (i = 0; i < tamanho_buf && buf[i] != '\n'; i++);

	if (i == tamanho_buf) {
		fprintf(stderr, "le_num_lf: Número muito longo, o limite é de %zu caracteres\n", tamanho_buf - 2);
		while ((c = getchar()) != EOF && c != '\n');
	}

	res = strtod(buf, &fimptr);

	if (errno == ERANGE || errno == EINVAL) {
		perror("strtod");
		if (errno == ERANGE)
			fprintf(stderr, "le_num_lf: O número deve pertencer ao intervalo [%lf, %lf]\n", DBL_MIN, DBL_MAX);
		return 0;
	}

	if ((*fimptr != '\n' && *fimptr != '\0' && *fimptr != '\r') || buf == fimptr) {
		errno = EINVAL;
		perror("le_num_lf");
	}

	return res;
}

int
main(void)
{
	char buf[TAMANHO_BUF];
	double n, n2;
	int op;

	puts("\nCalculadora de áreas - TDE 1° Semestre - Linguagem de Programação\nParticipantes (THEriveis):\n-Davi Soares Daltro\n-Igor Mascarenhas Oliveira Magalhães\n-José Sinfrônio de Oliveira Neto\n-Nicolas Ribeiro Dias\n-Vitor Gabriel Silva Matos\n-Wagner Cardeal de Jesus\n\n");

	while (1) {
		memset(buf, '\0', TAMANHO_BUF);
		errno = 0;

		puts("Escolha a figura:\n1 - Circulo\n2 - Retângulo\n3 - Quadrado\n4 - Triângulo\n5 - Limpar a tela\n6 - Sair");

		op = (int)le_num_llu(buf, TAMANHO_BUF);

		if (errno != 0)
			continue;

		memset(buf, '\0', TAMANHO_BUF);
		errno = 0;

		switch (op) {
		case 1:
			printf("Insira o raio:");
			n = le_num_lf(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("%lf\n", n * n * PI);
			break;
		case 2:
			printf("Insira a base:");
			n = le_num_lf(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("Insira a altura:");
			n2 = le_num_lf(buf, TAMANHO_BUF);
			if (errno != 0 || n2 < 0)
				continue;
			printf("%lf\n", n * n2);
			break;
		case 3:
			printf("Insira o lado:");
			n = le_num_lf(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("%lf\n", n * n);
			break;
		case 4:
			printf("Insira a base:");
			n = le_num_lf(buf, TAMANHO_BUF);
			if (errno != 0 || n < 0)
				continue;
			printf("Insira a altura:");
			n2 = le_num_lf(buf, TAMANHO_BUF);
			if (errno != 0 || n2 < 0)
				continue;
			printf("%lf\n", n * n2 / 2);
			break;
		case 5:
			system("cls");
			break;
		case 6:
			return 0;
			break;
		}
	}
}

