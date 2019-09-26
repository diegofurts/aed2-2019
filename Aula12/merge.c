#include <stdio.h>

void merge(int *v, int ini, int meio, int fim) {

    int vaux[fim-ini];
    int i = ini, j = meio, pos = 0;
    
    while (i < meio && j < fim) {
    
        if(v[i] <= v[j]) vaux[pos++] = v[i++];
        else vaux[pos++] = v[j++];
    
    }
    
    while(i < meio) vaux[pos++] = v[i++];
    while(j < fim) vaux[pos++] = v[j++];
    
    for(i = ini, pos = 0; i < fim; i++, pos++)
        v[i] = vaux[pos];
    
    return;
    

}

void mergesort(int *v, int ini, int fim) {

    if (fim <= ini+1) return;
    
    int m = (ini+fim)/2;
    mergesort(v, ini, m );
    mergesort(v,m,fim);
    merge(v, ini, m, fim);

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
    
    mergesort(v, 0, n);
    
    printf("Vetor final:");
    for (int i = 0; i < n; i++)
        printf(" %d", v[i]);
    printf("\n");

    return 0;

}
