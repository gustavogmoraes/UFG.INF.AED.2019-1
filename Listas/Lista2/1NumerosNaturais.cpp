#include <iostream>

using namespace std;

void ImprimaProximo(int numero, int quantidade)
{
    cout << ++numero << " ";

    if(numero == quantidade) return;

    ImprimaProximo(numero, quantidade);
}

int main()
{
    int quantidadeDeNumeros;
    cin >> quantidadeDeNumeros;

    ImprimaProximo(0, quantidadeDeNumeros);

    return 0;
}