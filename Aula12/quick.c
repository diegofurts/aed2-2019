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

void quicksort(int *v, int ini, int fim) {

    
    //caso base
    if (ini >= fim) return; 
    
    int j = particao(v, ini, fim);
    quicksort(v, ini, j);
    quicksort(v, j+1, fim);
    
    return;

}


int main() {

    int v[1000];
    int n;
    
    scanf("%d ", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d ", &v[i]);
    
    printf("Vetor inicial:");
    for (int i = 0; i < n; i++)
        printf(" %d", v[i]);
    printf("\n\n\n");
    
    quicksort(v, 0, n);
    
    printf("Vetor final:");
    for (int i = 0; i < n; i++)
        printf(" %d", v[i]);
    printf("\n");

    return 0;

}
