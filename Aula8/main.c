#include<stdio.h>
#include<stdlib.h>
#include "Hash.h"

int main() {

    TipoHash H;
    TipoItem item;

    InicializaHash(H);

    item.Chave = 5;
    InsereHash(H, item);
    
    item.Chave = 130;
    InsereHash(H, item);
    
    item.Chave = 245;
    InsereHash(H, item);
    
    item.Chave = 930;
    InsereHash(H, item);
    
    item.Chave = 210;
    InsereHash(H, item);
    
    item.Chave = 125;
    InsereHash(H, item);
    
    item.Chave = 10;
    InsereHash(H, item);
    
    item.Chave = 100;
    InsereHash(H, item);
    
    item.Chave = 1000;
    InsereHash(H, item);
        
    item = PesquisaHash(H, 3); printf("%d\n", item.Chave);
    item = PesquisaHash(H, 100); printf("%d\n", item.Chave);
    item = PesquisaHash(H, 125); printf("%d\n", item.Chave);
        
    RemoveHash(H, 3);
    RemoveHash(H, 100);
    RemoveHash(H, 125);
	
	return 0;
}
