#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "splaytree.h"

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
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 23;
    strcpy(I.Numeral, "vinte e tres");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 55;
    strcpy(I.Numeral, "cinquenta e cinco");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 62;
    strcpy(I.Numeral, "sessenta e dois");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 51;
    strcpy(I.Numeral, "cinquenta e um");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 41;
    strcpy(I.Numeral, "quarenta e um");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 77;
    strcpy(I.Numeral, "setenta e sete");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 29;
    strcpy(I.Numeral, "vinte e nove");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 12;
    strcpy(I.Numeral, "doze, ladrao!");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 27;
    strcpy(I.Numeral, "vinte e sete");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    
    I.Chave = 26;
    strcpy(I.Numeral, "vinte e seis");
    Insere(&A,I);
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);

    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    emOrdem(A); printf("\n\n");


    Remove(&A, 41);
    emOrdem(A); printf("\n\n");
    Remove(&A, 51);
    emOrdem(A); printf("\n\n");
    Remove(&A, 62);
    emOrdem(A); printf("\n\n");
    Remove(&A, 77);
    emOrdem(A); printf("\n\n");
    Remove(&A, 55);
    emOrdem(A); printf("\n\n");
    
    printf("Chave da raiz = %d\n", (*A).Item.Chave);
    emOrdem(A); printf("\n\n");
    

    return 0;

}
