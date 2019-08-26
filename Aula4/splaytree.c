#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "splaytree.h"

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
        printf("Inserindo item com chave %d\n", (*A)->Item.Chave);
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

// A função splay é também a função de pesquisa
TipoArvore *Splay(TipoArvore *A, TipoChave C) {

    TipoItem I;

    if (C == (*A)->Item.Chave || (*A) == NULL) { //achou não existe
        return A;
    }
            
    
    if (C > (*A)->Item.Chave) { // vai para a direita
    
        if ((*A)->dir == NULL) return A; // não vai achar mesmo
        
        if (C > (*A)->dir->Item.Chave) { // direita esquerda (zig zag)
        } else { // direita direita (zig zig)
        }

        return Splay(&(*A)->dir, C);
    
    } else { // vai para a esquerda
    
        if ((*A)->esq == NULL) return A; // não vai achar mesmo
        
        if (C > (*A)->esq->Item.Chave) { // esquerda direita (zag zig)
        } else { // esquerda esquerda (zag zag)
        }
    
        return Splay(&(*A)->esq, C);
    
    }

}

/*void static achaMenorETroca(TipoArvore *A, TipoArvore *Atual) {

    if ((*Atual)->esq == NULL) { // mais a direita possivel
        (*A)->Item = (*Atual)->Item;
        TipoApontador p = (*Atual); // guarda para apagar
        (*Atual) = (*Atual)->dir;
        free(p);
    } else {
        achaMenorETroca(A, &(*Atual)->esq);
    }

}*/

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

    //printf("Entrou na remocao do item com chave %d, olhando %d\n", C, (*A)->Item.Chave);

    if ((*A) == NULL) { // nao achou
        printf("ERRO ao remover: nao encontrou a chave\n");
        return;
    }
    
    if (C > (*A)->Item.Chave) { // direita
        Remove(&(*A)->dir, C);
        return;
    } else if (C < (*A)->Item.Chave) { // esquerda
        Remove(&(*A)->esq, C);
        return;
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


/*void rot_dir(TipoArvore *A) {

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
}*/


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
