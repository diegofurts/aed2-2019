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

static void InsereRecursivo(TipoArvore *A, TipoItem I) {

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

void Insere(TipoArvore *A, TipoItem I) {

    InsereRecursivo(A, I);
    Splay(A, I.Chave);
    return;
    
}

// A função splay é também a função de pesquisa
TipoArvore *Splay(TipoArvore *A, TipoChave C) {

    TipoItem I;

    if ((*A) == NULL || C == (*A)->Item.Chave) { //achou não existe
        //printf("Caso base %d\n", (*A) == NULL);
        return A;
    }
    
    //printf("Chave da recursao = %d\n", (*A)->Item.Chave);
            
    
    if (C > (*A)->Item.Chave) { // vai para a direita
    
        if ((*A)->dir == NULL) return A; // não vai achar mesmo
        
        //caso especial que preciso tratar de outro jeito para
        //poder usar depois da inserção e nas buscas
        if (C == (*A)->dir->Item.Chave) {
            zag(A);
            return A;
        }
        
        if (C <= (*A)->dir->Item.Chave) { // direita esquerda (zig zag)
            //printf("Caso 1\n");
            // Primeiro, traz a chave recursivamente
            (*A)->dir->esq = *(Splay(&(*A)->dir->esq, C));
            
            // primeira rotação
            zig(A);
        
        } else { // direita direita (zag zag)
            //printf("Caso 2\n");
            // Primeiro, traz a chave recursivamente
            (*A)->dir->dir = *(Splay(&(*A)->dir->dir, C));
            
            // primeira rotação
            zag(A);
            
        }
            
        return A;
    
    } else { // vai para a esquerda
    
        if ((*A)->esq == NULL) return A; // não vai achar mesmo
        
        //caso especial que preciso tratar de outro jeito para
        //poder usar depois da inserção e nas buscas
        if (C == (*A)->esq->Item.Chave) {
            zig(A);
            return A;
        }
        
        if (C > (*A)->esq->Item.Chave) { // esquerda direita (zag zig)
            //printf("Caso 3\n");
            // Primeiro, traz a chave recursivamente
            (*A)->esq->dir = *(Splay(&(*A)->esq->dir, C));
            
            // primeira rotação
            zag(A);
        
        } else { // esquerda esquerda (zig zig)
            //printf("Caso 4\n");
            // Primeiro, traz a chave recursivamente
            (*A)->esq->esq = *(Splay(&(*A)->esq->esq, C));
            
            // primeira rotação
            zig(A);
            
        }
    
        return A;
    
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
        achaMaiorETroca(A, &(*A)->esq);
    }
    
}


/*
similar ao rot_dir da AVL

        k2                   k1
       /  \                 /  \
      k1   Z     ==>       X   k2
     / \                      /  \
    X   Y                    Y    Z
*/
void zig(TipoArvore *A) {

    TipoArvore q, temp;
    
    // filho a esquerda da raiz
    q = (*A)->esq;
    // filho a direita de tal filho a esquerda
    temp = q->dir;
    
    // o filho a esquerda vira a raiz
    q->dir = *A;
    // e a sub-arvore temporaria muda de pai
    (*A)->esq = temp;
    
    // arruma o ponteiro pra raiz
    *A = q;
    
}

/*
similar ao rot_esq da AVL

        k2                       k1
       /  \                     /  \
      X    k1         ==>      k2   Z
          /  \                /  \
         Y    Z              X    Y

*/
void zag(TipoArvore *A) {

    TipoArvore q, temp;
    
    // filho a direita da raiz
    q = (*A)->dir; 
    // filho a esquerda de tal filho a direita
    temp = q->esq;
    
    // o filho a direita vira a raiz
    q->esq = *A;
    // e a sub-arvore temporaria muda de pai
    (*A)->dir = temp;
        
    // arruma o ponteiro pra raiz
    *A = q;
    
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

