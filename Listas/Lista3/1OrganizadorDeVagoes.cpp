#include <iostream>
#include <vector>

using namespace std;

int NumeroDeTrocas;

bool VerifiqueSeEstahOrdenado(vector<int> vagoes)
{
    for(int i = 0; i < vagoes.size() -1; i++)
    {
        if(vagoes[i + 1] < vagoes[i])
            return false;
    }

    return true;
}

void TroqueElementos(int* a, int* b)
{ 
    int temporario = *a; 
    *a = *b; 
    *b = temporario;

    NumeroDeTrocas++;
}

void RealizeTrocas(vector<int>& vagoes)
{
    for(int i = 0; i < vagoes.size() - 1; i++)
    {
        if(vagoes[i + 1] < vagoes[i]) 
            TroqueElementos(&vagoes[i + 1], &vagoes[i]);
    }
}

int Resolva(int numeroDeVagoes)
{
    vector<int> vagoes;
    for(int i = numeroDeVagoes; i > 0; i--)
    {
        int entrada;
        cin >> entrada;

        vagoes.push_back(entrada);
    }

    NumeroDeTrocas = 0;
    while(!VerifiqueSeEstahOrdenado(vagoes))
    {
        RealizeTrocas(vagoes);
    }

    return NumeroDeTrocas;
}

int main()
{
    int numeroDeTestes;
    cin >> numeroDeTestes;

    for (int i = numeroDeTestes; i > 0; i--)
    {
        int numeroDeVagoes;
        cin >> numeroDeVagoes;
        
        cout << Resolva(numeroDeVagoes) << "\n";
    }
}