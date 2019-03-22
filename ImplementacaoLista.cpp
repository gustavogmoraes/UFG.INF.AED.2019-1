#include <iostream>
#include <vector>

using namespace std;

class Produto
{
    public: int Codigo;

    public: string Nome;
};

void ImprimaProduto(Produto produto)
{
    cout << "Codigo: " << produto.Codigo << "\n";
    cout << "Nome: " << produto.Nome << "\n";
}

template <typename T>
class List
{
    private:
        std::vector<T> _vetor;

        int IndexOfLast()
        {
            return Count() - 1;
        }
    
    public:
        T& operator[] (int index)
        {
            return _vetor[index];
        };

        int Count()
        {
            return _vetor.capacity();
        }

        T& First()
        {
            return _vetor[0];
        }

        T& Last()
        {
            return _vetor[IndexOfLast()];
        }

        void Add(T item)
        {
            _vetor.push_back(item);
        }

        void AddRange(List<T> lista)
        {
            for (int i =  0; i < lista.Count(); i++)
            {
                _vetor.push_back(lista[i]);
            }
        }

        void RemoveAt(int index)
        {
            _vetor.erase(index);
        }

        void RemoveFirst()
        {
            _vetor.erase[0];
        }

        void RemoveLast()
        {
            _vetor.erase[IndexOfLast()];
        }

        void RemoveRange(int startIndex, int endIndex)
        {
            for (int i = startIndex; i <= endIndex; i++)
            {
                _vetor.erase[i];
            }
        }

        // QuickSort
        void Sort()
        {

        }

        // int GetIndexOf(T item)
        // {
        //     for (int i = 0; i < vetor.capacity(); i++)
        //     {
        //         if (vetor[i] == item)
        //             return i;
        //     }

        //     return 0;
        // }
};
 
int main()
{
    List<Produto> listaDeProdutos;

    Produto produto;
    produto.Codigo = 1;
    produto.Nome = "Teste";

    Produto produto2;
    produto2.Codigo = 2;
    produto2.Nome = "Bosta";

    List<Produto> lista2;
    lista2.Add(produto);
    lista2.Add(produto2);

    listaDeProdutos.AddRange(lista2);

    ImprimaProduto(listaDeProdutos.Last());

    //cout << listaDeProdutos.GetIndexOf(produto2);

    cout << "\n";
    //system("clear");
}
