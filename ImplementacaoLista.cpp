#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

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

static map<string, function<int(string, string)>> MapeamentoDeFuncoesDeComparacao =
{
    { "string", [](string x, string y) 
        {   if (x > y) return -1;
            if (x == y) return 0;
            return 1; 
        } 
    },
    { "int", [](string x, string y) 
        {   if (stoi(x) > stoi(y)) return -1;
            if (stoi(x) == stoi(y)) return 0;
            return 1; 
        } 
    },
    { "float", [](string x, string y) 
        {   if (stof(x) > stof(y)) return -1;
            if (stof(x) == stof(y)) return 0;
            return 1; 
        } 
    },
    { "double", [](string x, string y) 
        {   if (stod(x) > stod(y)) return -1;
            if (stod(x) == stod(y)) return 0;
            return 1; 
        } 
    },
};

static int Compare(string tipoDaPropriedade, string x, string y)
{
    return MapeamentoDeFuncoesDeComparacao[tipoDaPropriedade](x, y);
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

        #pragma region Sort

        // Troca dois elementos de posição
        void TroqueElementos(T* a, T* b) 
        { 
            T temporario = *a; 
            *a = *b; 
            *b = temporario;
        } 

        int SortByCompareTo(function<string(T)>& propertyGetter, string tipoDaPropriedade, T x, T y)
        {
            return Compare(tipoDaPropriedade, propertyGetter(x), propertyGetter(y));
        }
        
        // Seleciona o último elemento como pivô, coloca ele na posição correta de acordo
        // com a ordenação, depois coloca todos os menores à esquerda e os maiores à direita.
        // Retorna o índice de partição.
        int SortByParticioneVetor(function<string(T)>& propertyGetter, string tipoDaPropriedade, int indiceInicial, int indiceFinal)
        {
            T pivo = _vetor[indiceFinal];
            int indiceDoMenorElemento = (indiceInicial - 1);
        
            for (int i = indiceInicial; i <= indiceFinal - 1; i++) 
            { 
                if (SortByCompareTo(propertyGetter, tipoDaPropriedade, _vetor[i], pivo) <= 0) 
                { 
                    indiceDoMenorElemento++;
                    TroqueElementos(&_vetor[indiceDoMenorElemento], &_vetor[i]); 
                } 
            }

            TroqueElementos(&_vetor[indiceDoMenorElemento + 1], &_vetor[indiceFinal]);

            return (indiceDoMenorElemento + 1); 
        }

        void SortByAux(function<string(T)>& propertyGetter, string tipoDaPropriedade, int indiceInicial, int indiceFinal)
        {
            if(indiceInicial < indiceFinal)
            {
                int indiceDeParticao = SortByParticioneVetor(propertyGetter, tipoDaPropriedade, indiceInicial, indiceFinal);

                // Ordena os elementos à esquerda e à direita do
                // índice de partição, separadamente, antes e depois da partição 
                SortByAux(propertyGetter, tipoDaPropriedade, indiceInicial, indiceDeParticao - 1); 
                SortByAux(propertyGetter, tipoDaPropriedade, indiceDeParticao + 1, indiceFinal); 
            }
        }

        #pragma endregion

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

        void SortBy(function<string(T)>& propertyGetter, string tipoDaPropriedade)
        {
            int indiceInicial = 0;
            int indiceFinal = Count() - 1;

            SortByAux(propertyGetter, tipoDaPropriedade, indiceInicial, indiceFinal);
        }

        //T&
        T* FindLinear(function<bool(T)>& predicate)
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

        // Busca Binaria
        // Espera-se que o vetor esteja ordenado
        // Retorna nullptr se o elemento não estiver presente
        T* FindBinary(function<string(T)>& propertyGetter, string tipoDaPropriedade, string chave)
        {
            int indiceInicial = 0;
            int indiceFinal = Count() - 1;

            return BuscaBinaria(indiceInicial, indiceFinal, propertyGetter, tipoDaPropriedade, chave);
        }

        T* BuscaBinaria(int indiceInicial, int indiceFinal, function<string(T)>& propertyGetter, string tipoDaPropriedade, string chave)
        { 
            if (indiceFinal >= indiceInicial) 
            { 
                int meio = indiceInicial + (indiceFinal - indiceInicial) / 2;

                // Igual
                if(Compare(tipoDaPropriedade, propertyGetter(_vetor[meio]), chave) == 0)
                    return &_vetor[meio];

                if (Compare(tipoDaPropriedade, propertyGetter(_vetor[meio]), chave) == 1) 
                     return BuscaBinaria(indiceInicial, meio - 1, propertyGetter, tipoDaPropriedade, chave); 

                return BuscaBinaria(meio + 1, indiceFinal, propertyGetter, tipoDaPropriedade, chave); 
            } 

            return nullptr; 
        }
};

int main()
{
    List<Produto> listaDeProdutos;
    Produto prod;
    prod.Codigo = 10;
    listaDeProdutos.Add(prod);
    //function<string(Produto)> lambdaSort = [](Produto x) { return to_string(x.Codigo); };
    //listaDeProdutos.SortBy(lambdaSort, "int");

    //function<void(Produto&)> lambda = [](Produto& x) { x.Nome = "Mudei"; };
    //listaDeProdutos.ForEach(lambda);

    function<string(Produto)> lambda = [](Produto x) { return to_string(x.Codigo); };
    Produto* encontrado = listaDeProdutos.FindBinary(lambda, "int", "10");

    if(encontrado != nullptr) cout << encontrado->Codigo;

    std::cout << "\n";
    //std::system("clear");
}   