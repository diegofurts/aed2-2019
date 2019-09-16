#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"
#include "Hash.h"

int HashFunc(TipoChave C) {
    return (C*C) % MAXTAM;
}

void InicializaHash(TipoHash H) {

    int i;
    for (i = 0; i < MAXTAM; i++)
        InicializaLista(&(H[i]));
        
    return;

}

void InsereHash(TipoHash H, TipoItem I) {

    int pos = HashFunc(I.Chave);
    InsereLista(&(H[pos]), I);
    return;

}

TipoItem PesquisaHash(TipoHash H, TipoChave C) {

    int pos = HashFunc(C);
    TipoNo *N = PesquisaLista(&(H[pos]), C);
    
    if (N==NULL) {
        TipoItem I;
        I.Chave = -1;
        return I;
    } else
        return N->Item;
}

void RemoveHash(TipoHash H, TipoChave C) {

    int pos = HashFunc(C);
    RemoveLista(&(H[pos]), C);
    return;

}


