#include <iostream>
#include <vector>

using namespace std;

class Coordenada
{
    public:
        int X;
        int Y;
};

const char AGUA = '.';
const char PARTE_DE_NAVIO = '#';
const char PARTE_DE_NAVIO_DESTRUIDA = '@';

vector<vector<char>> Tabuleiro;

int QuantidadeDeNaviosAfundados;

void InicializeTabuleiro(int numeroDeLinhas, int numeroDeColunas)
{
    Tabuleiro = vector<vector<char>>(numeroDeLinhas, vector<char>(numeroDeColunas));
}

void LeiaTabuleiro(int numeroDeLinhas, int numeroDeColunas)
{
    cin.clear();
	for(int a = 0; a < numeroDeLinhas; a++)
    {
        for(int j = 0; j < numeroDeColunas; j++)
        {
            cin >> Tabuleiro[a][j];
        }
    }
}

vector<Coordenada> ObtenhaQuadrante(Coordenada coordenada)
{
    // Levar em conta os limites do tabuleiro --> esse é o erro atual
    vector<Coordenada> retorno;

    Coordenada coordenada1;
    coordenada1.X = coordenada.X - 1;
    coordenada1.Y = coordenada.Y;

    retorno.push_back(coordenada1);

    Coordenada coordenada2;
    coordenada2.X = coordenada.X + 1;
    coordenada2.Y = coordenada.Y;

    retorno.push_back(coordenada2);

    Coordenada coordenada3;
    coordenada3.X = coordenada.X;
    coordenada3.Y = coordenada.Y - 1;

    retorno.push_back(coordenada3);

    Coordenada coordenada4;
    coordenada4.X = coordenada.X;
    coordenada4.Y = coordenada.Y + 1;

    retorno.push_back(coordenada4);

    return retorno;
}

bool VerifiqueSeNavioFoiDestruidoCompletamente(Coordenada coordenada)
{
    vector<Coordenada> quadrante = ObtenhaQuadrante(coordenada);
    bool resultado = true;

    int cont = quadrante.capacity();

    for(int i = 0; i < 4; i++)
    {
        if(Tabuleiro[quadrante[i].X][quadrante[i].Y] == '#')
            resultado = false;
    }

    return resultado;
}

void EfetueDisparo(Coordenada coordenada)
{
    if(Tabuleiro[coordenada.X][coordenada.Y] == PARTE_DE_NAVIO)
    {
        Tabuleiro[coordenada.X][coordenada.Y] = PARTE_DE_NAVIO_DESTRUIDA;

        if(VerifiqueSeNavioFoiDestruidoCompletamente(coordenada))
            QuantidadeDeNaviosAfundados++;
    }
}


int main()
{
    int numeroDeLinhas, numeroDeColunas;

    cin >> numeroDeLinhas >> numeroDeColunas;

    InicializeTabuleiro(numeroDeLinhas, numeroDeColunas);
    LeiaTabuleiro(numeroDeLinhas, numeroDeColunas);
    
    cin.clear();

    int numeroDeDisparos;
    cin >> numeroDeDisparos;

    QuantidadeDeNaviosAfundados = 0;
    int i = 0;
    while(i < numeroDeDisparos)
    {
        Coordenada coordenadaDisparo;
        cin >> coordenadaDisparo.X >> coordenadaDisparo.Y;
        
        // Ajustando para índice 0
        coordenadaDisparo.X--;
        coordenadaDisparo.Y--;

        EfetueDisparo(coordenadaDisparo);
        i++;
    }

    cout << QuantidadeDeNaviosAfundados;

    return 0;
}