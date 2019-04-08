#include <iostream>

using namespace std;

const char ORIGEM = 'O';
const char DESTINO = 'D';
const char AUXILIAR = 'A';

void MovaDisco(int disco, char torreDeOrigem, char torreDeDestino, char torreAuxiliar)
{
   if (disco == 1) 
   {
      cout << "(" << torreDeOrigem << "," << torreDeDestino << ")" << "\n";
      return;
   }

   MovaDisco(disco - 1, torreDeOrigem, torreAuxiliar, torreDeDestino);
   
   cout << "(" << torreDeOrigem << "," << torreDeDestino << ")" << "\n";
   
   MovaDisco(disco - 1, torreAuxiliar, torreDeDestino, torreDeOrigem);
};

int main()
{
   int quantidadeDeDiscos;
   cin >> quantidadeDeDiscos;

   MovaDisco(quantidadeDeDiscos, ORIGEM, DESTINO, AUXILIAR);

   return 0;
}