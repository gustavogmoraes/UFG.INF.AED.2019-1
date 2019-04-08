#include <iostream>

using namespace std;

const int R$_2 = 0;
const int R$_5 = 1;
const int R$_10 = 2;
const int R$_20 = 3;
const int R$_50 = 4;
const int R$_100 = 5;

int QuantidadeDeNotas[6];
int QuantidadeDeManeirasParaTroco;

int main()
{
    int valorDoSaque;
    cin >> valorDoSaque;

    cin >> QuantidadeDeNotas[R$_2] >> QuantidadeDeNotas[R$_5] >> QuantidadeDeNotas[R$_10] >> 
           QuantidadeDeNotas[R$_20] >> QuantidadeDeNotas[R$_50] >> QuantidadeDeNotas[R$_100];

    cout << QuantidadeDeManeirasParaTroco;
}