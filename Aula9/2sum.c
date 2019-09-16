#include <stdio.h>
#include "Hash.h"

int main() {

    TipoHash h;
    TipoItem item;
    int v;
    int k;
    
    InicializaHash(h);
    
    scanf("%d ", &k);
    
    while (scanf("%d ", &v)!=EOF) {
        
        item = PesquisaHash(h, k-v);
        if (item.Chave >= 0) {
            printf("Encontrou %d %d\n", v, k-v);
            return 0;
        }
        
        item.Chave = v;
        InsereHash(h, item);
        
    }
    
    printf("Nao encontrou\n");
    return 0;    

}
