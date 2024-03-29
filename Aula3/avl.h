#ifndef AVL_H
#define AVL_H

typedef int TipoChave;

typedef struct {
	TipoChave Chave;
	char Numeral[100];
	/* Outros campos */
} TipoItem;

typedef struct TipoNo {
	TipoItem Item;
	struct TipoNo *esq, *dir;
	int alt; // altura
} TipoNo;

typedef struct TipoNo *TipoApontador;
typedef TipoApontador TipoArvore;


void CriaArvore(TipoArvore *A);
void CriaRaiz(TipoArvore *A, TipoItem I);

int retornaAltura(TipoArvore *A);
int checaFB(TipoArvore *A);

void Insere(TipoArvore *A, TipoItem I);
TipoItem Pesquisa(TipoArvore *A, TipoChave C);
void Remove(TipoArvore *A, TipoChave C);

void rot_dir(TipoArvore *A);
void rot_esq(TipoArvore *A);
void rot_dir_esq(TipoArvore *A);
void rot_esq_dir(TipoArvore *A);

void visita(TipoArvore A);
void emOrdem(TipoArvore A);

int max(int a, int b);

#endif
