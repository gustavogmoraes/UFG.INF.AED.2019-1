#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valorMaximo, numeroA, numeroB, resultado;
    char operacao;

    scanf("%i", &valorMaximo);
    scanf("%i %c %i", &numeroA, &operacao, &numeroB);

    if(operacao == '+')
        resultado = numeroA + numeroB;
    else if(operacao == '*')
        resultado = numeroA * numeroB;

    printf("%s", resultado <= valorMaximo ? "ok" : "overflow");

    return 0;
}