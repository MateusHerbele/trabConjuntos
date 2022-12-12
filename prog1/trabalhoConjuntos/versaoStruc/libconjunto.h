#ifndef LIBCONJUNTO_H
#define LIBCONJUNTO_H

struct conjunto{
    int valorConjunto[200];
    int tamanho;
};

void preencheMenosUm(int *conjunto);

void imprimirConjunto(struct conjunto *conjunto);

int removerRepeticoes(struct conjunto *conjunto);

void ordenaConjunto(struct conjunto *conjunto);

void verificaVazio(int *conjunto);

int tamanhoConjunto(struct conjunto *conjunto);

void preencherConjunto(int *conjunto, int n);

int preencherAleatorios(int *conjunto);

void unirConjuntos(struct conjunto *conjunto1, struct conjunto *conjunto2, struct conjunto *conjuntoU);

void interseccaoConjutos(int *conjunto1, int *conjunto2, int *conjuntoI);

#endif // LIBCOJUNTO_H