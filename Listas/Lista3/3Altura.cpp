#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &vetor) 
{ 
    int i, chave, j; 
    for (i = 1; i < vetor.size(); i++) 
    { 
        chave = vetor[i]; 
        j = i - 1; 
        
        while (j >= 0 && vetor[j] > chave) 
        { 
            vetor[j + 1] = vetor[j]; 
            j = j - 1; 
        }

        vetor[j + 1] = chave; 
    } 
}

void ImprimaVetor(vector<int> vetor)
{
    for(int i = 0; i < vetor.size(); i++)
    {
        cout<< vetor[i] << " ";
    }

    cout << "\n";
}

int main()
{
    int numeroDeCidades, numeroDePessoas, entrada;
    cin >> numeroDeCidades;

    for(int i = 0; i < numeroDeCidades; i++)
    {
        cin >> numeroDePessoas;
        vector<int> alturas;
        for(int z = 0; z < numeroDePessoas; z++)
        {
            cin >> entrada;
            alturas.push_back(entrada);
        }

        InsertionSort(alturas);
        ImprimaVetor(alturas);
    }
}