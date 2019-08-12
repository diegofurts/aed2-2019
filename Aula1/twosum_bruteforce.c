#include <stdio.h>

int main()
{
    
    int n, vetor[101], i, j, s, achou = 0;
    
    scanf("%d ", &n);
    for(i=0;i < n; i++)
        scanf("%d ", &v[i]);
    
    scanf("%d ", &s);
        
    for(i=0;i < n && !achou; i++) {
        
        for(j=i;j < n && !achou; j++) {
            if (v[i] + v[j] == s) {achou = 1;}
        }
            
    }
    
    if (achou) printf("ACHOU!!\n");
    else printf("ERRRROOOOUUUUU!!\n");
    
    return 0;
}
