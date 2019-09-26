#include <stdio.h>

void swap_vec(int *v, int pos1, int pos2) {

    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
    
}

int particao(int *v, int ini, int fim) {

    // pegar o do meio
    // se estiver ordenado, otimo
    // se estiver aleatorizado, tanto faz, certo?
    int pivo = (ini+fim)/2;
    
    swap_vec(v, ini, pivo);    
    pivo = ini;
    
    int i, j;
    i = ini + 1;
    j = fim - 1;
    
    while(i <= j) {
    
        while(i < fim && v[i] <= v[pivo]) i++;
        while(v[j] > v[pivo]) j--;
        
        if (i < j)
            swap_vec(v, i, j);
    
    }
    
    //if (v[j] < v[pivo]) j = pivo;
    swap_vec(v, pivo, j);
    
    return j;

}

void select(int *v, int ini, int fim, int k) {

    
    //caso base
    if (ini >= fim) return; 
    
    int j = particao(v, ini, fim);
    if (j == k) return;
    if (k < j)
        select(v, ini, j, k);
    else
        select(v, j+1, fim, k );
    
    return;

}


int main() {

    int v[1000];
    int n, k;
    
    scanf("%d %d ", &n, &k);
    
    for (int i = 0; i < n; i++)
        scanf("%d ", &v[i]);
    
    select(v, 0, n, k-1);
    printf("k-th elemento: %d\n", v[k-1]);

    return 0;

}
