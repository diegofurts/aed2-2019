#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"
#include "Hash.h"

int HashFunc(TipoChave C) {

    return (C*C) % MAXTAM;

}


