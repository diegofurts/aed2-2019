#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"

void CriaArvore(TipoArvore *A) {
	*A = NULL;
}

void CriaRaiz(TipoArvore *A, TipoItem I) {

	*A = (TipoArvore) malloc(sizeof(TipoNo));

	(*A)->Item = I;
	(*A)->esq = NULL;
	(*A)->dir = NULL;
	(*A)->alt = 0;
	
}

int retornaAltura(TipoArvore *A) {
    if ((*A) == NULL)
        return -1;
    else
        return (*A)->alt;
}

int checaFB(TipoArvore *A) {
    if ((*A) == NULL)
        return 0;
    else // verificar isso que dai
        return retornaAltura(&(*A)->esq) - retornaAltura(&(*A)->dir);
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
        (*A)->alt = max((*A)->alt, retornaAltura(&(*A)->dir) + 1);
    } else {
        Insere(&(*A)->esq, I);
        (*A)->alt = max((*A)->alt, retornaAltura(&(*A)->esq) + 1);
    }
           
    int bal = checaFB(A);
    printf(" -- bal: %d\n", bal);
    
    if (bal > 1) {
    
        TipoArvore filhoesq = (*A)->esq;
        int balfilho = checaFB(&filhoesq);
        
        printf("Rotacionar a direita\n");
        if (balfilho >= 0) rot_dir(A);
        else rot_esq_dir(A); 
        
    } else if (bal < -1) {
    
        TipoArvore filhodir = (*A)->dir;
        int balfilho = checaFB(&filhodir);
        
        printf("Rotacionar a esquerda\n");
        if (balfilho <= 0) rot_esq(A);
        else rot_dir_esq(A);
    
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


void rot_dir(TipoArvore *A) {

    TipoArvore q, temp;
    
    // filho a esquerda da raiz
    q = (*A)->esq;
    // filho a direita de tal filho a esquerda
    temp = q->dir;
    
    // o filho a esquerda vira a raiz
    q->dir = *A;
    // e a sub-arvore temporaria muda de pai
    (*A)->esq = temp;
    
    // arrumar as alturas
    (*A)->alt = max(retornaAltura(&(*A)->dir), retornaAltura(&(*A)->esq)) + 1;
    q->alt = max(retornaAltura(&(q)->dir), retornaAltura(&(q)->esq)) + 1;
    
    // arruma o ponteiro pra raiz
    *A = q;
    
}

void rot_esq(TipoArvore *A) {

    TipoArvore q, temp;
    
    // filho a direita da raiz
    q = (*A)->dir; 
    // filho a esquerda de tal filho a direita
    temp = q->esq;
    
    // o filho a direita vira a raiz
    q->esq = *A;
    // e a sub-arvore temporaria muda de pai
    (*A)->dir = temp;
        
    // arrumar as alturas
    (*A)->alt = max(retornaAltura(&(*A)->dir), retornaAltura(&(*A)->esq)) + 1;
    q->alt = max(retornaAltura(&(q)->dir), retornaAltura(&(q)->esq)) + 1;
        
    // arruma o ponteiro pra raiz
    *A = q;
    
}

void rot_esq_dir(TipoArvore *A) {
    
    rot_esq(&(*A)->esq);
    rot_dir(A);
}

void rot_dir_esq(TipoArvore *A) {
    
    rot_dir(&(*A)->dir);
    rot_esq(A);
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

int max(int a, int b) {  
    return (a > b)? a : b;
}
