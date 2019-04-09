#include <iostream>
#include <sstream>

using namespace std;

int ObtenhaResto(int dividendo, int divisor)
{
    return dividendo % divisor;
}

string ConvertaDecimalParaBinario(int numeroDecimal)
{
    string retorno;
    while(numeroDecimal > 0)
    {
        int resto = ObtenhaResto(numeroDecimal, 2);
        std::stringstream ss;
        ss << resto;
        retorno.append(ss.str());
        numeroDecimal = numeroDecimal / 2;
    }

    return retorno;
}

int main()
{
    int quantidadeDeTestes, numeroDecimal;

    while (int i = 0 < quantidadeDeTestes)
    {
        cin >> numeroDecimal;

        cout << ConvertaDecimalParaBinario(numeroDecimal);
    }

    return 0;
}