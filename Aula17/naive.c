#include <stdio.h>
#include <string.h>

int main() {

    char txt[] = "ABAAAABAACDABABCCBACABABACAAABACABA"; 
    char pat[] = "ABA";
    
    int i, j;
    int m = strlen(pat), n = strlen(txt);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m && txt[i+j]==pat[j]; j++);
        if (j == m) printf("Match na posicao %d\n", i);
    }
            

}
