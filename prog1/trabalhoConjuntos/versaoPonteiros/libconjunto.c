#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libconjunto.h"

void preencheMenosUm(int *conjunto){
    int i;
    for(i = 0; i < 100; i++){
        conjunto[i] = -1;
    }
}

void ordenaConjunto(int *conjunto, int n){
    int i, j, aux, posMenor;

    for(i = 0; i < n-1; i++){
        posMenor = i;
        for(j = i+1; j < n; j++){
            if(conjunto[j] < conjunto[posMenor]){
                posMenor = j;
            }
        }
        aux = conjunto[posMenor];
        conjunto[posMenor] = conjunto[i];
        conjunto[i] = aux;
    }
}

int tamanhoConjunto(int *conjunto){
    int i;
    for(i = 0; i < 200; i++){
        if(conjunto[i] == -1){
            if(i == 0){
                printf("Conjunto vazio\n");
                return -1;
            }
            else{
                return i;
            }
        }
    }
    return 200;
}

int removerRepeticoes(int *conjunto, int tamanho){
    int i, j, k;
    
    for(i = 0; i < tamanho; i++){
        for(j = i+1; j <tamanho;j = j){
            if(conjunto[i] == conjunto[j]){
                for(k = j; k < tamanho; k++){
                        conjunto[k] = conjunto[k+1];
                    }
                tamanho--;/*Reduz o tamanho do vetor para evitar pegar o -1 na próxima repetição*/
                }
                else{
                    j++;/*Pula pro próximo número apenas aqui,
                    pois se pular no laço do j pode ocorrer de não eliminar a repetição em seguida do mesmo número
                    exemplo: 1 2 3 4 4 4 5 
                    primeiro ciclo: 1 2 3 4 4 5
                    segundo ciclo: 1 2 3 4 4 5, como foi pro quatro ao lado ele descondera o quatro anterior,
                    então mantém a repetição */
                }
            }     
        }
    conjunto[tamanho] == -1;
    return tamanho;
    }
   


void imprimirConjunto(int *conjunto){
    int i, tamanho;
    /*Ordena na impressão ao invés da inserção 
    para evitar que sejam colocados em 2 inserções
     de elementos valores que não fiquem ordenados 
    na impressão*/
    tamanho = tamanhoConjunto(conjunto);
    ordenaConjunto(conjunto, tamanho);

    for(i = 0; i < 200; i++){
        if(conjunto[i] == -1 && i == 0){
            printf("Conjunto vazio \n");
            return;    
            
        }
        else{
            if(conjunto[i] == -1){
                return;
            }
            else{
                printf("Elemento %d: %d", i+1, conjunto[i]);
                printf("\n");
            }
        }
    }

}

void verificaVazio(int *conjunto){
    if(conjunto[0] == -1){
        printf("Conjunto Vazio\n");
        return ;
    }
    printf("Conjunto não vazio\n");
}

void preencherConjunto(int *conjunto, int n){
    int i = 0, temp;

    while(i < n){
        printf("Insira um número ao conjunto:");
        scanf("%d", &temp);
        if(temp < 0){
            printf("Valor inválido!Digite novamente!");
        }
        else{
            conjunto[i] = temp;
            i++;
        }
    }
}

int preencherAleatorios(int *conjunto){
    int i;
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        conjunto[i] = rand() % 1000;//Deixei em 1000 pois a faixa de valores resultantes apresenta menos repetições
    }
    ordenaConjunto(conjunto, 100);
    printf("Conjunto de aleatórios gerado:\n");
    imprimirConjunto(conjunto);
}

void unirConjuntos(int *conjunto1, int *conjunto2, int *conjuntoU){
    int i, tamanho1, tamanho2, tamanhoSoma;

    tamanho1 = tamanhoConjunto(conjunto1);
    tamanho2 = tamanhoConjunto(conjunto2);
    tamanhoSoma = tamanho1 + tamanho2;

    for(i = 0; i < tamanhoSoma; i++){
        if(i < tamanho1){
            conjuntoU[i] = conjunto1[i];
        }
        if(i < tamanho2){
            conjuntoU[i+tamanho1] = conjunto2[i];
        }
    }
    tamanhoSoma = removerRepeticoes(conjuntoU, tamanhoSoma);
    printf("A união dos dois conjuntos resultou no conjunto Uniao com %d elemento(s) e é constituído por: \n", tamanhoSoma);
    imprimirConjunto(conjuntoU);

}

void interseccaoConjutos(int *conjunto1, int *conjunto2, int *conjuntoI){
    int i, j, m, tamanho1, tamanho2, tamanhoMaior, tamanhoMenor;
    int *conjuntoMaior, *conjuntoMenor;
    m = 0;

    tamanho1 = tamanhoConjunto(conjunto1);
    tamanho2 = tamanhoConjunto(conjunto2);
    if(tamanho1 > tamanho2 || tamanho1 == tamanho2){
        tamanhoMaior = tamanho1;
        tamanhoMenor = tamanho2;
        conjuntoMaior = conjunto1;
        conjuntoMenor = conjunto2;
    }
    else{
        tamanhoMaior = tamanho2;
        tamanhoMenor = tamanho1;
        conjuntoMaior = conjunto2;
        conjuntoMenor = conjunto1;
    }
  

    for(i = 0; i < tamanhoMaior; i++){
        for(j = 0; j < tamanhoMenor; j++){
            if(conjuntoMaior[i] == conjuntoMenor[j]){
                conjuntoI[m] = conjuntoMaior[i];
                m++;
            }
        }
    }
    tamanhoMaior = tamanhoConjunto(conjuntoI); //Reutilizando as variáveis já declaradas
    tamanhoMenor = removerRepeticoes(conjuntoI, tamanhoMaior);//Reutilizando as variáveis já declaradas
    printf("O conjunto resultado da intersecção entre os dois conjuntos tem %d elemento(s) e é contistuído por: \n", tamanhoMenor);
    imprimirConjunto(conjuntoI);
}