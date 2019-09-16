#include <stdio.h>

int main() {

    int numbers[10000];
    int n = 0;
    
    while (scanf("%d ", &numbers[n])!=EOF) {
        
        printf("%d - %d\n", n, numbers[n]);
        n++;
        
    }
    
    return 0;    

}
