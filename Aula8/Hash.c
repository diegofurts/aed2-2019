#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"
#include "Hash.h"

int HashFunc(TipoChave C) {

    return (C*C) % MAXTAM;

}

void InicializaHash(TipoHash H);
void InsereHash(TipoHash H, TipoItem I);
TipoItem PesquisaHash(TipoHash H, TipoChave C);
void RemoveHash(TipoHash H, TipoChave C);


