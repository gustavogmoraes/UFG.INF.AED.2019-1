#include <iostream>

using namespace std;

int numeroDeChamadas;
int numeroDesejado;

int ObtenhaFibonacci(int numero)  
{
    if(numero == 0)
        return 0;
    else if(numero == 1)
      return 1;
    else
      return ObtenhaFibonacci(numero - 1) + ObtenhaFibonacci(numero - 2);
}

int main()
{
    cin >> numeroDesejado;

    cout << ObtenhaFibonacci(numeroDesejado) << "\n";

    return 0;
}