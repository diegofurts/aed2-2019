#include <stdio.h>
#include <string.h>

int max (int a, int b) { return (a > b)? a: b; } 

void preprocGoodSuffix(int *gs, char *pat) {


    int m = strlen(pat);
    int i, j, r;
    

    for (i = m-1, j = m - 2; i >= 0; i--) {
    
        r = 0;
        
        // r < tamanho do sufixo
        // j-r tem que ser >= 0
        while(r < m - i && r <= j) {
            if (pat[m-1-r] == pat[j-r]) {
                r++;
            } else { //recomeca a tentar achar o padrao
                j--; r=0;
            }
        }
        
        if (r < m - i) j = -1; // r menor que o tamanho do sufixo = nao deu match inteiro pq acabou o padrao        
            
        gs[i] = m - 2 - j;
        
    }
    
    /*for (i = 0; i < m; i++)
        printf("%d ", gs[i]);
    printf("\n");*/

}

int main() {

    char txt[] = "AABABACABABBAAAABAAABABACABABCDABABCCBACABABACAAAABABACABABBACABA"; 
    char pat[] = "ABABACABAB";
    
    int i, j;
    int m = strlen(pat), n = strlen(txt);
    
    int gs[m+1];
    gs[m] = 1;
    
    preprocGoodSuffix(gs, pat);
    //printf("%d %d %d\n", lo['A'], lo['B'], lo['C']);
    
    i = 0; // i vai indexar a posicao no txt
    while(i <= (n - m)) {
        //printf("%d\n", i);
        j = m-1; // a cada laco, comeca do ultimo char do pat
        
        // reduz ate dar mismatch
        while(j >= 0 && pat[j] == txt[i+j])
            j--;
            
        if (j < 0) {
        
            printf("Match na posicao %d\n", i);
            i++;
            
        } else {        
            i += gs[j+1];        
        }
    
    }
            

}
