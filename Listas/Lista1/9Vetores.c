#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int numeroDeCasos;
    scanf("%i", &numeroDeCasos);

    int loop;
    for(loop = 0; loop < numeroDeCasos; loop++)
    {
        int a[100], b[100];
        int vetorResposta[200] = { 0 };
        int i,j,tmp;
        char numeroA[40],numeroB[40];

        scanf("%s %s", &numeroA, &numeroB);

        int l1 = strlen(numeroA);
        int l2 = strlen(numeroB);
        for(i = l1 - 1, j = 0; i >= 0; i--, j++)
        {
            a[j] = numeroA[i] - '0';
        }
		
        for(i = l2-1,j=0;i>=0;i--,j++)
        {
            b[j] = numeroB[i] - '0';
        }
		
        for(i = 0;i < l2; i++)
        {
            for(j = 0;j < l1; j++)
            {
                vetorResposta[i+j] += b[i]*a[j];
            }
        }
        for(i = 0; i < l1 + l2; i++)
        {
            tmp = vetorResposta[i] / 10;
            vetorResposta[i] = vetorResposta[i] % 10;
            vetorResposta[i + 1] = vetorResposta[i + 1] + tmp;
        }
		
        for(i = l1 + l2; i >= 0; i--)
        {
            if(vetorResposta[i] > 0)
                break;
        }
		
        for(;i >= 0;i--)
        {
            printf("%i", vetorResposta[i]);
        }

        printf("\n");
    }

    return 0;
}

