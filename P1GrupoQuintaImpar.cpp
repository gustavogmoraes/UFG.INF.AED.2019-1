#include <iostream>
#include <string>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &array)
{
    int i, j, key;

    for(i = 1; i < array.size(); i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array [j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

int ContagemDeComparacoes;

int BuscaLinear(vector<int> &vetor, int chave)
{
    for(int i = 0; i < vetor.size(); i++)
    {
        ContagemDeComparacoes++;
        if(vetor[i] == chave)
        {
            return i;
        }
    }
}

int BuscaBinariaAux(vector<int> &vetor, int indiceInicial, int indiceFinal, int chave)
{ 
    if (indiceFinal >= indiceInicial) 
    { 
        //int meio = indiceInicial + (indiceFinal - indiceInicial) / 2;
        int meio = (indiceInicial + indiceFinal) / 2; // Fórmula da busca binária

        // Igual
        ContagemDeComparacoes++;
        if(vetor[meio] == chave)
            return vetor[meio];

        //ContagemDeComparacoes++;
        if (vetor[meio] > chave) 
            return BuscaBinariaAux(vetor, indiceInicial, meio - 1, chave); 

        return BuscaBinariaAux(vetor, meio + 1, indiceFinal, chave); 
    } 

    return 0; 
}

int BuscaBinaria(vector<int> &vetor, int chave)
{
    return BuscaBinariaAux(vetor, 0, vetor.size() - 1, chave);
}

// Valor: 7,0 pontos
void ResolvaQuestao04()
{
    int numeroDeTestes, tamanhoDoVetor;
    cin >> numeroDeTestes >> tamanhoDoVetor;

    for (int i = 0; i < numeroDeTestes; i++)
    {
        int entrada;
        vector<int> vetor;
        for(int j = 0; j < tamanhoDoVetor; j++)
        {
            cin >> entrada;
            vetor.push_back(entrada);
        }

        int elementoBusca = vetor[0];
        InsertionSort(vetor);

        ContagemDeComparacoes = 0;
        BuscaLinear(vetor, elementoBusca);
        int comparacoesLinear = ContagemDeComparacoes;

        ContagemDeComparacoes = 0;
        BuscaBinaria(vetor, elementoBusca);
        int comparacoesBinaria = ContagemDeComparacoes;

        cout << comparacoesLinear << " " << comparacoesBinaria << "\n";
    }
}

int main()
{
    ResolvaQuestao04();
}