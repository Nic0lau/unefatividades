#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long
le_num_lld(char *buf, size_t tamanho_buf)
{
	long long res;
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
		fprintf(stderr, "le_num_lld: Número muito longo, o limite é de %zu caracteres\n", tamanho_buf - 2);
		while ((c = getchar()) != EOF && c != '\n');
	}

	res = strtoll(buf, &fimptr, 0);

	if (errno == ERANGE || errno == EINVAL) {
		perror("strtoll");
		if (errno == ERANGE)
			fprintf(stderr, "le_num_lld: O número deve pertencer ao intervalo [%lld, %lld]\n", LLONG_MIN, LLONG_MAX);
		return 0;
	}

	if ((*fimptr != '\n' && *fimptr != '\0' && *fimptr != '\r') || buf == fimptr) {
		errno = EINVAL;
		perror("le_num_lld");
	}

	return res;
}

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
