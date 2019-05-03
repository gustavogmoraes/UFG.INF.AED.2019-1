#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Aluno
{
    public:
        string Nome;
        int Nota;

        int CompareTo(Aluno outroAluno)
        {
            if (Nota < outroAluno.Nota) return -1;
            if (Nota > outroAluno.Nota) return 1;

            if (Nome < outroAluno.Nome) return 1;
            if (Nome == outroAluno.Nome) return 0;
            return -1;
        }

        void Imprima()
        {
            cout << Nome << " " << Nota;
        }
};

void InsertionSort(vector<Aluno> &vetor) 
{ 
    Aluno chave;
    int i, j; 
    for (i = 1; i < vetor.size(); i++) 
    { 
        chave = vetor[i]; 
        j = i - 1; 
        
        while (j >= 0 && vetor[j].CompareTo(chave) == 1) 
        { 
            vetor[j + 1] = vetor[j]; 
            j = j - 1; 
        }

        vetor[j + 1] = chave; 
    } 
}

void ImprimaReverso(vector<Aluno> lista)
{
    for(int i = lista.size() - 1; i > -1; i--)
    {
        if(i == 0)
        {
            lista[i].Imprima();
            cout << "*\n";
            continue;
        }
            
        lista[i].Imprima();
        cout << "\n";
    }
}

int main()
{
    int numeroDeTestes, nota;
    string nome;
    cin >> numeroDeTestes;

    vector<Aluno> alunos;
    for(int i = 0; i < numeroDeTestes; i++)
    {
        Aluno aluno;
        cin >> aluno.Nome >> aluno.Nota;

        alunos.push_back(aluno);
    }

    InsertionSort(alunos);
    ImprimaReverso(alunos);
}