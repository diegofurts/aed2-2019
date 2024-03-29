#ifndef SplayTree_H
#define SplayTree_H

typedef int TipoChave;

typedef struct {
	TipoChave Chave;
	char Numeral[100];
	/* Outros campos */
} TipoItem;

typedef struct TipoNo {
	TipoItem Item;
	struct TipoNo *esq, *dir;
} TipoNo;

typedef struct TipoNo *TipoApontador;
typedef TipoApontador TipoArvore;


void CriaArvore(TipoArvore *A);
void CriaRaiz(TipoArvore *A, TipoItem I);

void Insere(TipoArvore *A, TipoItem I);
TipoArvore *Splay(TipoArvore *A, TipoChave C);
void Remove(TipoArvore *A, TipoChave C);

void zag(TipoArvore *A);
void zig(TipoArvore *A);

void visita(TipoArvore A);
void emOrdem(TipoArvore A);

#endif
