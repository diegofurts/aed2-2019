#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

int main() {

    TipoArvore A;
    CriaArvore(&A);
    
    TipoItem I;
    
    I.Chave = 45;
    strcpy(I.Numeral, "quarenta e cinco");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 32;
    strcpy(I.Numeral, "trinta e dois");
    Insere(&A,I);
    
    I.Chave = 55;
    strcpy(I.Numeral, "cinquenta e cinco");
    Insere(&A,I);
    
    printf("Chave da raiz->dir = %d\n", A->dir->Item.Chave);
    printf("Chave da raiz->esq = %d\n", A->esq->Item.Chave);
    
    I.Chave = 23;
    strcpy(I.Numeral, "vinte e tres");
    Insere(&A,I);
    
    I.Chave = 41;
    strcpy(I.Numeral, "quarenta e um");
    Insere(&A,I);
    
    I.Chave = 62;
    strcpy(I.Numeral, "sessenta e dois");
    Insere(&A,I);
    
    I.Chave = 51;
    strcpy(I.Numeral, "cinquenta e um");
    Insere(&A,I);
    
    I.Chave = 77;
    strcpy(I.Numeral, "setenta e sete");
    Insere(&A,I);
    
    I.Chave = 29;
    strcpy(I.Numeral, "vinte e nove");
    Insere(&A,I);
    
    I.Chave = 12;
    strcpy(I.Numeral, "doze, ladrao!");
    Insere(&A,I);
    
    I.Chave = 27;
    strcpy(I.Numeral, "vinte e sete");
    Insere(&A,I);
    
    I.Chave = 26;
    strcpy(I.Numeral, "vinte e seis");
    Insere(&A,I);
    
    emOrdem(A); printf("\n");
    

    I = Pesquisa(&A, 45);
    printf("Resultado da busca por 45: %s\n", I.Numeral);

    I = Pesquisa(&A, 23);
    printf("Resultado da busca por 23: %s\n", I.Numeral);
    
    I = Pesquisa(&A, 77);
    printf("Resultado da busca por 77: %s\n", I.Numeral);
    
    I = Pesquisa(&A, 62);
    printf("Resultado da busca por 62: %s\n", I.Numeral);
    
    I = Pesquisa(&A, 12);
    printf("Resultado da busca por 12: %s\n", I.Numeral);
    
    I = Pesquisa(&A, 15);
    printf("Resultado da busca por 15: %s\n", I.Numeral);
    
    
    Remove(&A, 15);
    
    emOrdem(A); printf("\n");
    
    Remove(&A, 32);
    emOrdem(A); printf("\n");
    /*Remove(&A, 55);
    emOrdem(A); printf("\n");
    Remove(&A, 41);
    emOrdem(A); printf("\n");
    Remove(&A, 23);
    emOrdem(A); printf("\n");
    Remove(&A, 45);
    emOrdem(A); printf("\n");
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    printf("Chave da raiz->dir = %d\n", A->dir->Item.Chave);
    printf("Chave da raiz->esq = %d\n", A->esq->Item.Chave);*/

    return 0;

}
