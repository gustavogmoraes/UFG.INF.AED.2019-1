#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &arr, int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) 
    { 
        key = arr[i]; 
        j = i - 1; 
        
        while (j >= 0 && arr[j] > key) 
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        }

        arr[j + 1] = key; 
    } 
}

vector<int> ObtenhaPares(vector<int> lista)
{
    vector<int> retorno;

    for(int i = 0; i < lista.size(); i++)
    {
        int numero = lista[i];
        if(numero % 2 == 0) 
            retorno.push_back(numero);
    }

    return retorno;
}

vector<int> ObtenhaImpares(vector<int> lista)
{
    vector<int> retorno;

    for(int i = 0; i < lista.size(); i++)
    {
        int numero = lista[i];
        if(numero % 2 != 0) 
            retorno.push_back(numero);
    }

    return retorno;
}

void ImprimaLista(vector<int> lista)
{
    for(int i = 0; i < lista.size(); i++)
    {
        cout<< lista[i] << "\n";
    }
}

void ImprimaReverso(vector<int> lista)
{
    for(int i = lista.size() - 1; i > -1; i--)
    {
        cout<< lista[i] << "\n";
    }
}

int main()
{
    int quantidadeDeNumeros, entrada;
    cin >> quantidadeDeNumeros;
    
    vector<int> listaDeNumeros;
    for (int i = 0; i < quantidadeDeNumeros; i++)
    {
        cin >> entrada;
        listaDeNumeros.push_back(entrada);
    }

    vector<int> pares = ObtenhaPares(listaDeNumeros);
    vector<int> impares = ObtenhaImpares(listaDeNumeros);

    InsertionSort(pares, pares.size());
    InsertionSort(impares, impares.size());

    ImprimaLista(pares);
    ImprimaReverso(impares);
}