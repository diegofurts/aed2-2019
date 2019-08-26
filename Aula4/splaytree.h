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

/*void rot_dir(TipoArvore *A);
void rot_esq(TipoArvore *A);
void rot_dir_esq(TipoArvore *A);
void rot_esq_dir(TipoArvore *A);*/

void visita(TipoArvore A);
void emOrdem(TipoArvore A);

int max(int a, int b);

#endif
