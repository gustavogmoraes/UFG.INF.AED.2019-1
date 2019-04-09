#include <iostream>

using namespace std;

int QuantidadeMinimaDeTestes;

bool RealizeTesteDeEstouro(int n, int k)
{

}

int main()
{
    int quantidadeMaximaDeHelio, numeroDeBaloes;

    cin >> quantidadeMaximaDeHelio >> numeroDeBaloes;

    QuantidadeMinimaDeTestes = 0;

    RealizeTesteDeEstouro(quantidadeMaximaDeHelio, numeroDeBaloes);

    cout << QuantidadeMinimaDeTestes << "\n";
}