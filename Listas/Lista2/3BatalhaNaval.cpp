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

vector< vector<char> > Tabuleiro;
int NumeroDeLinhas;
int NumeroDeColunas;

int QuantidadeDeNaviosAfundados;

void InicializeTabuleiro()
{
    Tabuleiro = vector<vector<char> >(NumeroDeLinhas, vector<char>(NumeroDeColunas));
}

void LeiaTabuleiro()
{
	for(int a = 0; a < NumeroDeLinhas; a++)
    {
        for(int j = 0; j < NumeroDeColunas; j++)
        {
            cin >> Tabuleiro[a][j];
        }
    }
}

enum EnumTipoDeOperacao
{
    NORTE,
    SUL,
    LESTE,
    OESTE
};

Coordenada OpereCoordenada(Coordenada coordenada, EnumTipoDeOperacao tipodeOperacao)
{
    Coordenada retorno;
    switch(tipodeOperacao)
    {
        case NORTE:
            retorno.X = coordenada.X;
            retorno.Y = coordenada.Y + 1;
            break;
        case SUL:
            retorno.X = coordenada.X;
            retorno.Y = coordenada.Y - 1;
            break;
        case LESTE:
            retorno.X = coordenada.X + 1;
            retorno.Y = coordenada.Y;
            break;
        case OESTE:
            retorno.X = coordenada.X - 1;
            retorno.Y = coordenada.Y;
            break;
    }

    return retorno;
}

vector<Coordenada> ObtenhaQuadrante(Coordenada coordenada)
{
    // Levar em conta os limites do tabuleiro --> esse é o erro atual
    vector<Coordenada> retorno;

    for(int i = 0; i < 4; i++)
    {
        Coordenada operada = OpereCoordenada(coordenada, (EnumTipoDeOperacao)i);

        if(operada.X != -1 &&
           operada.Y != -1 &&
           operada.X < NumeroDeLinhas &&
           operada.Y < NumeroDeColunas)
        {
            retorno.push_back(operada);
        }
    }

    return retorno;
}

char LeiaCoordenada(Coordenada coordenada)
{
    return Tabuleiro[coordenada.X][coordenada.Y];
}

bool VerifiqueSeCoordenadaJaEstahNoNavio(Coordenada coordenada, vector<Coordenada> navio)
{
    for (int i = 0; i < navio.capacity(); i++)
    {
        if(navio[i].X == coordenada.X && navio[i].Y == coordenada.Y)
            return true;
    }

    return false;
}

bool JaFoiProcessada(vector<Coordenada> processadas, Coordenada coordenada)
{
    for (int i = 0; i < processadas.capacity(); i++)
    {
        if(processadas[i].X == coordenada.X && processadas[i].Y == coordenada.Y)
            return true;
    }

    return false;
}

void PreenchaNavio(vector<Coordenada> navio, Coordenada coordenadaDeUmaParte, vector<Coordenada> processadas)
{
    processadas.push_back(coordenadaDeUmaParte);
    
    if(LeiaCoordenada(coordenadaDeUmaParte) == PARTE_DE_NAVIO || 
       LeiaCoordenada(coordenadaDeUmaParte) == PARTE_DE_NAVIO_DESTRUIDA)
    {
        if(!VerifiqueSeCoordenadaJaEstahNoNavio(coordenadaDeUmaParte, navio))
            navio.push_back(coordenadaDeUmaParte);
    }

    vector<Coordenada> quadrante = ObtenhaQuadrante(coordenadaDeUmaParte);
    for (int i = 0; i < quadrante.capacity() - 1; i++)
    {
        if(JaFoiProcessada(processadas, quadrante[i]))
            continue;
        PreenchaNavio(navio, quadrante[i], processadas);
    }
}

bool VerifiqueSeNavioFoiDestruidoCompletamente(Coordenada coordenada)
{
    vector<Coordenada> navio, processadas;
    PreenchaNavio(navio, coordenada, processadas);

    int contNavio = navio.capacity();

    for(int i = 0; i < contNavio; i++)
    {
        if(Tabuleiro[navio[i].X][navio[i].Y] == AGUA)
            return false;
    }

    return true;
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
    cin >> NumeroDeLinhas >> NumeroDeColunas;

    InicializeTabuleiro();
    LeiaTabuleiro();
    
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

    cout << QuantidadeDeNaviosAfundados << "\n";

    return 0;
}