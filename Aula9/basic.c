#include <stdio.h>

int main() {

    int numbers[10000];
    int n = 0, k;
    
    scanf("%d ", &k);
    
    while (scanf("%d ", &numbers[n])!=EOF)
        n++;
    
    return 0;    

}
