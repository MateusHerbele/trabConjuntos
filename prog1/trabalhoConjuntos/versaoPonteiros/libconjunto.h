#ifndef LIBCONJUNTO_H
#define LIBCONJUNTO_H

void preencheMenosUm(int *conjunto);

void imprimirConjunto(int *conjunto);

int removerRepeticoes(int *conjunto, int tamanho);

void ordenaConjunto(int *conjunto, int n);

void verificaVazio(int *conjunto);

int tamanhoConjunto(int *conjunto);

void preencherConjunto(int *conjunto, int n);

int preencherAleatorios(int *conjunto);

void unirConjuntos(int *conjunto1, int *conjunto2, int *conjuntoU);

void interseccaoConjutos(int *conjunto1, int *conjunto2, int *conjuntoI);

#endif // LIBCOJUNTO_H