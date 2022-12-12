#include <stdio.h>
#include "libconjunto.h"

int main(){
    //variáveis globais
    struct conjunto conjuntoA, conjuntoB, conjuntoAleatorio, conjuntoUniao, conjuntoInterseccao;
    struct conjunto* P_conjuntoA = &conjuntoA;
    struct conjunto* P_conjuntoB = &conjuntoB;
    struct conjunto* P_conjuntoAleatorio = &conjuntoAleatorio;
    struct conjunto* P_conjuntoUniao = &conjuntoUniao;
    struct conjunto* P_conjuntoInterseccao = &conjuntoInterseccao;

    preencheMenosUm(P_conjuntoA->valorConjunto);
    preencheMenosUm(P_conjuntoB->valorConjunto);
    preencheMenosUm(P_conjuntoAleatorio->valorConjunto);
    preencheMenosUm(P_conjuntoUniao->valorConjunto);
    preencheMenosUm(P_conjuntoInterseccao->valorConjunto);

    conjuntoAleatorio.tamanho = 100;

    int escolha = 1, escolhaConjunto, nElem, tamanho, trava = 0;
    int *escolhaUI1[200], *escolhaUI2[200];

    printf("Bem-vindo ao programa dos conjuntos!\nVocê tem acesso a dois conjuntos para preencher manualmente, o cojunto A e o conjunto B\n");
    while(escolha != 8){
        printf("Opções disponíveis com os conjuntos:\n1-Preencher um dos conjuntos(A ou B)\n2-Verificar se um conjunto é vazio\n3-Saber o tamanho de um conjunto\n4-Imprimir um conjunto\n5-Criar um novo conjunto com apenas números gerados aleatoriamente\n6-Criar um novo conjunto que seja a união de dois a sua escolha\n7-Criar um conjunto que seja a intersecção de 2 conjuntos a sua escolha\n8-Encerrar o programa\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1:
                printf("1-Preencher Conjunto A\n2-Preencher Conjunto B\n");
                scanf("%d", &escolhaConjunto);
                switch (escolhaConjunto){
                    case 1:
                        printf("Escolha o número de elementos a serem preenchidos 1-100\n");
                        scanf("%d", &nElem);
                        if(nElem > 100 || nElem < 0){
                            printf("Valor inválido! Retornando ao menu de opções\n");
                        }
                        else{
                            preencherConjunto(P_conjuntoA->valorConjunto, nElem);
                        }
                    break;
                
                    case 2:
                        printf("Escolha o número de elementos a serem preenchidos 1-100\n");
                        scanf("%d", &nElem);
                        if(nElem > 100 || nElem < 0){
                            printf("Valor inválido! Retornando ao menu de opções\n");
                        }
                        else{
                            preencherConjunto(P_conjuntoB->valorConjunto, nElem);
                        }
                    break;

                    default:
                        printf("Valor inválido!Retornando ao menu de ações\n");     
                }
            break;

            case 2:
                printf("1-Verificar Conjunto A\n2-Verificar Conjunto B\n3-Verificar Conjunto Aleatório\n4-Verificar Conjunto União\n5-Verficar Conjunto Intersecção\n");
                scanf("%d", &escolhaConjunto);
                switch (escolhaConjunto){
                    case 1:
                        verificaVazio(P_conjuntoA->valorConjunto);
                    break;
                
                    case 2:
                        verificaVazio(P_conjuntoB->valorConjunto);
                    break;

                    case 3:
                        verificaVazio(P_conjuntoAleatorio->valorConjunto);
                    break;

                    case 4:
                        verificaVazio(P_conjuntoUniao->valorConjunto);
                    break;

                    case 5:
                        verificaVazio(P_conjuntoInterseccao->valorConjunto); 

                    default:
                        printf("Valor inválido!Retornando ao menu de ações\n");
            }
            break;

            case 3:
                printf("1-Verificar tamanho Conjunto A\n2-Verificar tamanho Conjunto B\n3-Verificar tamanho conjunto Aleatório\n4-Verificar tamanho conjunto União\n5-Verificar tamanho conjunto intersecção\n");
                scanf("%d", &escolhaConjunto);
                switch (escolhaConjunto){
                    case 1:
                        tamanho = tamanhoConjunto(P_conjuntoA);
                        if(tamanho != -1){
                            printf("Tamanho do conjunto em questão: %d\n", tamanho);
                        }
                    break;
                
                    case 2:
                        tamanho = tamanhoConjunto(P_conjuntoB);
                        if(tamanho != -1){
                            printf("Tamanho do conjunto em questão: %d\n", tamanho);
                        }
                    break;

                    case 3:
                        tamanho = tamanhoConjunto(P_conjuntoAleatorio);
                        if(tamanho != -1){
                            printf("Tamanho do conjunto em questão: %d\n", tamanho);
                        }
                    break;

                    case 4:
                        tamanho = tamanhoConjunto(P_conjuntoUniao);
                        if(tamanho != -1){
                            printf("Tamanho do conjunto em questão: %d\n", tamanho);
                        }
                    break;

                    case 5:
                        tamanho = tamanhoConjunto(P_conjuntoInterseccao);
                        if(tamanho != -1){
                            printf("Tamanho do conjunto em questão: %d\n", tamanho);
                        } 
                    break;

                    default:
                        printf("Valor inválido!Retornando ao menu de ações\n");
            }
            break;
            
            case 4:
                printf("1-Imprimir Conjunto A\n2-Imprimir Conjunto B\n3-Imprimir conjunto Aleatório\n4-Imprimir conjunto União\n5-Imprimir conjunto intersecção\n");
                scanf("%d", &escolhaConjunto);
                switch (escolhaConjunto){
                    case 1:
                        imprimirConjunto(P_conjuntoA->valorConjunto);
                    break;
                
                    case 2:
                        imprimirConjunto(P_conjuntoB->valorConjunto);
                    break;

                    case 3:
                        imprimirConjunto(P_conjuntoAleatorio->valorConjunto);
                    break;

                    case 4:
                        imprimirConjunto(P_conjuntoUniao->valorConjunto);
                    break;

                    case 5:
                        imprimirConjunto(P_conjuntoInterseccao->valorConjunto); 
                    break;

                    default:
                        printf("Valor inválido!Retornando ao menu de ações\n");
                }
            break;

            case 5:
                preencherAleatorios(P_conjuntoAleatorio->valorConjunto);
            break;
                
            case 6:
                printf("1-Conjunto A\n2-Conjunto B\n3-Conjunto Aleatório\n4-Conjunto União\n5-Conjunto intersecção\n");
                printf("Escolha o primeiro conjunto para a união:");
                scanf("%d", &escolhaConjunto);
                 if(escolhaConjunto < 0 || escolhaConjunto > 5){
                    printf("Valor inválido!Retornando ao menu de ações\n");
                    trava = 1;
                }
                else{
                    switch (escolhaConjunto){
                        case 1:
                            *escolhaUI1 = P_conjuntoA->valorConjunto;
                        break;
                        
                        case 2:
                            *escolhaUI1 = P_conjuntoB->valorConjunto;
                        break;
                        
                        case 3:
                            *escolhaUI1 = P_conjuntoAleatorio->valorConjunto;
                        break;

                        case 4:
                            *escolhaUI1 = P_conjuntoUniao->valorConjunto;
                        break;
                        case 5:
                            *escolhaUI2 = P_conjuntoInterseccao->valorConjunto;
                        break;
                    }
                    }
                    if(trava != 1){
                        printf("1-Conjunto A\n2-Conjunto B\n3-Conjunto Aleatório\n4-Conjunto União\n5-Conjunto intersecção\n");
                        printf("Escolha o segundo conjunto para a união:");
                        scanf("%d", &escolhaConjunto);
                            switch (escolhaConjunto){
                            case 1:
                                *escolhaUI2 = P_conjuntoA->valorConjunto;
                            break;
                            
                            case 2:
                                *escolhaUI2 = P_conjuntoB->valorConjunto;
                            break;
                            
                            case 3:
                                *escolhaUI2 = P_conjuntoAleatorio->valorConjunto;
                            break;

                            case 4:
                                *escolhaUI2 = P_conjuntoUniao->valorConjunto;
                            break;
                            
                            case 5:
                                *escolhaUI2 = P_conjuntoInterseccao->valorConjunto;
                            break;
                            
                            default:
                                printf("Escolha Inválida! Voltando ao menu de ações\n");
                                trava = 1;
                        

                        }
                            if(trava != 1){
                                unirConjuntos(*escolhaUI1, *escolhaUI2, P_conjuntoUniao->valorConjunto);
                            }
                    }
                trava = 0;

                
            break;
            
            case 7:
                printf("1-Conjunto A\n2-Conjunto B\n3-Conjunto Aleatório\n4-Conjunto União\n5-Conjunto intersecção\n");
                printf("Escolha o primeiro conjunto para a intersecção:");
                scanf("%d", &escolhaConjunto);
                if(escolhaConjunto < 0 || escolhaConjunto > 5){
                    printf("Valor inválido!Retornando ao menu de ações\n");
                    trava = 1;
                }
                else{
                    switch (escolhaConjunto){
                        case 1:
                            *escolhaUI1 = P_conjuntoA->valorConjunto;
                        break;
                        
                        case 2:
                            *escolhaUI1 = P_conjuntoB->valorConjunto;
                        break;
                        
                        case 3:
                            *escolhaUI1 = P_conjuntoAleatorio->valorConjunto;
                        break;

                        case 4:
                            *escolhaUI1 = P_conjuntoUniao->valorConjunto;
                        break;
                        
                        case 5:
                            *escolhaUI1 = P_conjuntoInterseccao->valorConjunto;
                        break;

                    }
                }
                if(trava != 1){
                    printf("1-Conjunto A\n2-Conjunto B\n3-Conjunto Aleatório\n4-Conjunto União\n5-Conjunto intersecção\n");
                    printf("Escolha o segundo conjunto para a intersecção:");
                    scanf("%d", &escolhaConjunto);
                        switch (escolhaConjunto){
                        case 1:
                            *escolhaUI2 = P_conjuntoA->valorConjunto;
                        break;
                        
                        case 2:
                            *escolhaUI2 = P_conjuntoB->valorConjunto;
                        break;
                        
                        case 3:
                            *escolhaUI2 = P_conjuntoAleatorio->valorConjunto;
                        break;

                        case 4:
                            *escolhaUI2 = P_conjuntoUniao->valorConjunto;
                        break;

                        case 5:
                            *escolhaUI2 = P_conjuntoInterseccao->valorConjunto;
                        break;
                        
                        default:
                            printf("Escolha Inválida! Voltando ao menu de ações\n");
                            trava = 1;
                        break;

                    }
                        if(trava != 1){
                            interseccaoConjutos(*escolhaUI1, *escolhaUI2, P_conjuntoInterseccao->valorConjunto);
                        } 
                    }
                trava = 0;
                
            break;

            case 8:
                printf("Encerrando o programa.\nObrigado pela preferência!\n");
            break;

            default:
                printf("Opção inválida!\n");
        
        }
    }

    return 0;
}