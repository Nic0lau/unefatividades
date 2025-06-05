#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "comum.h"

#define TAMANHO_BUF 32
#define NUMERO_DE_QUESTOES 10

extern void questao1(void);
extern void questao2(void);
extern void questao3(void);
extern void questao4(void);
extern void questao5(void);
extern void questao6(void);
extern void questao7(void);
extern void questao8(void);
extern void questao9(void);
extern void questao10(void);

int
main(int argc, char **argv)
{
	void (*questoes[])(void) = {
		questao1,
		questao2,
		questao3,
		questao4,
		questao5,
		questao6,
		questao7,
		questao8,
		questao9,
		questao10
	};
	char buf[TAMANHO_BUF];
	int op;

	setlocale(LC_ALL, "");

	while (1) {
		memset(buf, '\0', TAMANHO_BUF);
		errno = 0;

		puts("Escolha:\n1...10 - Questões (A 7ª é o TDE):\n11 - Limpar a tela\n12 - Sair\n");

		op = (int)le_num_llu(buf, TAMANHO_BUF);

		if (errno != 0)
			continue;

		switch (op) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			questoes[op - 1]();
			break;
		case 11:
			clrscr();
			break;
		case 12:
			return 0;
			break;
		}
	}

	return 0;
}
