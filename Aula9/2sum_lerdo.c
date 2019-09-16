#include <stdio.h>

int main() {

    int numbers[200000];
    int n = 0, k;
    
    scanf("%d ", &k);
    
    while (scanf("%d ", &numbers[n])!=EOF)
        n++;
    
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++) {
            if (numbers[i]+numbers[j] == k) {
                printf("Encontrou %d %d\n", numbers[i],numbers[j]);
                return 0;
            }
        }
    
    printf("Nao encontrou\n");
    
    return 0;    

}
