#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

void CriaArvore(TipoArvore *A) {
	*A = NULL;
}

void CriaRaiz(TipoArvore *A, TipoItem I) {

	*A = (TipoArvore) malloc(sizeof(TipoNo));

	(*A)->Item = I;
	(*A)->esq = NULL;
	(*A)->dir = NULL;
	
}

void Insere(TipoArvore *A, TipoItem I) {

    if ((*A) == NULL) { //arvore vazia
        CriaRaiz(A, I);
        return;
    }
    
    //considerando que nao pode haver chaves duplicadas
    if (I.Chave == (*A)->Item.Chave) {
        printf("ERRO: chave duplicada. Pulando operacao de inserir.\n\n");
        return;
    }
    
    if (I.Chave > (*A)->Item.Chave) { // direita
        Insere(&(*A)->dir, I);
    } else {
        Insere(&(*A)->esq, I);
    }
    
    return;

}

TipoItem Pesquisa(TipoArvore *A, TipoChave C) {

    TipoItem I;

    if ((*A) == NULL) { //nao achou
        I.Chave = -1;
        strcpy(I.Numeral, "|ERRO|");
        return I;
    }
    
    // ACHOU!
    if (C == (*A)->Item.Chave)
        return (*A)->Item;
        
    
    if (C > (*A)->Item.Chave) { // direita
        return Pesquisa(&(*A)->dir, C);
    } else { // esquerda
        return Pesquisa(&(*A)->esq, C);
    }

}

void static achaMenorETroca(TipoArvore *A, TipoArvore *Atual) {

    if ((*Atual)->esq == NULL) { // mais a direita possivel
        (*A)->Item = (*Atual)->Item;
        TipoApontador p = (*Atual); // guarda para apagar
        (*Atual) = (*Atual)->dir;
        free(p);
    } else {
        achaMenorETroca(A, &(*Atual)->esq);
    }

}

void static achaMaiorETroca(TipoArvore *A, TipoArvore *Atual) {

    if ((*Atual)->dir == NULL) { // mais a direita possivel
        (*A)->Item = (*Atual)->Item;
        TipoApontador p = (*Atual); // guarda para apagar
        (*Atual) = (*Atual)->esq;
        free(p);
    } else {
        achaMaiorETroca(A, &(*Atual)->dir);
    }

}

void Remove(TipoArvore *A, TipoChave C) {

    if ((*A) == NULL) { // nao achou
        printf("ERRO ao remover: nao encontrou a chave\n");
        return;
    }
    
    if (C > (*A)->Item.Chave) { // direita
        //printf("(%d, %d) dir ->\n", C, (*A)->Item.Chave);
        return Remove(&(*A)->dir, C);
    } else if (C < (*A)->Item.Chave) { // esquerda
        //printf("(%d, %d) <- esq\n", C, (*A)->Item.Chave);
        return Remove(&(*A)->esq, C);
    }
    
    // se chegou aqui, eh pq a chave eh igual
    TipoApontador p;
    
    // Dá para tirar um desses ifs. Respondam como fariam isso.
    if ((*A)->esq == NULL && (*A)->dir == NULL) { //folha
        p = *A;
        *A = NULL; //vai fazer o ponteiro dir ou esq chamado recursivamente apontar para nulo
        free(p);
    } else if ((*A)->esq == NULL) { //soh tem o da direita
        p = *A;
        *A = (*A)->dir;
        free(p);
    } else if ((*A)->dir == NULL) { //soh tem o da esquerda
        p = *A;
        *A = (*A)->esq;
        free(p);
    } else {
        achaMaiorETroca(A, &(*A)->esq); // OU
        //achaMenorETroca(A, &(*A)->dir);
    }

}

void visita(TipoArvore A) {
	printf("%d ", A->Item.Chave);
}

void emOrdem(TipoArvore A) {
	if (A == NULL) return;
	emOrdem(A->esq);
	visita(A);
	emOrdem(A->dir);
}
