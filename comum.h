#ifndef COMUM_CABECALHO
#define COMUM_CABECALHO

/* Para limpar a tela com portabilidade */
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\033[2J\033[H");
#endif

long long le_num_lld(char *buf, size_t tamanho_buf);
unsigned long long le_num_llu(char *buf, size_t tamanho_buf);
long double le_num_ld(char *buf, size_t tamanho_buf);

#endif
