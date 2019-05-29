#include <iostream>
#include <vector>

using namespace std;

class ConjuntoDeNaturais
{
    public:
        void InsiraElementoNoConjunto(int elemento)
        {

        }

        void ExcluaElementoDoConjunto(int elemento)
        {

        }

        bool VerifiqueSeElementoEstahNoConjunto(int elemento)
        {

        }

        bool VerifiqueSeConjuntoEhVazio()
        {

        }

        bool VerifiqueSeConjuntosSaoIdenticos(ConjuntoDeNaturais outroConjunto)
        {

        }

        bool VerifiqueSeEhSubconjunto(ConjuntoDeNaturais conjuntoMacro)
        {

        }

        ConjuntoDeNaturais ObtenhaComplemento()
        {

        }

        ConjuntoDeNaturais ObtenhaDiferenca(ConjuntoDeNaturais outroConjunto)
        {

        }

        ConjuntoDeNaturais ObtenhaConjuntoDasPartes()
        {

        }

        void MostreElementos()
        {

        }

        void DestruaConjunto()
        {

        }

    private:
        vector<int> _vetorDeElementos;
};

int ExibaMenuERecebaEntrada()
{
    system("clear");

    cout << "Digite uma opcao \n" << 
            "1 - Criar conjunto \n" <<
            "2 - Incluir elemento no conjunto\n" <<
            "3 - Excluir elemento no conjunto\n" <<
            "4 - Incluir elemento no conjunto\n" <<
            "5 - Incluir elemento no conjunto\n" <<
            "6 - Incluir elemento no conjunto\n" <<
            "7 - Incluir elemento no conjunto\n" <<
            "8 - Incluir elemento no conjunto\n" <<
            "9 - Incluir elemento no conjunto\n" <<
            "10 - Incluir elemento no conjunto\n" <<
            "11 - Incluir elemento no conjunto\n" <<
            "12 - Incluir elemento no conjunto\n" <<
            "Entrada: ";

    int entrada;
    cin >> entrada;

    return entrada;
}

int main()
{
    bool terminar = false;
    ConjuntoDeNaturais conjunto;

    while(!terminar)
    {
        auto entrada = ExibaMenuERecebaEntrada();
        
        switch(entrada)
        {
            case 1:
                cout << "Conjunto criado";
                getchar();
                break;

            case 2:
                cout << "Informe o elemento para incluir: ";

                int elemento;
                cin >> elemento;

                conjunto.InsiraElementoNoConjunto(elemento);
                break;

            default:
                terminar = true;
                break;
        }
    }
}

//1. criar um conjunto C, inicialmente vazio: criaConjunto(C);
//2. incluir o elemento x no conjunto C: insereElementoConjunto(x, C);
//3. excluir o elemento x do conjunto C: insereElementoConjunto(x, C);
//4. verificar se o elemento x pertence ao conjunto C: eElementoConjunto(x, C);
//5. verificar se o conjunto C é vazio: conjuntoVazio(C);
//6. comparar se dois conjuntos, C1 e C2 são idênticos: conjuntosIdenticos(C1, C2);
//7. identificar se o conjunto C1 é subconjunto do conjunto C2: subconjunto(C1, C2);
//8. gerar o complemento do conjunto C1 em relação ao conjunto C2: complemento(C1, C2); 
//9. gerar a diferença entre o conjunto C1 e o conjunto C2: diferenca(C1, C2);
//10. gerar o conjunto das partes do conjunto C: conjuntoPartes(C);
//11. mostrar os elementos presentes no conjunto C: mostraConjunto(C); 
//12. destrui o conjunto C: destroiConjunto(C).