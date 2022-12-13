#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libconjunto.h"

void preencheMenosUm(struct conjunto *conjunto){
    int i;
    for(i = 0; i < 200; i++){
        conjunto->valorConjunto[i] = -1;
    }
}

void ordenaConjunto(struct conjunto *conjunto){
    int i, j, aux, posMenor;

    for(i = 0; i < conjunto->tamanho-1; i++){
        posMenor = i;
        for(j = i+1; j < conjunto->tamanho; j++){
            if(conjunto->valorConjunto[j] < conjunto->valorConjunto[posMenor]){
                posMenor = j;
            }
        }
        aux = conjunto->valorConjunto[posMenor];
        conjunto->valorConjunto[posMenor] = conjunto->valorConjunto[i];
        conjunto->valorConjunto[i] = aux;
    }
}

int tamanhoConjunto(struct conjunto *conjunto){
    int i;
    for(i = 0; i < 200; i++){
        if(conjunto->valorConjunto[i] == -1){
            if(i == 0){
                printf("Conjunto vazio\n");
                conjunto->tamanho = 0;
                return -1;
            }
            else{
                conjunto->tamanho = i;
                return i;
            }
        }
    }
    return 200;
}

int removerRepeticoes(struct conjunto *conjunto){
    int i, j, k;
    
    for(i = 0; i < conjunto->tamanho; i++){
        for(j = i+1; j <conjunto->tamanho;j = j){
            if(conjunto->valorConjunto[i] == conjunto->valorConjunto[j]){
                for(k = j; k < conjunto->tamanho; k++){
                        conjunto[k] = conjunto[k+1];
                    }
                conjunto->tamanho += -1;/*Reduz o tamanho do vetor para evitar pegar o -1 na próxima repetição*/
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
    conjunto->valorConjunto[conjunto->tamanho] == -1;
    return conjunto->tamanho;
    }
   


void imprimirConjunto(struct conjunto *conjunto){
    int i, tamanho;
    /*Reordena na impressão
    para evitar que sejam colocados em 2 inserções
     de elementos valores que não fiquem ordenados 
    na impressão*/
    tamanho = tamanhoConjunto(conjunto);
    ordenaConjunto(conjunto);

    for(i = 0; i < 200; i++){
        if(tamanho == -1){
            printf("Conjunto vazio \n");
            return;    
            
        }
        else{
            if(conjunto->valorConjunto[i] == -1){
                return;
            }
            else{
                printf("Elemento %d: %d", i+1, conjunto->valorConjunto[i]);
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

void preencherConjunto(struct conjunto *conjunto, int n){
    int i = 0, temp;

    while(i < n){
        printf("Insira um número ao conjunto:");
        scanf("%d", &temp);
        if(temp < 0){
            printf("Valor inválido!Digite novamente!");
        }
        else{
            conjunto->valorConjunto[i] = temp;
            i++;
        }
    }
}

void preencherAleatorios(struct conjunto *conjunto){
    int i;
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        conjunto->valorConjunto[i] = rand() % 1000;//Deixei em 1000 pois a faixa de valores resultantes apresenta menos repetições
    }
    ordenaConjunto(conjunto);
    printf("Conjunto de aleatórios gerado:\n");
    imprimirConjunto(conjunto);
}

void unirConjuntos(struct conjunto *conjunto1, struct conjunto *conjunto2, struct conjunto *conjuntoU){
    int i;

    conjuntoU->tamanho = conjunto1->tamanho + conjunto2->tamanho;    

    for(i = 0; i < conjuntoU->tamanho; i++){
        if(i < conjunto1->tamanho){
            conjuntoU->valorConjunto[i] = conjunto1->valorConjunto[i];
        }
        if(i < conjunto2->tamanho){
            conjuntoU->valorConjunto[i+conjunto1->tamanho] = conjunto2->valorConjunto[i];
        }
    }
    conjuntoU->tamanho = removerRepeticoes(conjuntoU);
    printf("A união dos dois conjuntos resultou no conjunto Uniao com %d elemento(s) e é constituído por: \n", conjuntoU->tamanho);
    imprimirConjunto(conjuntoU);

}

void interseccaoConjutos(struct conjunto *conjunto1, struct conjunto  *conjunto2, struct conjunto *conjuntoI){
    int i, j, m, tamanho1, tamanho2, tamanhoMaior, tamanhoMenor;
    struct conjunto* conjuntoMaior, *conjuntoMenor;
    m = 0;

    tamanhoConjunto(conjunto1);
    tamanhoConjunto(conjunto2);

    if(conjunto1->tamanho > conjunto2->tamanho || conjunto1->tamanho == conjunto2->tamanho){
        tamanhoMaior = conjunto1->tamanho;
        tamanhoMenor = conjunto2->tamanho;
        conjuntoMaior = conjunto1;
        conjuntoMenor = conjunto2;
    }
    else{
        tamanhoMaior = conjunto2->tamanho;
        tamanhoMenor = conjunto1->tamanho;
        conjuntoMaior = conjunto2;
        conjuntoMenor = conjunto1;
    }
  

    for(i = 0; i < tamanhoMaior; i++){
        for(j = 0; j < tamanhoMenor; j++){
            if(conjuntoMaior->valorConjunto[i] == conjuntoMenor->valorConjunto[j]){
                conjuntoI->valorConjunto[m] = conjuntoMaior->valorConjunto[i];
                m++;
            }
        }
    }
    tamanhoMaior = tamanhoConjunto(conjuntoI); //Reutilizando as variáveis já declaradas
    tamanhoMenor = removerRepeticoes(conjuntoI);//Reutilizando as variáveis já declaradas
    printf("O conjunto resultado da intersecção entre os dois conjuntos tem %d elemento(s) e é contistuído por: \n", tamanhoMenor);
    imprimirConjunto(conjuntoI);
}