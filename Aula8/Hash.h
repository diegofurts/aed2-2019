#ifndef HASH_H
#define HASH_H

#include "Lista.h"

#define MAXTAM 113

typedef TipoLista TipoHash[MAXTAM];

void InicializaHash(TipoHash H);
void InsereHash(TipoHash H, TipoItem I);
TipoItem PesquisaHash(TipoHash H, TipoChave C);
void RemoveHash(TipoHash H, TipoChave C);

#endif
