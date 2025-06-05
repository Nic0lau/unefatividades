#include <stdio.h>

void
questao8(void)
{
	char c;

	puts("\nEste programa lê uma letra e imprime uma\nresposta seguindo a tabela abaixo:\n'S' => Segunda\n'T' => Terça\n'Q' => Quarta\n'C' => Quinta\n'X' => Sexta\n'B' => Sábado\n'D' => Domingo\n\n");

	c = getchar();

	switch (c) {
	case 'S':
	case 's':
		puts("Segunda-feira");
		break;
	case 'T':
	case 't':
		puts("Terça-feira");
		break;
	case 'Q':
	case 'q':
		puts("Quarta-feira");
		break;
	case 'C':
	case 'c':
		puts("Quinta-feira");
		break;
	case 'X':
	case 'x':
		puts("Sexta-feira");
		break;
	case 'B':
	case 'b':
		puts("Sábado");
		break;
	case 'D':
	case 'd':
		puts("Domingo");
		break;
	default:
		puts("Opção inválida");
		break;
	}

	while (c != '\n' && c != EOF)
		c = getchar();
}
