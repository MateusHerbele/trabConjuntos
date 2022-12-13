#ifndef LIBCONJUNTO_H
#define LIBCONJUNTO_H

struct conjunto{
    int *valorConjunto;
    int tamanho;
};

void preencheMenosUm(struct conjunto *conjunto);

void imprimirConjunto(struct conjunto *conjunto);

int removerRepeticoes(struct conjunto *conjunto);

void ordenaConjunto(struct conjunto *conjunto);

void verificaVazio(int *conjunto);

int tamanhoConjunto(struct conjunto *conjunto);

void preencherConjunto(struct conjunto *conjunto, int n);

void preencherAleatorios(struct conjunto  *conjunto, int n);

void unirConjuntos(struct conjunto *conjunto1, struct conjunto *conjunto2, struct conjunto *conjuntoU);

void interseccaoConjutos(struct conjunto *conjunto1, struct conjunto  *conjunto2, struct conjunto *conjuntoI);

#endif // LIBCOJUNTO_H