#include <stdio.h>
#include <string.h>

#define TAM 256

int max (int a, int b) { return (a > b)? a: b; } 

void preprocBadChar(int *lo, char *pat) {

    int m = strlen(pat);
    int i;
    
    for (i = 0; i < TAM; i++)
        lo[i] = -1;
    
    for (i = 0; i < m; i++)
        lo[pat[i]] = i;

}

int main() {

    char txt[] = "ABAAAABAACDABABCCBACABABACAAABACABA"; 
    char pat[] = "ABA";
    
    int lo[TAM];
    
    int i, j;
    int m = strlen(pat), n = strlen(txt);
    
    preprocBadChar(lo, pat);
    //printf("%d %d %d\n", lo['A'], lo['B'], lo['C']);
    
    i = 0; // i vai indexar a posicao no txt
    while(i <= (n - m)) {
        
        j = m-1; // a cada laco, comeca do ultimo char do pat
        
        // reduz ate dar mismatch
        while(j >= 0 && pat[j] == txt[i+j])
            j--;
            
        if (j < 0) {
        
            printf("Match na posicao %d\n", i);
            // pode pular ate a posicao de match do proximo caracter
            //if (i+m < n)
                i += m-lo[txt[i+m]];
            //else
                //i++;
            
        } else {
        
            // entre 1 e a diferenca, caso de negativo (a ultima ocorrencia esta pra frente)
            // i + j marca o caracter em txt que deu mismatch
            i += max(1, j - lo[txt[i+j]]); 
        
        }
    
    }
            

}
