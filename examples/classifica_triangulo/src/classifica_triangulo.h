#ifndef TRI_RUIM_H
#define TRI_RUIM_H
/* Retorna string alocada via malloc com a classificação do triângulo.
   O chamador DEVE dar free() no ponteiro retornado. */
char* classifica_triangulo(int a, int b, int c);
#endif