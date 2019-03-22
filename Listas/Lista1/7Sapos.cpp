#include <iostream>

using namespace std;

const int MAXIMO_DE_PEDRAS = 50;
bool rio[MAXIMO_DE_PEDRAS];

int numeroDePedras, numeroDeSapos;

int main(){
	
	cin >> numeroDePedras >> numeroDeSapos;

	for(int i = 1; i <= numeroDeSapos; i++){
		
		// declaro e leio seus valores de P e D
		int posicao, tamanhoDoPulo;
		cin >> posicao >> tamanhoDoPulo;
		
    int inicio = posicao % tamanhoDoPulo;
		for(int i = inicio; i <= numeroDePedras; i += tamanhoDoPulo)
			rio[i] = true;
	}
	
	// depois imprimo os estado de cada pedra
	for(int i = 1; i <= numeroDePedras; i++)
    cout << rio[i] << "\n";
	
	return 0;
}