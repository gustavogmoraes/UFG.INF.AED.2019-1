#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, *valor, i, numero, k, contador;
    
    scanf("%d", &x);
    
    valor= (int*) malloc(x * sizeof(int));
    
    for(i = 0; i < x; i++){
        scanf("%d", &valor[i]);
        numero = valor[i];
        k = 2;
        contador = 0;
        while(k <= numero / 2){
            if((numero % k) == 0){
                contador++;
            }
            k++;
            
        }
        if(contador > 0){
            printf("N\n");
        }
        else{
            printf("S\n");
        }
    }
    
    return 0;
}
