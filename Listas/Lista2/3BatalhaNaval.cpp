#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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

vector<Coordenada> ObtenhaNavio(Coordenada coordenada)
{
    vector<Coordenada> vetor;
    return vetor;
}

bool VerifiqueSeNavioFoiDestruidoCompletamente(Coordenada coordenada)
{
    vector<Coordenada> navio = ObtenhaNavio(coordenada);

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

// Program to count islands in boolean 2D matrix 
#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 
  
#define ROW 100 
#define COL 100
  
// A function to check if a given cell (row, col) can be included in DFS 
int isSafe(int M[][COL], int row, int col, bool visited[][COL]) 
{ 
    // row number is in range, column number is in range and value is 1  
    // and not yet visited 
    return (row >= 0) && (row < NumeroDeLinhas) &&      
           (col >= 0) && (col < NumeroDeColunas) &&       
           (M[row][col] && !visited[row][col]);  
} 
  
// A utility function to do DFS for a 2D boolean matrix. It only considers 
// the 8 neighbours as adjacent vertices 
// DFS: Depht First Search
void DFS(int M[][COL], int row, int col, bool visited[][COL]) 
{ 
    // These arrays are used to get row and column numbers of 8 neighbours  
    // of a given cell 
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1}; 
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1}; 
  
    // Mark this cell as visited 
    visited[row][col] = true; 
  
    // Recur for all connected neighbours 
    for (int k = 0; k < 8; ++k) 
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) ) 
            DFS(M, row + rowNbr[k], col + colNbr[k], visited); 
} 
  
// The main function that returns count of islands in a given boolean 
// 2D matrix 
int countIslands(int M[][COL]) 
{ 
    // Make a bool array to mark visited cells. 
    // Initially all cells are unvisited 
    bool visited[ROW][COL]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Initialize count as 0 and travese through the all cells of given matrix 
    int count = 0; 
    for (int i = 0; i < NumeroDeLinhas; ++i) 
        for (int j = 0; j < NumeroDeColunas; ++j) 
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not 
            {                              // visited yet, then new island found 
                DFS(M, i, j, visited);     // Visit all cells in this island. 
                ++count;                   // and increment island count 
            } 
  
    return count; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int M[][COL]= 
    {   {1, 1, 0, 0, 0}, 
        {0, 1, 0, 0, 1}, 
        {1, 0, 0, 1, 1}, 
        {0, 0, 0, 0, 0}, 
        {1, 0, 1, 0, 1} 
    };
    NumeroDeLinhas = 5;
    NumeroDeColunas = 5; 
  
    printf("Number of islands is: %d\n", countIslands(M)); 
  
    return 0; 
} 

// int main()
// {
//     cin >> NumeroDeLinhas >> NumeroDeColunas;

//     InicializeTabuleiro();
//     LeiaTabuleiro();
    
//     cin.clear();

//     int numeroDeDisparos;
//     cin >> numeroDeDisparos;

//     QuantidadeDeNaviosAfundados = 0;
//     int i = 0;
//     while(i < numeroDeDisparos)
//     {
//         Coordenada coordenadaDisparo;
//         cin >> coordenadaDisparo.X >> coordenadaDisparo.Y;
        
//         // Ajustando para índice 0
//         coordenadaDisparo.X--;
//         coordenadaDisparo.Y--;

//         EfetueDisparo(coordenadaDisparo);
//         i++;
//     }

//     cout << QuantidadeDeNaviosAfundados << "\n";

//     return 0;
// }

