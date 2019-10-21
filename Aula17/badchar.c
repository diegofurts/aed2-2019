#include <stdio.h>
#include <string.h>

#define TAM 256

int max (int a, int b) { return (a > b)? a: b; } 

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
    
    int lo[TAM];
    
    int i, j;
    int m = strlen(pat), n = strlen(txt);
    
    preprocBadChar(lo, pat);
    
    i = 0;
    while(i <= n-m) {
        //printf("%d\n", i);
        j=m-1;
        
        for (; j>=0 && pat[j] == txt[j+i]; j--);
        
        if(j < 0) {
            printf("Match na posicao %d\n", i);
            i += (m-lo[txt[i+m]]);
        } else {
            i += max(1, j-lo[txt[i+j]]);
        }
    
    }
    
}
