/* Lembre-se de compilar usando -mlong-double-64 no MinGW64 */
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\033[2J\033[H");
#endif
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

long double
le_num_ld(char *buf, size_t tamanho_buf)
{
	long double res;
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
		fprintf(stderr, "le_num_ld: Número muito longo, o limite é de %zu caracteres\n", tamanho_buf - 2);
		while ((c = getchar()) != EOF && c != '\n');
	}

	res = strtold(buf, &fimptr);

	if (errno == ERANGE || errno == EINVAL) {
		perror("strtold");
		if (errno == ERANGE)
			fprintf(stderr, "le_num_ld: O número deve pertencer ao intervalo [%Lf, %Lf]\n", LDBL_MIN, LDBL_MAX);
		return 0;
	}

	if ((*fimptr != '\n' && *fimptr != '\0' && *fimptr != '\r') || buf == fimptr) {
		errno = EINVAL;
		perror("le_num_ld");
	}

	return res;
}

int
main(void)
{
	char buf[TAMANHO_BUF];
	long double n, n2;
	int op;

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
			return 0;
			break;
		}
	}
}

