#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Produto
{
    public: int Codigo;

    public: string Nome;
};

void ImprimaProduto(Produto produto)
{
    std::cout << "Codigo: " << produto.Codigo << "\n";
    std::cout << "Nome: " << produto.Nome << "\n";
}

template <typename T>
class List
{
    private:
        vector<T> _vetor;

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
            return _vetor.size();
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

        void ForEach(function<void(T&)> action)
        {
            for (int i =  0; i < Count(); i++)
            {
                action(_vetor[i]);
            }
        }

        #pragma region Sort

        // A utility function to swap two elements 
        void swap(int* a, int* b) 
        { 
            int t = *a; 
            *a = *b; 
            *b = t; 
        } 
        
        /* This function takes last element as pivot, places 
        the pivot element at its correct position in sorted 
            array, and places all smaller (smaller than pivot) 
        to left of pivot and all greater elements to right 
        of pivot */
        int partition (int arr[], int low, int high) 
        { 
            int pivot = arr[high];    // pivot 
            int i = (low - 1);  // Index of smaller element 
        
            for (int j = low; j <= high- 1; j++) 
            { 
                // If current element is smaller than or 
                // equal to pivot 
                if (arr[j] <= pivot) 
                { 
                    i++;    // increment index of smaller element 
                    swap(&arr[i], &arr[j]); 
                } 
            } 
            swap(&arr[i + 1], &arr[high]); 
            return (i + 1); 
        } 
        
        /* The main function that implements QuickSort 
        arr[] --> Array to be sorted, 
        low  --> Starting index, 
        high  --> Ending index */
        void quickSort(int arr[], int low, int high) 
        { 
            if (low < high) 
            { 
                /* pi is partitioning index, arr[p] is now 
                at right place */
                int pi = partition(arr, low, high); 
        
                // Separately sort elements before 
                // partition and after partition 
                quickSort(arr, low, pi - 1); 
                quickSort(arr, pi + 1, high); 
            } 
        } 

        // QuickSort
        void Sort()
        {

        }

        void SortBy(function<string(T)>& propertyGetter)
        {

        }

        #pragma endregion

        // Busca Binaria
        // Espera-se que o vetor esteja ordenado
        int BuscaBinaria(int vetor[], int tamanho, int chave)
        {
            int cursor = 0;
            int ultimoElemento = tamanho - 1;
            int meio;
            while (cursor <= ultimoElemento)
            {
                meio = (cursor + ultimoElemento) / 2;
                if (vetor[meio] == chave)
                    return meio;
                else
                {
                    if (chave > vetor[meio])
                        cursor = meio + 1;
                    else
                        ultimoElemento = meio - 1;
                }
            }

            return -1;
        }

        //T&
        T* Find(function<bool(T)>& predicate)
		{
			for (int i = 0; i < _vetor.size(); i++)
			{
				if (predicate(_vetor[i]))
				{
					return &_vetor[i];
				}
			}

			return nullptr; // T();
		}
};

int main()
{
    List<Produto> listaDeProdutos;

    Produto produto2;
    produto2.Codigo = 2;
    produto2.Nome = "Teste2";

    Produto produto;
    produto.Codigo = 1;
    produto.Nome = "Teste";

    listaDeProdutos.Add(produto2);
    listaDeProdutos.Add(produto);

    function<void(Produto&)> lambda = [](Produto& x) { x.Nome = "Mudei"; };
    listaDeProdutos.ForEach(lambda);

    listaDeProdutos.ForEach(ImprimaProduto);

    //function<void(Produto*)> lambda2 = [](Produto* x) { ImprimaProduto(*x); };
    //listaDeProdutos.ForEach(lambda2);

    //function<string(Produto)> lambda1 = [](Produto x) { return to_string(x.Codigo); };
    //listaDeProdutos.SortBy(lambda1);

    //function<bool(Produto)> lambda = [](Produto x) { return x.Codigo == 3; };
    //Produto encontrado = *listaDeProdutos.Find(lambda);


    std::cout << "\n";
    //std::system("clear");
}   