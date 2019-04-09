#include <iostream>
#include <vector>

using namespace std;

enum EnumNotas
{
    N_2,

    N_5,

    N_10,

    N_20,

    N_50,

    N_100
};

class Saque
{
    public:
        int Notas[6];
};

int QuantidadeDeManeirasParaTroco;

int Notas[6];

vector<Saque> Saques;
vector<Saque> Resultado;

int Iteracao;

int ObtenhaNota(EnumNotas item)
{
    switch(item)
    {
        case N_2:
            return 2;
            break;
        case N_5:
            return 5;
            break;
        case N_10:
            return 10;
            break;
        case N_20:
            return 20;
            break;
        case N_50:
            return 50;
            break;
        case N_100:
            return 100;
            break;
    }

    return 1;
}

void Resolva(int valor, int divisor)
{
    if(valor == 0 || divisor == -1)
        return;
    
    if(valor / ObtenhaNota((EnumNotas)divisor) > 0 && Notas[divisor] > 0)
    {
        valor -= ObtenhaNota((EnumNotas)divisor);
        Notas[divisor]--;
        Saques[Iteracao].Notas[divisor]++;
    }
    else divisor--;

    Resolva(valor, divisor);
}

bool VerifiqueSeSaqueJaExisteNoResultado(Saque saque)
{
    for(int i = 0; i < Resultado.size(); i++)
    {
        if(Resultado[i].Notas[N_2] == saque.Notas[N_2] &&
           Resultado[i].Notas[N_5] == saque.Notas[N_5] &&
           Resultado[i].Notas[N_10] == saque.Notas[N_10] &&
           Resultado[i].Notas[N_20] == saque.Notas[N_20] &&
           Resultado[i].Notas[N_50] == saque.Notas[N_50] &&
           Resultado[i].Notas[N_100] == saque.Notas[N_100])
        {
            return true;
        }
    }

    return false;
}

void SetNotas(int n2, int n5, int n10, int n20, int n50, int n100)
{
    Notas[0] = n2;
    Notas[1] = n5;
    Notas[2] = n10;
    Notas[3] = n20;
    Notas[4] = n50;
    Notas[5] = n100;
}

int main()
{
    int valorDoSaque, n2, n5, n10, n20, n50, n100;
    cin >> valorDoSaque;

    cin >> n2 >> n5 >> n10 >> n20 >> n50 >> n100;

    Iteracao = 0;
    SetNotas(n2, n5, n10, n20, n50, n100);
    for(int i = 5; i > -1; i--)
    {
        //SetNotas(n2, n5, n10, n20, n50, n100);
        Saque saque;
        Saques.push_back(saque);
        Resolva(valorDoSaque, (EnumNotas)i);

        saque = Saques[Iteracao];
        if(!VerifiqueSeSaqueJaExisteNoResultado(saque))
        {
            Resultado.push_back(saque);
        }

        Iteracao++;
    }

    cout << Resultado.size() - 1;
}