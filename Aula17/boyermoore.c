#include <stdio.h>
#include <string.h>

#define TAM 256

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
}

void preprocBadChar(int *lo, char *pat) {

    int m = strlen(pat);
    
    int i;
    for(i = 0; i < TAM; i++)
        lo[i] = -1;
    
    for (i = 0; i < m; i++)
        lo[pat[i]] = i;

}

int main() {

    char txt[] = "AABABACABABBAAAABAAABABACABABCDABABCCBACABABACAAAABABACABABBACABA"; 
    char pat[] = "ABABACABAB";
    
    int i, j;
    int m = strlen(pat), n = strlen(txt);
    
    int lo[TAM];
    int gs[m+1];
    gs[m] = 1;
    
    preprocBadChar(lo, pat);    
    preprocGoodSuffix(gs, pat);
    
    i = 0;
    while(i <= n-m) {
        //printf("%d\n", i);
        j=m-1;
        
        for (; j>=0 && pat[j] == txt[j+i]; j--);
        
        if(j < 0) {
            printf("Match na posicao %d\n", i);
            i += (m-lo[txt[i+m]]);
        } else {
            i += max(gs[j+1], j-lo[txt[i+j]]);
        }
    
    }
               

}
