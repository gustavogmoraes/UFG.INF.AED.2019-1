#include <iostream>

using namespace std;

int ObtenhaReverso(int numero)
{
    int base = 1;

    while (numero / (base * 10)){
        base *= 10;
    }

    if (numero <= 9)
    {
        return numero;
    } 
    else if (numero >= 10)
    {
        int reverso = (numero % 10) * base;
        return ObtenhaReverso(numero / 10) + reverso;
    }
}

int main()
{
    int numero;
    cin >> numero;

    cout << ObtenhaReverso(numero);

    return 0;
}